--
-- mkdocs generator for MWSE-lua definitions.
--

local lfs = require("lfs")
local common = require("builders.common")

common.log("Starting build of mkdocs source files...")

-- Recreate meta folder.
local docsSourceFolder = lfs.join(common.pathAutocomplete, "..\\docs\\source")
lfs.remakedir(lfs.join(docsSourceFolder, "apis"))
lfs.remakedir(lfs.join(docsSourceFolder, "types"))
lfs.remakedir(lfs.join(docsSourceFolder, "events"))

-- Base containers to hold our compiled data.
local globals = {}
local classes = {}
local events = {}
local typeLinks = {}

--
-- Utility functions.
--

common.log("Definitions folder: %s", common.pathDefinitions)


--
-- Compile data
--

common.compilePath(lfs.join(common.pathDefinitions, "global"), globals)
common.compilePath(lfs.join(common.pathDefinitions, "namedTypes"), classes, "class")
common.compilePath(lfs.join(common.pathDefinitions, "events", "standard"), events, "event")


--
-- Building
--

---@param packages package[]
---@return package[] packages The provided packages without the deprecated fields.
local function removeDeprecated(packages)
	for i, package in ipairs(packages) do
		if package.deprecated then
			packages[i] = nil
		end
	end
	-- Make sure there are no gaps in the returned array
	return table.values(packages)
end

local function buildParentChain(className)
	local package = assert(classes[className])
	local ret = ""
	if (classes[className]) then
		ret = string.format("[%s](../../types/%s)", className, className)
	else
		ret = className
	end
	if (package.inherits) then
		ret = ret .. ", " .. buildParentChain(package.inherits)
	end
	return ret
end

---@param type string Supports array annotation. For example: "tes3weather[]".
local function getTypeLink(type)
	if typeLinks[type] then
		return typeLinks[type]
	end

	local isArray = type:endswith("[]")
	local valueType = type:match("[%w%.]+")

	if classes[valueType] then
		typeLinks[type] = string.format("[%s](../../types/%s)%s", valueType, valueType, isArray and "[]" or "")
	else
		typeLinks[type] = type
	end

	return typeLinks[type]
end

--- This function converts a union of types to an array. E.g.:<br>
--- "table<integer, tes3ref|tes3mobile>|fun(self: infoGetTextEventData|string): boolean, string|integer" to<br>
--- {<br>
---    "table<integer, tes3ref|tes3mobile>",<br>
---    "fun(self: infoGetTextEventData|string): boolean, string",<br>
---    "integer",<br>
--- }<br>
---@param union string
---@return string[]
local function breakoutUnion(union)
	local types = {}

	while union ~= "" do
		if union:startswith("|") then
			union = union:sub(2, -1)
		end

		local i, _, tableStr = union:find("(table%b<>)([^|]*)")
		if i == 1 then -- A table found, e.g. table<integer, tes3reference|tes3actor>
			table.insert(types, tableStr)
			union = union:sub(tableStr:len() + 1)
			goto continue
		end

		local i, _, functionParams, functionReturns = union:find("(fun%b())([^|]*)")
		if i == 1 then
			local functionStr = functionParams .. functionReturns
			table.insert(types, functionStr)
			union = union:sub(functionStr:len() + 1)
			goto continue
		end

		local type = union:match("[^|]+")
		table.insert(types, type)
		union = union:sub(type:len() + 1)
		::continue::
	end
	return types
end

---@param type string
---@param nested boolean?
---@return string
local function breakoutTypeLinks(type, nested)
	local types = breakoutUnion(type)

	for i, t in ipairs(types) do
		-- Support "table<x, y>" as type, in HTML < and > signs have a special meaning.
		-- Use "&lt;" and "&gt;" instead.
		if t:startswith("table<") then
			local keyType, valueType = t:match("table<(%w+), (.+)>")
			keyType = breakoutTypeLinks(keyType, true)
			valueType = breakoutTypeLinks(valueType, true)

			types[i] = string.format("table&lt;%s, %s&gt;", keyType, valueType)
		elseif t:startswith("fun(") then
			-- Let's take "fun(e: mwseTimerCallbackData, param2): boolean, string"
			-- params: "(e: mwseTimerCallbackData, param2)",
			-- ret: "boolean, string"
			local params, ret = t:match("fun(%b())[:]?[%s]?(.*)")

			-- Handle the parameters
			-- "e: mwseTimerCallbackData, param2"
			params = params:sub(2, -2)
			local p = {}
			for i, paramStr in ipairs(params:split(",")) do
				-- paramStr: "e: mwseTimerCallbackData", " param2"
				paramStr = paramStr:trim()
				-- name: "e", type: "mwseTimerCallbackData" or
				-- name: "param2", type: nil
				local name, type = paramStr:match("([%w]+)[:]?[%s]?(.*)")
				p[i] = ("%s%s"):format(
					name,
					type and (": " .. breakoutTypeLinks(type, true)) or ""
				)
			end
			params = table.concat(p, ", ")

			-- Handle the return values
			if ret then
				local r = {}
				for i, returnStr in ipairs(ret:split(", ")) do
					-- returnStr: "boolean", "string"
					r[i] = breakoutTypeLinks(returnStr, true)
				end
				ret = table.concat(r, ", ")
			end

			types[i] = string.format("fun(%s)%s",
				params or "",
				(ret ~= "") and (": " .. ret) or ""
			)
		else
			types[i] = getTypeLink(t)
		end
	end
	return table.concat(types, nested and "|" or ", ")
end

--- comment
--- @param package table
--- @param field any
--- @param results any
--- @return table
local function getPackageComponentsArray(package, field, results)
	results = results or {}

	local onThis = package[field]
	if (onThis) then
		for _, v in ipairs(table.values(onThis)) do
			if (results[v.key] == nil) then
				results[v.key] = v
			end
		end
	end

	if (package.inherits and classes[package.inherits]) then
		return getPackageComponentsArray(classes[package.inherits], field, results)
	end

	return results
end

local function sortPackagesByKey(A, B)
	return A.key:lower() < B.key:lower()
end

local function writeArgument(file, argument, indent)
	indent = indent or ""

	file:write(string.format("%s* `%s`", indent, argument.name or "unnamed"))

	if (argument.type) then
		file:write(string.format(" (%s)", breakoutTypeLinks(argument.type)))
	end

	local description = common.getDescriptionString(argument, false)
	if (description) then
		file:write(string.format(": %s", description))
	end

	file:write("\n")

	if (argument.tableParams) then
		for _, tableArg in ipairs(argument.tableParams) do
			writeArgument(file, tableArg, "\t" .. indent)
		end
	end
end

local function getArgumentCode(argument)
	if (argument.tableParams) then
		local tableArgs = {}
		for _, arg in ipairs(argument.tableParams) do
			table.insert(tableArgs, string.format("%s = ...", arg.name))
		end
		return string.format("{ %s }", table.concat(tableArgs, ", "))
	end
	return argument.name or "unknown"
end

local writeSubPackage = nil

local operatorToTitle = {
	unm = "Unary minus (`-`)",
	add = "Addition (`+`)",
	sub = "Subtraction (`-`)",
	mul = "Multiplication (`*`)",
	div = "Division (`/`)",
	idiv = "Floor division (`//`)",
	mod = "Modulo (`%`)",
	pow = "Exponentiation (`^`)",
	concat = "Concatenation (`..`)",
	len = "Length (`#`)",
}

local function writeOperatorPackage(file, operator, package)
	file:write(string.format("### %s\n\n", operatorToTitle[operator.key]))

	local notUnary = operator.overloads[1].rightType and true

	if (notUnary) then
		file:write("| Left operand type | Right operand type | Result type | Description |\n")
		file:write("| ----------------- | ------------------ | ----------- | ----------- |\n")
		for _, overload in ipairs(operator.overloads) do
			file:write(string.format("| %s | %s | %s | %s |\n", getTypeLink(package.namespace), getTypeLink(overload.rightType), getTypeLink(overload.resultType), overload.description or ""))
		end
	else
		file:write("| Result type | Description |\n")
		file:write("| ----------- | ----------- |\n")
		for _, overload in ipairs(operator.overloads) do
			file:write(string.format("| %s | %s |\n", getTypeLink(overload.resultType), overload.description or ""))
		end
	end

	file:write("\n")
end

--- This function is used to write out properties, methods, functions, and operators of a package.
---@param file file* The file to write to.
---@param package package The package whose fields that will be written out.
---@param field string The name of the fields to write. Can be "values", "methods", "functions", and "operators"
---@param fieldName string The name of the section for the fields.
---@param writeFunction fun(file: file*, package: package, from: package) The function that write a single package definition.
---@param writeRule boolean If true a horizontal rule will be written before the section.
---@return boolean written True if at least one field was written to file.
local function writeFields(file, package, field, fieldName, writeFunction, writeRule)
	local fields = table.values(getPackageComponentsArray(package, field), sortPackagesByKey)
	fields = removeDeprecated(fields)
	local count = #fields

	if (count > 0) then
		if (writeRule) then
			file:write("***\n\n")
		end
		file:write(string.format("## %s\n\n", fieldName))
		for i, field in ipairs(fields) do
			if (not field.deprecated) then
				writeFunction(file, field, package)
				if (i < count) then
					file:write("***\n\n")
				end
			end
		end
		return true
	end
	return false
end

---@param file file*
---@param package any
local function writePackageDetails(file, package)
	-- Write description.
	file:write(string.format("%s\n\n", common.getDescriptionString(package)))
	if (package.type == "class" and package.inherits) then
		file:write(string.format("This type inherits the following: %s\n", buildParentChain(package.inherits)))
	elseif (package.type == "event") then
		file:write(string.format("```lua\n--- @param e %sEventData\nlocal function %sCallback(e)\nend\nevent.register(tes3.event.%s, %sCallback)\n```\n\n", package.key, package.key, package.key, package.key))
		if (package.filter) then
			file:write(string.format("!!! tip\n\tThis event can be filtered based on the **`%s`** event data.\n\n", package.filter))
		end
		if (package.blockable) then
			file:write("!!! tip\n\tThis event supports blocking by setting `e.block` to `true` or returning `false`. Blocking the event prevents vanilla behavior from happening. For example, blocking an `equip` event prevents the item from being equipped.\n\n")
		end
		file:write("!!! tip\n\tAn event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.\n\n")
	end

	local needsHorizontalRule = false

	-- Write out fields.
	needsHorizontalRule = (
		writeFields(file, package, "values", "Properties", writeSubPackage, needsHorizontalRule)
		or needsHorizontalRule
	)

	-- Write out methods.
	needsHorizontalRule = (
		writeFields(file, package, "methods", "Methods", writeSubPackage, needsHorizontalRule)
		or needsHorizontalRule
	)

	-- Write out functions.
	needsHorizontalRule = (
		writeFields(file, package, "functions", "Functions", writeSubPackage, needsHorizontalRule)
		or needsHorizontalRule
	)

	-- Write out operators.
	needsHorizontalRule = (
		writeFields(file, package, "operators", "Math Operations", writeOperatorPackage, needsHorizontalRule)
		or needsHorizontalRule
	)

	local returns = common.getConsistentReturnValues(package)
	if (package.type == "method" or package.type == "function") then
		file:write(string.format("```lua\n",  package.namespace))
		if (returns) then
			local returnNames = {}
			for i, ret in ipairs(returns) do
				table.insert(returnNames, ret.name or string.format("unnamed%d", i))
			end
			file:write(string.format("local %s = ", table.concat(returnNames, ", ")))
		end
		if (package.parent) then
			if (package.type == "method") then
				file:write(string.format("%s:%s(", "myObject", package.key))
			else
				file:write(string.format("%s.%s(", package.parent.namespace, package.key))
			end
		else
			file:write(string.format("%s(", package.key))
		end
		if (package.arguments) then
			local args = {}
			for _, arg in pairs(package.arguments) do
				table.insert(args, getArgumentCode(arg))
			end
			file:write(table.concat(args, ", "))
		end
		file:write(string.format(")\n```\n\n", package.namespace))
	end

	if (package.arguments) then
		file:write(string.format("**Parameters**:\n\n"))
		for _, argument in ipairs(package.arguments) do
			writeArgument(file, argument, "")
		end
		file:write("\n")
	end

	if (returns) then
		file:write(string.format("**Returns**:\n\n"))
		for _, ret in ipairs(returns) do
			writeArgument(file, ret, "")
		end
		file:write("\n")
	end

	-- Events are more top-level, need to do special handling...
	if (package.type == "event") then
		-- Write out event data.
		if (package.eventData) then
			file:write("## Event Data\n\n")
			local eventDataKeys = table.keys(package.eventData, true)
			for _, key in ipairs(eventDataKeys) do
				local data = package.eventData[key]
				data.name = key
				writeArgument(file, data)
			end
			file:write("\n")
		end
	end

	if (package.examples) then
		local exampleType = "???"
		if (package.type == "event") then
			file:write("## Examples\n\n")
			exampleType = "!!!"
		end

		local exampleKeys = table.keys(package.examples, true)
		for _, name in ipairs(exampleKeys) do
			local example = package.examples[name]
			file:write(string.format("%s example \"Example: %s\"\n\n", exampleType, example.title or name))
			if (example.description) then
				file:write(string.format("\t%s\n\n", string.gsub(example.description, "\n\n", "\n\n\t")))
			end
			file:write(string.format("\t```lua\n"))

			local path = nil
			if (package.type == "class") then
				path = lfs.join(package.folder, package.key, package.key, name .. ".lua")
			else
				path = lfs.join(package.folder, package.key, name .. ".lua")
			end
			for line in io.lines(path) do
				file:write(string.format("\t%s\n", line))
			end
			file:write(string.format("\n\t```\n\n"))
		end
	end
end

local identifierStems = {
	functions = {
		"get", "set", "mod",
		"is", "has", "can",
		"open", "close",
		"add", "remove",
		"enable", "disable",
		"apply", "update",
		"find", "show",
		"create", "delete",
		"test", "toggle",
	},
	classes = {
		"ni", "tes3ui", "tes3",
	}
}

local function writeSearchTerms(file, key, stems)
	-- Hidden search terms, to work around deficiencies in lunr.
	-- Include lower-cased variants of the identifier.
	-- Include lower-cased stemmed variant, unless it is a single character.
	local stemmedKey = nil
	for _, stem in ipairs(stems) do
		if (key:startswith(stem) and key ~= stem) then
			stemmedKey = string.sub(key, 1 + stem:len(), -1):lower()
			break
		end
	end

	file:write("<div class=\"search_terms\" style=\"display: none\">")
	local lowercaseKey = key:lower()
	if (stemmedKey and stemmedKey:len() > 1) then
		file:write(string.format("%s, %s", lowercaseKey, stemmedKey))
	else
		file:write(string.format("%s", lowercaseKey))
	end
	file:write("</div>\n\n")
end

writeSubPackage = function(file, package, from)
	-- Don't document deprecated APIs on the website.
	if (package.deprecated) then
		return
	end

	local key = package.key
	if (from.type == "lib") then
		key = string.format("%s.%s", from.namespace, package.key)
	end

	-- Add title and hidden search terms.
	file:write(string.format("### `%s`\n", key))
	writeSearchTerms(file, package.key, identifierStems.functions)

	writePackageDetails(file, package)
end

local function build(package, outDir)
	-- Load our base package.
	common.log("Building " .. package.type .. ": " .. package.namespace .. " ...")

	-- Get the package.
	local outPath = lfs.join(docsSourceFolder, outDir, package.namespace .. ".md")

	-- Create the file.
	local file = assert(io.open(outPath, "w"))

	-- Add title and hidden search terms. The heading has to be before any other line to be recognized as the title.
	-- This avoids mkdocs using the auto-capitalized filename as the sidebar title.
	file:write(string.format("# %s\n", package.namespace))
	writeSearchTerms(file, package.namespace, identifierStems.classes)

	-- Make it clear this is auto-generated.
	file:write("<!---\n")
	file:write("\tThis file is autogenerated. Do not edit this file manually. Your changes will be ignored.\n")
	file:write("\tMore information: https://github.com/MWSE/MWSE/tree/master/docs\n")
	file:write("-->\n\n")

	-- Warn of deprecated packages.
	if (package.deprecated) then
		file:write("!!! warning\n\tThis API is deprecated. See below for more information about what to use instead.\n\n")
	end

	writePackageDetails(file, package)

	-- Ensure that sub-globals are built.
	if (package.libs) then
		for _, lib in ipairs(package.libs) do
			build(lib, outDir)
		end
	end

	-- Close up shop.
	file:close()
end

for _, package in pairs(globals) do
	build(package, "apis")
end

for _, package in pairs(classes) do
	build(package, "types")
end

for _, package in pairs(events) do
	build(package, "events")
end

--
-- Custom file setup.
--

-- Add our .pages files for retitling directories.
io.createwith(lfs.join(docsSourceFolder, "apis", ".pages"), "title: APIs")

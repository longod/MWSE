return {
	type = "function",
	description = [[Adds a spell to an actor's spell list. If the spell is passive, the effects will be applied.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "reference", type = "tes3reference|tes3mobileActor|string", description = "Who to give the spell to. To manipulate an actor without specifying any particular reference, use `actor` instead." },
			{ name = "actor", type = "tes3actor|string", description = "Who to give the spell to. Providing a base actor can be done before a save has been loaded, but may not correctly update effects for instanced versions of that actor in an active save." },
			{ name = "spell", type = "tes3spell|string", description = "The spell to add." },
		},
	}},
	returns = {
		{ name = "wasAdded", type = "boolean", description = "True if the spell was successfully added. This can be false if the actor's race or birthsign already contains the spell." },
	}
}
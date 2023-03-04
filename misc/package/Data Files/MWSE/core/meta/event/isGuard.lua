-- This file is autogenerated. Do not edit this file manually. Your changes will be ignored.
-- More information: https://github.com/MWSE/MWSE/tree/master/docs

--- @meta
--- The isGuard event triggers whenever the game engine checks if an NPC object is a guard. The guard status can be modified. This alone will not make an NPC behave like a guard, though.
--- @class isGuardEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field isGuard boolean The previously calculated guard status.
--- @field npc tes3npc *Read-only*. The NPC that the guard status is being checked for.

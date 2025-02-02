# mobileActivated
<div class="search_terms" style="display: none">mobileactivated</div>

<!---
	This file is autogenerated. Do not edit this file manually. Your changes will be ignored.
	More information: https://github.com/MWSE/MWSE/tree/master/docs
-->

This event is called when a mobile object is activated. This includes NPCs, creatures and projectiles, but not the player. This may be the first time that a given reference has an associated mobile object attached to it. Typically this happens when a projectile gets fired, a creature gets summoned or when the player transitions from one cell to another, causing actors in newly loaded cells to get activated.

```lua
--- @param e mobileActivatedEventData
local function mobileActivatedCallback(e)
end
event.register(tes3.event.mobileActivated, mobileActivatedCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `mobile` ([tes3mobileObject](../../types/tes3mobileObject)): *Read-only*. The activated mobile object.
* `reference` ([tes3reference](../../types/tes3reference)): *Read-only*. The reference that the mobile object has been activated for.


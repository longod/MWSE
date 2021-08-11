# levelUp

This even is called whenever the player successfully finishes leveling up.

```lua
--- @type e event.levelUp
local function levelUpCallback(e)
end
event.register("levelUp", levelUpCallback)
```

This event can be filtered based on the **`level`** event data.

## Event Data

* `level` (number): The new level obtained.

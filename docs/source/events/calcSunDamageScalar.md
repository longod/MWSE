# calcSunDamageScalar

calcSunDamageScalar is used when calculating the amount of damage to apply for the Sun Damage magic effect.

```lua
--- @type e event.calcSunDamageScalar
local function calcSunDamageScalarCallback(e)
end
event.register("calcSunDamageScalar", calcSunDamageScalarCallback)
```

## Event Data

* `damage` (number): The previously calculated sun damage.

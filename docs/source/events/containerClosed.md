# containerClosed

This event is raised when a container is closed.

```lua
--- @type e event.containerClosed
local function containerClosedCallback(e)
end
event.register("containerClosed", containerClosedCallback)
```

## Event Data

* `reference` ([tes3reference](../../types/tes3reference)): The reference of the container that was closed.

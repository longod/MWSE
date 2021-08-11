# key

The key event fires when a key up or key down input is detected. It is preferred that the keyDown and keyUp events are used instead.

```lua
--- @type e event.key
local function keyCallback(e)
end
event.register("key", keyCallback)
```

This event can be filtered based on the **`keyCode`** event data.

## Event Data

* `keyCode` (number): The scan code of the key that raised the event.
* `pressed` (boolean): True if this is a key down event, false for a key up event.
* `isSuperDown` (number): True if super (Windows key) is held.
* `isAltDown` (number): True if alt  is held.
* `isControlDown` (number): True if control is held.

## Examples

!!! example "Example: Show a Message when Ctrl-Z is Pressed"

	```lua
	function myOnKeyCallback(e)
	    if( e.pressed and e.isControlDown ) then
	        tes3.messageBox({ message = "You pressed Ctrl-Z, but you can't undo all your mistakes." })
	    end
	end
	
	-- Filter by the scan code to get Z key presses only.
	event.register("key", myOnKeyCallback, { filter = tes3.scanCode.z } )

	```

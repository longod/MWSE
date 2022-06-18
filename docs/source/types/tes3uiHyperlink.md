<!---
	This file is autogenerated. Do not edit this file manually. Your changes will be ignored.
	More information: https://github.com/MWSE/MWSE/tree/master/docs
-->

# tes3uiHyperlink

A structure containing properties specific to hyperlinks.

This type inherits the following: [tes3uiWidget](../../types/tes3uiWidget)
## Properties

### `confirm`

If true, a confirmation prompt will be shown before any URLs are opened.

**Returns**:

* `result` (boolean)

***

### `element`

Access back to the element this widget interface is for.

**Returns**:

* `result` ([tes3uiElement](../../types/tes3uiElement))

***

### `url`

The URL to open if the element is clicked.

**Returns**:

* `result` (string)

***

## Methods

### `openURL`

Opens a contained URL. If the `confirm` property is set, a modal prompt will be given to confirm the user wants to open the URL.

```lua
myObject:openURL()
```

***

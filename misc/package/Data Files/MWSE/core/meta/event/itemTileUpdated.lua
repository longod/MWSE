--- @meta

--- This event is fired whenever an inventory item tile is updated, as well as when the tile is created. This can be used to easily manipulate or extend the appearance of inventory tiles.
--- @class itemTileUpdatedEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field element tes3uiElement *Read-only*. The UI element that the tile is displayed on.
--- @field item tes3alchemy|tes3apparatus|tes3armor|tes3book|tes3clothing|tes3ingredient|tes3light|tes3lockpick|tes3misc|tes3probe|tes3repairTool|tes3weapon *Read-only*. The tile's item.
--- @field itemData tesitemData *Read-only*. The tile's item data, if any.
--- @field menu tes3uiElement *Read-only*. The root menu of the tile. This will typically be the MenuInventory, MenuContents, or MenuBarter menus.
--- @field tile tes3inventoryTile *Read-only*. The tile data itself. This typically contains references to all the other event fields, among other tile-specific information.

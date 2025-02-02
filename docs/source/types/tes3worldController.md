# tes3worldController
<div class="search_terms" style="display: none">tes3worldcontroller, worldcontroller</div>

<!---
	This file is autogenerated. Do not edit this file manually. Your changes will be ignored.
	More information: https://github.com/MWSE/MWSE/tree/master/docs
-->

A core game object used for storing world simulation data.

## Properties

### `aiDistanceScale`
<div class="search_terms" style="display: none">aidistancescale</div>

A value in the range [0, 1]. The (relative) maximum distance setting for AI simulation. Corresponds to the AI distance option in the Options menu.

**Returns**:

* `result` (number)

***

### `allMobileActors`
<div class="search_terms" style="display: none">allmobileactors</div>

*Read-only*. The list of all active mobile actors. Mobile actors expire after 72 hours if they have not been in a loaded cell.

**Returns**:

* `result` ([tes3mobileActor](../../types/tes3mobileActor)[])

***

### `armCamera`
<div class="search_terms" style="display: none">armcamera</div>

*Read-only*. The access to the first person arms camera.

**Returns**:

* `result` ([tes3worldControllerRenderCamera](../../types/tes3worldControllerRenderCamera))

***

### `audioController`
<div class="search_terms" style="display: none">audiocontroller</div>

*Read-only*. The audio controller.

**Returns**:

* `result` ([tes3audioController](../../types/tes3audioController))

***

### `blindnessFader`
<div class="search_terms" style="display: none">blindnessfader</div>

*Read-only*. Screen overlay fader for the blind effect.

**Returns**:

* `result` ([tes3fader](../../types/tes3fader))

***

### `characterRenderTarget`
<div class="search_terms" style="display: none">characterrendertarget</div>

*Read-only*. 

**Returns**:

* `result` (tes3worldControllerRenderTarget)

***

### `charGenState`
<div class="search_terms" style="display: none">chargenstate</div>

*Read-only*. The `charGenState` global variable. Indicates progress through character generation. Has a value of `-1` when chargen is complete.

**Returns**:

* `result` ([tes3globalVariable](../../types/tes3globalVariable))

***

### `countMusicTracksBattle`
<div class="search_terms" style="display: none">countmusictracksbattle</div>

*Read-only*. The number of available battle music tracks.

**Returns**:

* `result` (number)

***

### `countMusicTracksExplore`
<div class="search_terms" style="display: none">countmusictracksexplore</div>

*Read-only*. The number of available explore music tracks.

**Returns**:

* `result` (number)

***

### `criticalDamageSound`
<div class="search_terms" style="display: none">criticaldamagesound</div>

The sound played when an actor takes damage from a critical hit. It plays instead of the normal health damage sound.

**Returns**:

* `result` ([tes3sound](../../types/tes3sound))

***

### `cursorOff`
<div class="search_terms" style="display: none">cursoroff</div>

If the target crosshair is disabled. Corresponds to the "Crosshair" option in the Options menu.

**Returns**:

* `result` (boolean)

***

### `day`
<div class="search_terms" style="display: none">day</div>

*Read-only*. The `Day` global variable, indicating the current day. Day numbering starts at `1` for the first day of a month.

**Returns**:

* `result` ([tes3globalVariable](../../types/tes3globalVariable))

***

### `daysPassed`
<div class="search_terms" style="display: none">dayspassed</div>

*Read-only*. The `DaysPassed` global variable, indicating the days passed since the game started for this character.

**Returns**:

* `result` ([tes3globalVariable](../../types/tes3globalVariable))

***

### `deadFloatScale`
<div class="search_terms" style="display: none">deadfloatscale</div>



**Returns**:

* `result` (number)

***

### `defaultLandSound`
<div class="search_terms" style="display: none">defaultlandsound</div>

This it the default sound played when the player lands, after a jump or a fall.

**Returns**:

* `result` ([tes3sound](../../types/tes3sound))

***

### `defaultLandWaterSound`
<div class="search_terms" style="display: none">defaultlandwatersound</div>

This it the default sound played when the player lands in the water, after a jump or a fall.

**Returns**:

* `result` ([tes3sound](../../types/tes3sound))

***

### `deltaTime`
<div class="search_terms" style="display: none">deltatime</div>

The time interval (in seconds) between this frame and the last frame. Useful for calculations that involve movement or damage over a period of time.

**Returns**:

* `result` (number)

***

### `difficulty`
<div class="search_terms" style="display: none">difficulty</div>

A number in the range [-1, 1]. Corresponds to the "Difficulty" option in the Options menu.

**Returns**:

* `result` (number)

***

### `drowningDamageSound`
<div class="search_terms" style="display: none">drowningdamagesound</div>

The sound played when an actor takes health damage while drowning. It plays instead of the normal health damage sound.

**Returns**:

* `result` ([tes3sound](../../types/tes3sound))

***

### `drownSound`
<div class="search_terms" style="display: none">drownsound</div>

The sound played when an actor is losing health by drowning.

**Returns**:

* `result` ([tes3sound](../../types/tes3sound))

***

### `enchantedItemEffect`
<div class="search_terms" style="display: none">enchanteditemeffect</div>

*Read-only*. The animated texture effect that is applied onto equipped enchanted items.

**Returns**:

* `result` ([niTextureEffect](../../types/niTextureEffect))

***

### `enchantedItemEffectCreated`
<div class="search_terms" style="display: none">enchanteditemeffectcreated</div>

*Read-only*. If the enchantedItemEffect is available.

**Returns**:

* `result` (boolean)

***

### `enchantedItemEffectTextures`
<div class="search_terms" style="display: none">enchanteditemeffecttextures</div>

*Read-only*. An array of textures used for the enchanted item effect, 32 elements long.

**Returns**:

* `result` ([niSourceTexture](../../types/niSourceTexture)[])

***

### `flagLevitationDisabled`
<div class="search_terms" style="display: none">flaglevitationdisabled</div>

If levitation is disabled.

**Returns**:

* `result` (boolean)

***

### `flagTeleportingDisabled`
<div class="search_terms" style="display: none">flagteleportingdisabled</div>

If teleporting is disabled.

**Returns**:

* `result` (boolean)

***

### `globalScripts`
<div class="search_terms" style="display: none">globalscripts</div>

*Read-only*. A list of active global scripts.

**Returns**:

* `result` ([tes3globalScript](../../types/tes3globalScript)[])

***

### `handToHandHit2Sound`
<div class="search_terms" style="display: none">handtohandhit2sound</div>

A sound played when a hand to hand attack hits. For each attack, `handToHandHitSound` or `handToHandHitSound2` are randomly chosen.

**Returns**:

* `result` ([tes3sound](../../types/tes3sound))

***

### `handToHandHitSound`
<div class="search_terms" style="display: none">handtohandhitsound</div>

A sound played when a hand to hand attack hits. For each attack, `handToHandHitSound` or `handToHandHitSound2` are randomly chosen.

**Returns**:

* `result` ([tes3sound](../../types/tes3sound))

***

### `healthDamageSound`
<div class="search_terms" style="display: none">healthdamagesound</div>

The sound played when health damage is taken.

**Returns**:

* `result` ([tes3sound](../../types/tes3sound))

***

### `heavyArmorHitSound`
<div class="search_terms" style="display: none">heavyarmorhitsound</div>

The sound played when a heavy armor piece is hit.

**Returns**:

* `result` ([tes3sound](../../types/tes3sound))

***

### `helpDelay`
<div class="search_terms" style="display: none">helpdelay</div>

A number in the range [0, 2]. The delay in seconds before a tooltip appears. Corresponds to the "Menu help delay" option in the Options menu.

**Returns**:

* `result` (number)

***

### `hitFader`
<div class="search_terms" style="display: none">hitfader</div>

*Read-only*. Screen overlay fader that pulses when damage is taken.

**Returns**:

* `result` ([tes3fader](../../types/tes3fader))

***

### `hour`
<div class="search_terms" style="display: none">hour</div>

*Read-only*. The `GameHour` global variable, indicating the time of day.

**Returns**:

* `result` ([tes3globalVariable](../../types/tes3globalVariable))

***

### `hudStyle`
<div class="search_terms" style="display: none">hudstyle</div>

No known effect.

**Returns**:

* `result` (number)

***

### `inputController`
<div class="search_terms" style="display: none">inputcontroller</div>

*Read-only*. The controller responsible for player input.

**Returns**:

* `result` ([tes3inputController](../../types/tes3inputController))

***

### `instance`
<div class="search_terms" style="display: none">instance</div>

*Read-only*. 

**Returns**:

* `result` (HINSTANCE)

***

### `itemRepairSound`
<div class="search_terms" style="display: none">itemrepairsound</div>

The sound played when an item is repaired.

**Returns**:

* `result` ([tes3sound](../../types/tes3sound))

***

### `lastFrameTime`
<div class="search_terms" style="display: none">lastframetime</div>

*Read-only*. The value of `tes3.worldController.systemTime` at the start of the previous frame. Measured in milliseconds since the program was started.

**Returns**:

* `result` (number)

***

### `lightArmorHitSound`
<div class="search_terms" style="display: none">lightarmorhitsound</div>

The sound played when a light armor piece is hit.

**Returns**:

* `result` ([tes3sound](../../types/tes3sound))

***

### `mapController`
<div class="search_terms" style="display: none">mapcontroller</div>

*Read-only*. The controller responsible for the world and local maps.

**Returns**:

* `result` (tes3mapController)

***

### `maxFPS`
<div class="search_terms" style="display: none">maxfps</div>

Maximum framerate target for the engine's FPS limiter.

**Returns**:

* `result` (number)

***

### `mediumArmorHitSound`
<div class="search_terms" style="display: none">mediumarmorhitsound</div>

The sound played when a medium armor piece is hit.

**Returns**:

* `result` ([tes3sound](../../types/tes3sound))

***

### `menuAlpha`
<div class="search_terms" style="display: none">menualpha</div>

A value in the range [0, 1]. The alpha value of the black background of menus. Corresponds to the "Menu transparency" option in the Options menu.

**Returns**:

* `result` (number)

***

### `menuCamera`
<div class="search_terms" style="display: none">menucamera</div>

*Read-only*. The access to the camera used to render menus.

**Returns**:

* `result` ([tes3worldControllerRenderCamera](../../types/tes3worldControllerRenderCamera))

***

### `menuClickSound`
<div class="search_terms" style="display: none">menuclicksound</div>

The sound played when a UI button or other control is clicked.

**Returns**:

* `result` ([tes3sound](../../types/tes3sound))

***

### `menuController`
<div class="search_terms" style="display: none">menucontroller</div>

*Read-only*. The controller responsible for the menu system.

**Returns**:

* `result` ([tes3uiMenuController](../../types/tes3uiMenuController))

***

### `menuSizeSound`
<div class="search_terms" style="display: none">menusizesound</div>

Unused sound. Not used when a menu is resized.

**Returns**:

* `result` ([tes3sound](../../types/tes3sound))

***

### `missSound`
<div class="search_terms" style="display: none">misssound</div>

The sound played when a weapon fails its to-hit check.

**Returns**:

* `result` ([tes3sound](../../types/tes3sound))

***

### `mobManager`
<div class="search_terms" style="display: none">mobmanager</div>

*Read-only*. The manager responsible for mobile objects and collision.

**Returns**:

* `result` ([tes3mobManager](../../types/tes3mobManager))

***

### `month`
<div class="search_terms" style="display: none">month</div>

*Read-only*. The `Month` global variable, indicating the current month. Month numbering starts at `0` for the first month, Morning Star.

**Returns**:

* `result` ([tes3globalVariable](../../types/tes3globalVariable))

***

### `monthsToRespawn`
<div class="search_terms" style="display: none">monthstorespawn</div>

*Read-only*. The `monthsToRespawn` global variable, used by the game to count the time left until containers are respawned. This is decremented at the end of a month (or end of a day with the appropriate MCP option). When it reaches `0`, containers are respawned.

**Returns**:

* `result` ([tes3globalVariable](../../types/tes3globalVariable))

***

### `mouseSensitivityX`
<div class="search_terms" style="display: none">mousesensitivityx</div>

The horizontal camera rotation sensitivity. Corresponds to the "Horizontal sensitivity" option in the Options menu.

**Returns**:

* `result` (number)

***

### `mouseSensitivityY`
<div class="search_terms" style="display: none">mousesensitivityy</div>

The vertical camera rotation sensitivity. Corresponds to the "Vertical sensitivity" option in the Options menu.

**Returns**:

* `result` (number)

***

### `musicSituation`
<div class="search_terms" style="display: none">musicsituation</div>

The kind of music being played. Only updates when music is not muted.
`0` Explore music
`1` Combat music
`2` Main menu music

Note: These values are available as [`tes3.musicSituation`](https://mwse.github.io/MWSE/references/music-situations/) constants

**Returns**:

* `result` (number)

***

### `nodeCursor`
<div class="search_terms" style="display: none">nodecursor</div>

*Read-only*. The scenegraph node for the target crosshair.

**Returns**:

* `result` ([niNode](../../types/niNode))

***

### `parentWindowHandle`
<div class="search_terms" style="display: none">parentwindowhandle</div>

*Read-only*. Handle to the parent window.

**Returns**:

* `result` (HWND)

***

### `projectionDistance`
<div class="search_terms" style="display: none">projectiondistance</div>



**Returns**:

* `result` (number)

***

### `quests`
<div class="search_terms" style="display: none">quests</div>

*Read-only*. A list of all available quest objects.

**Returns**:

* `result` ([tes3quest](../../types/tes3quest)[])

***

### `quickSaveWhenResting`
<div class="search_terms" style="display: none">quicksavewhenresting</div>

Controls if auto-save on resting or waiting is enabled. Corresponds to the "Auto-save when rest" option in the Options menu.

**Returns**:

* `result` (boolean)

***

### `rechargingItems`
<div class="search_terms" style="display: none">rechargingitems</div>

*Read-only*. A list of enchanted items that are recharging. Items in the list may not all belong to the player.

**Returns**:

* `result` ([tes3rechargingItem](../../types/tes3rechargingItem)[])

***

### `shaderWaterReflectTerrain`
<div class="search_terms" style="display: none">shaderwaterreflectterrain</div>

If pixel shader water reflection includes terrain. Not functional with MGE enabled.

**Returns**:

* `result` (boolean)

***

### `shaderWaterReflectUpdate`
<div class="search_terms" style="display: none">shaderwaterreflectupdate</div>

Period between reflection updates for pixel shader water. Not functional with MGE enabled.

**Returns**:

* `result` (number)

***

### `shadowCamera`
<div class="search_terms" style="display: none">shadowcamera</div>

*Read-only*. The access to the camera used for shadows rendering.

**Returns**:

* `result` ([tes3worldControllerRenderCamera](../../types/tes3worldControllerRenderCamera))

***

### `shadows`
<div class="search_terms" style="display: none">shadows</div>

An integer in the range of `0` to `6`. Controls the amount of actor shadows drawn. The maximum value of `6` is loose; it is determined by the "Number of Shadows" INI setting. Corresponds to the "Real-time shadows" option in the Options menu.

**Returns**:

* `result` (integer)

***

### `showSubtitles`
<div class="search_terms" style="display: none">showsubtitles, subtitles</div>

If subtitles are shown. Corresponds to the "Subtitles" option in the Options menu.

**Returns**:

* `result` (boolean)

***

### `simulationTimeScalar`
<div class="search_terms" style="display: none">simulationtimescalar</div>

A scalar used for simulation time. At the start of every frame, the `deltaTime` is multiplied by this value. Doing this here is safer than doing it in another event.

**Returns**:

* `result` (number)

***

### `splashController`
<div class="search_terms" style="display: none">splashcontroller</div>

*Read-only*. Access to the splash controller.

**Returns**:

* `result` ([tes3splashController](../../types/tes3splashController))

***

### `splashscreenCamera`
<div class="search_terms" style="display: none">splashscreencamera</div>

*Read-only*. The access to the camera used to render splashscreens.

**Returns**:

* `result` ([tes3worldControllerRenderCamera](../../types/tes3worldControllerRenderCamera))

***

### `stopGameLoop`
<div class="search_terms" style="display: none">stopgameloop</div>

When true, the game simulation loop will stop. Not normally used, and may have other unknown effects.

**Returns**:

* `result` (boolean)

***

### `sunglareFader`
<div class="search_terms" style="display: none">sunglarefader</div>

*Read-only*. Screen overlay fader for sunglare.

**Returns**:

* `result` ([tes3fader](../../types/tes3fader))

***

### `systemTime`
<div class="search_terms" style="display: none">systemtime</div>

*Read-only*. Time in milliseconds since the program was started.

**Returns**:

* `result` (number)

***

### `timescale`
<div class="search_terms" style="display: none">timescale</div>

*Read-only*. The `timescale` global variable. Used to convert real time to in-game time.

**Returns**:

* `result` ([tes3globalVariable](../../types/tes3globalVariable))

***

### `transitionFader`
<div class="search_terms" style="display: none">transitionfader</div>

*Read-only*. Screen overlay fader for cell transitions.

**Returns**:

* `result` ([tes3fader](../../types/tes3fader))

***

### `useBestAttack`
<div class="search_terms" style="display: none">usebestattack</div>

Automatically choose the best attack direction for attacks. Corresponds to the "Always use best attack" option in the Options menu.

**Returns**:

* `result` (boolean)

***

### `vfxManager`
<div class="search_terms" style="display: none">vfxmanager</div>

*Read-only*. Access to the VFX manager.

**Returns**:

* `result` ([tes3vfxManager](../../types/tes3vfxManager))

***

### `viewHeight`
<div class="search_terms" style="display: none">viewheight</div>

*Read-only*. The height of the UI viewport in pixels. Affected by UI scaling. For screen resolution, use [`tes3.getViewportSize()`](https://mwse.github.io/MWSE/apis/tes3/#tes3getviewportsize).

**Returns**:

* `result` (number)

***

### `viewWidth`
<div class="search_terms" style="display: none">viewwidth</div>

*Read-only*. The width of the UI viewport in pixels. Affected by UI scaling. For screen resolution, use [`tes3.getViewportSize()`](https://mwse.github.io/MWSE/apis/tes3/#tes3getviewportsize).

**Returns**:

* `result` (number)

***

### `weaponSwishSound`
<div class="search_terms" style="display: none">weaponswishsound</div>

The sound played when an attack with a melee weapon is performed. It always plays when a melee attack is released, irrespective of hit or miss.

**Returns**:

* `result` ([tes3sound](../../types/tes3sound))

***

### `weatherController`
<div class="search_terms" style="display: none">weathercontroller</div>

*Read-only*. The weather controller.

**Returns**:

* `result` ([tes3weatherController](../../types/tes3weatherController))

***

### `werewolfFader`
<div class="search_terms" style="display: none">werewolffader</div>

*Read-only*. Screen overlay fader for werewolf vision.

**Returns**:

* `result` ([tes3fader](../../types/tes3fader))

***

### `werewolfFOV`
<div class="search_terms" style="display: none">werewolffov</div>

The camera FOV when the player is a werewolf.

**Returns**:

* `result` (number)

***

### `worldCamera`
<div class="search_terms" style="display: none">worldcamera</div>

*Read-only*. The access to the world camera.

**Returns**:

* `result` ([tes3worldControllerRenderCamera](../../types/tes3worldControllerRenderCamera))

***

### `year`
<div class="search_terms" style="display: none">year</div>

*Read-only*. The `Year` global variable, indicating the current year.

**Returns**:

* `result` ([tes3globalVariable](../../types/tes3globalVariable))

***

## Methods

### `applyEnchantEffect`
<div class="search_terms" style="display: none">applyenchanteffect, enchanteffect</div>

This method applies an enchantment's effects to a scene node.

```lua
local result = myObject:applyEnchantEffect(node, enchantment)
```

**Parameters**:

* `node` ([niNode](../../types/niNode)): A scene node to which to apply the enchantment's effects.
* `enchantment` ([tes3enchantment](../../types/tes3enchantment)): The enchantment's effects to apply.

**Returns**:

* `result` (boolean)


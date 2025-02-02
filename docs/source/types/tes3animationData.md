# tes3animationData
<div class="search_terms" style="display: none">tes3animationdata, animationdata</div>

<!---
	This file is autogenerated. Do not edit this file manually. Your changes will be ignored.
	More information: https://github.com/MWSE/MWSE/tree/master/docs
-->

A game object which contains information on actor's animations.

Animations are divided into three layers. The layer 0 is the base layer containing all the base animations for every humanoid in the game, including the player (when in third person). These animations come from `base_anim.nif`. Layer 1 is for female animations. Any animations present in `base_anim_female.nif` override their male counterparts for humanoid races. For beast races, layer 1 animations come from `base_anim_kna.nif`. Layer 2 are the custom animations assigned to the actor.

## Properties

### `actorNode`
<div class="search_terms" style="display: none">actornode</div>



**Returns**:

* `result` ([niNode](../../types/niNode))

***

### `animationGroups`
<div class="search_terms" style="display: none">animationgroups</div>

*Read-only*. The animation groups, indexed by the [`tes3.animationGroup`](https://mwse.github.io/MWSE/references/animation-groups/) namespace.

**Returns**:

* `result` (tes3animationGroup[])

***

### `animationGroupSoundgenCounts`
<div class="search_terms" style="display: none">animationgroupsoundgencounts</div>

*Read-only*. The number of sound generators for each of the animation groups, indexed by the [`tes3.animationGroup`](https://mwse.github.io/MWSE/references/animation-groups/) namespace.

**Returns**:

* `result` (number[])

***

### `animGroupLayerIndicies`
<div class="search_terms" style="display: none">animgrouplayerindicies</div>

*Read-only*. The layer from which each of the actor's animation groups come, indexed by the [`tes3.animationGroup`](https://mwse.github.io/MWSE/references/animation-groups/) namespace.

**Returns**:

* `result` (number[])

***

### `approxRootTravelSpeeds`
<div class="search_terms" style="display: none">approxroottravelspeeds</div>

*Read-only*. The approximate root node travel speed for each of the animation groups, indexed by the [`tes3.animationGroup`](https://mwse.github.io/MWSE/references/animation-groups/) namespace.

**Returns**:

* `result` (number[])

***

### `blinkMorphEndTime`
<div class="search_terms" style="display: none">blinkmorphendtime</div>

Blink animation end time for `headMorphTiming`. Timing is specific to the current head model.

**Returns**:

* `result` (number)

***

### `blinkMorphStartTime`
<div class="search_terms" style="display: none">blinkmorphstarttime</div>

Blink animation start time for `headMorphTiming`. Timing is specific to the current head model.

**Returns**:

* `result` (number)

***

### `castSpeed`
<div class="search_terms" style="display: none">castspeed</div>

The animation speed multiplier for the spell casting animation. This is a feature added by MWSE.

It functions slightly differently to the other animation speed multipliers. It is not reset by the AI like the movement and weapon speeds. Therefore, it can be set before a spell is cast, as well as during casting. The speed will affect all further casting by the actor.

**Returns**:

* `result` (number)

***

### `currentAnimGroupLayers`
<div class="search_terms" style="display: none">currentanimgrouplayers</div>

*Read-only*. 

**Returns**:

* `result` (number[])

***

### `currentAnimGroups`
<div class="search_terms" style="display: none">currentanimgroups</div>

*Read-only*. The currently playing [animation group](https://mwse.github.io/MWSE/references/animation-groups/), on each of the [body sections](https://mwse.github.io/MWSE/references/animation-body-sections/).

**Returns**:

* `result` (number[])

***

### `currentNodeIndices`
<div class="search_terms" style="display: none">currentnodeindices</div>

*Read-only*. 

**Returns**:

* `result` (number[])

***

### `currentSoundgenIndices`
<div class="search_terms" style="display: none">currentsoundgenindices</div>

*Read-only*. The index of the currently used sound generator for each of the [body sections](https://mwse.github.io/MWSE/references/animation-body-sections/).

**Returns**:

* `result` (number[])

***

### `deltaTime`
<div class="search_terms" style="display: none">deltatime</div>

The time in seconds since the last update.

**Returns**:

* `result` (number)

***

### `flags`
<div class="search_terms" style="display: none">flags</div>



**Returns**:

* `result` (number)

***

### `hasOverrideAnimations`
<div class="search_terms" style="display: none">hasoverrideanimations, overrideanimations</div>

*Read-only*. 

**Returns**:

* `result` (boolean)

***

### `headGeometry`
<div class="search_terms" style="display: none">headgeometry</div>



**Returns**:

* `result` ([niGeometry](../../types/niGeometry))

***

### `headMorphTiming`
<div class="search_terms" style="display: none">headmorphtiming</div>

The timing offset of the head morph controller. Used to select either blinking or lipsync animations. Actively updated by the animation system during blinking or voiceovers. Timing is specific to the current head model.

**Returns**:

* `result` (number)

***

### `headNode`
<div class="search_terms" style="display: none">headnode</div>



**Returns**:

* `result` ([niNode](../../types/niNode))

***

### `keyframeLayers`
<div class="search_terms" style="display: none">keyframelayers</div>

*Read-only*. 

**Returns**:

* `result` ([tes3animationDataSequenceGroup](../../types/tes3animationDataSequenceGroup)[])

***

### `lipsyncLevel`
<div class="search_terms" style="display: none">lipsynclevel</div>

This value indicates whether the NPC is speaking or not. The table below describes the relationship.

Value      | Behavior
---------- | ---------
      -1   | The NPC isn't speaking.
 0.0 - 1.0 | The NPC is speaking. The `lipsyncLevel` can be `0.0` when there is a silent part in the sound file the NPC is currently speaking.


**Returns**:

* `result` (number)

??? example "Example: isSpeaking"

	Check if the NPC is speaking

	```lua
	--- Returns true if the actor is currently speaking a voiceover line.
	---@param mobile tes3mobileActor
	---@return boolean isSpeaking
	local function isSpeaking(mobile)
		local ad = mobile.animationController.animationData
		return (ad.lipsyncLevel ~= -1)
	end

	```

***

### `loopCounts`
<div class="search_terms" style="display: none">loopcounts</div>

*Read-only*. 

**Returns**:

* `result` (number[])

***

### `manager`
<div class="search_terms" style="display: none">manager</div>



**Returns**:

* `result` (niKeyframeManager)

***

### `modelRootNode`
<div class="search_terms" style="display: none">modelrootnode, elrootnode</div>



**Returns**:

* `result` ([niNode](../../types/niNode))

***

### `movementSpeed`
<div class="search_terms" style="display: none">movementspeed</div>

*Read-only*. The animation speed multiplier of movement animations. This includes walking, running, crouching, swimming, turning, jumping and other movement related animations.

**Returns**:

* `result` (number)

***

### `nextLoopCounts`
<div class="search_terms" style="display: none">nextloopcounts</div>



**Returns**:

* `result` (number)

***

### `positionDeltaModelRoot`
<div class="search_terms" style="display: none">positiondeltamodelroot</div>



**Returns**:

* `result` ([tes3vector3](../../types/tes3vector3))

***

### `spine1Node`
<div class="search_terms" style="display: none">spine1node</div>



**Returns**:

* `result` ([niNode](../../types/niNode))

***

### `spine2Node`
<div class="search_terms" style="display: none">spine2node</div>



**Returns**:

* `result` ([niNode](../../types/niNode))

***

### `spineAngle`
<div class="search_terms" style="display: none">spineangle</div>



**Returns**:

* `result` (number)

***

### `talkMorphEndTime`
<div class="search_terms" style="display: none">talkmorphendtime</div>

Lipsync animation end time for `headMorphTiming`. Timing is specific to the current head model.

**Returns**:

* `result` (number)

***

### `talkMorphStartTime`
<div class="search_terms" style="display: none">talkmorphstarttime</div>

Lipsync animation start time for `headMorphTiming`. Timing is specific to the current head model.

**Returns**:

* `result` (number)

***

### `timeToNextBlink`
<div class="search_terms" style="display: none">timetonextblink</div>

The time in seconds until the next blink. It is fixed at 0 while the blink animation plays.

**Returns**:

* `result` (number)

***

### `timings`
<div class="search_terms" style="display: none">timings</div>

The time in seconds indicating the current position within the animation for each individual body section, indexed by values in the [`tes3.animationBodySection`](https://mwse.github.io/MWSE/references/animation-body-sections/) table.

**Returns**:

* `result` (number[])

***

### `weaponSpeed`
<div class="search_terms" style="display: none">weaponspeed</div>

The animation speed multiplier of weapon animations. This includes all weapon related idle, attack, and ready/unready animations.

**Returns**:

* `result` (number)

***

## Methods

### `getReference`
<div class="search_terms" style="display: none">getreference, reference</div>

This method fetches the reference of the actor to whom this animation data belongs.

```lua
local result = myObject:getReference()
```

**Returns**:

* `result` ([tes3reference](../../types/tes3reference))

***

### `playAnimationGroup`
<div class="search_terms" style="display: none">playanimationgroup</div>

This method plays an animation group on the related actor, invoking `playGroup` event.

```lua
myObject:playAnimationGroup(animationGroup, startFlag, loopCount)
```

**Parameters**:

* `animationGroup` (number): The animation group to play. A value from [`tes3.animationGroup`](https://mwse.github.io/MWSE/references/animation-groups/) namespace.
* `startFlag` (number): A flag for starting the group with, using [`tes3.animationStartFlag`](https://mwse.github.io/MWSE/references/animation-start-flags/) constants.
* `loopCount` (number): If provided, the animation will repeat its loop section a given number of times. To make an animation play through once, set loopCount = 0, while -1 is used for infinite looping.

***

### `playAnimationGroupForIndex`
<div class="search_terms" style="display: none">playanimationgroupforindex</div>

This method plays an animation group on the provided body section of related actor, invoking `playGroup` event.

```lua
myObject:playAnimationGroupForIndex(animationGroup, triIndex, startFlag, loopCount)
```

**Parameters**:

* `animationGroup` (number): The animation group to play. A value from [`tes3.animationGroup`](https://mwse.github.io/MWSE/references/animation-groups/) namespace.
* `triIndex` (number): The body section on which to play the animation. A value from [`tes3.animationBodySection`](https://mwse.github.io/MWSE/references/animation-body-sections/) namespace.
* `startFlag` (number): A flag for starting the group with, using [`tes3.animationStartFlag`](https://mwse.github.io/MWSE/references/animation-start-flags/) constants.
* `loopCount` (number): If provided, the animation will repeat its loop section a given number of times. To make an animation play through once, set loopCount = 0, while -1 is used for infinite looping.

***

### `setHeadNode`
<div class="search_terms" style="display: none">setheadnode, headnode</div>



```lua
myObject:setHeadNode(head)
```

**Parameters**:

* `head` ([niNode](../../types/niNode)): 

***

### `setOverrideLayerKeyframes`
<div class="search_terms" style="display: none">setoverridelayerkeyframes, overridelayerkeyframes</div>



```lua
local success = myObject:setOverrideLayerKeyframes(kfData)
```

**Parameters**:

* `kfData` (tes3keyframeDefinition): 

**Returns**:

* `success` (boolean)


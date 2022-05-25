#include "LuaUtil.h"
#include "LuaManager.h"

#include "LuaEquipEvent.h"

#include "Stack.h"

#include "ScriptUtil.h"
#include "ScriptUtilLua.h"

#include "TES3Creature.h"
#include "TES3Dialogue.h"
#include "TES3LeveledList.h"
#include "TES3Misc.h"
#include "TES3Reference.h"
#include "TES3Script.h"
#include "TES3Spell.h"
#include "TES3WorldController.h"

#include "BitUtil.h"
#include "InstructionStore.h"

namespace mwse::lua {
	void bindScriptUtil() {
		auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
		auto& state = stateHandle.state;

		//
		// Get context on the current execution.
		//

		state["mwscript"]["getScript"] = []() {
			return LuaManager::getInstance().getCurrentScript();
		};

		state["mwscript"]["getReference"] = []() {
			return LuaManager::getInstance().getCurrentReference();
		};

		//
		// Expose base game opcodes.
		//

		state["mwscript"]["activate"] = [](sol::optional<sol::table> params) {
			auto script = getOptionalParamExecutionScript(params);
			auto reference = getOptionalParamExecutionReference(params);

			mwscript::Activate(script, reference);
		};
		state["mwscript"]["addItem"] = [](sol::optional<sol::table> params) {
			auto script = getOptionalParamExecutionScript(params);
			auto reference = getOptionalParamExecutionReference(params);
			auto item = getOptionalParamObject<TES3::Item>(params, "item");
			auto count = getOptionalParam(params, "count", 1);
			if (item == nullptr || count <= 0) {
				return false;
			}

			mwscript::AddItem(script, reference, item, count);
			reference->setObjectModified(true);
			reference->baseObject->setObjectModified(true);
			return true;
		};
		state["mwscript"]["addSoulGem"] = [](sol::optional<sol::table> params) {
			auto script = getOptionalParamExecutionScript(params);
			auto reference = getOptionalParamExecutionReference(params);
			auto creature = getOptionalParamObject<TES3::Creature>(params, "creature");
			auto soulGem = getOptionalParamObject<TES3::Misc>(params, "soulgem");
			if (creature == nullptr || soulGem == nullptr) {
				return false;
			}

			mwscript::AddSoulGem(script, reference, creature, soulGem);
			return true;
		};
		state["mwscript"]["addToLevCreature"] = [](sol::optional<sol::table> params) {
			auto script = getOptionalParamExecutionScript(params);
			auto reference = getOptionalParamExecutionReference(params);
			auto list = getOptionalParamObject<TES3::LeveledCreature>(params, "list");
			auto actor = getOptionalParamObject<TES3::Actor>(params, "creature");
			auto level = getOptionalParam<unsigned short>(params, "level", 0);
			if (list == nullptr || actor == nullptr || level == 0) {
				return false;
			}

			mwscript::AddToLevCreature(script, reference, list, actor, level);
			return true;
		};
		state["mwscript"]["addSpell"] = [](sol::optional<sol::table> params) {
			auto script = getOptionalParamExecutionScript(params);
			auto reference = getOptionalParamExecutionReference(params);
			auto spell = getOptionalParamSpell(params, "spell");
			if (spell == nullptr) {
				return false;
			}

			mwscript::AddSpell(script, reference, spell);
			return true;
		};
		state["mwscript"]["addToLevItem"] = [](sol::optional<sol::table> params) {
			auto script = getOptionalParamExecutionScript(params);
			auto reference = getOptionalParamExecutionReference(params);
			auto list = getOptionalParamObject<TES3::BaseObject>(params, "list");
			auto item = getOptionalParamObject<TES3::Item>(params, "item");
			auto level = getOptionalParam<unsigned short>(params, "level", 0);
			if (list == nullptr || item == nullptr || level == 0) {
				return false;
			}

			mwscript::AddToLevItem(script, reference, list, item, level);
			return true;
		};
		state["mwscript"]["addTopic"] = [](sol::optional<sol::table> params) {
			auto script = getOptionalParamExecutionScript(params);
			auto reference = getOptionalParamExecutionReference(params);
			auto topic = getOptionalParamDialogue(params, "topic");
			if (topic == nullptr || topic->type != TES3::DialogueType::Topic) {
				return false;
			}

			mwscript::AddTopic(script, reference, topic);
			return true;
		};
		state["mwscript"]["aiTravel"] = [](sol::optional<sol::table> params) {
			auto script = getOptionalParamExecutionScript(params);
			auto reference = getOptionalParamExecutionReference(params);
			auto x = getOptionalParam(params, "x", 0.0f);
			auto y = getOptionalParam(params, "y", 0.0f);
			auto z = getOptionalParam(params, "z", 0.0f);

			mwscript::AITravel(script, reference, x, y, z);
			return true;
		};
		state["mwscript"]["disable"] = [](sol::optional<sol::table> params) {
			auto script = getOptionalParamExecutionScript(params);
			auto reference = getOptionalParamExecutionReference(params);
			auto setModified = getOptionalParam(params, "modify", true);

			if (setModified) {
				reference->setObjectModified(true);
			}

			mwscript::Disable(script, reference);
			return true;
		};
		state["mwscript"]["drop"] = [](sol::optional<sol::table> params) {
			auto script = getOptionalParamExecutionScript(params);
			auto reference = getOptionalParamExecutionReference(params);
			auto item = getOptionalParamObject<TES3::Item>(params, "item");
			auto count = getOptionalParam(params, "count", 1);
			if (item == nullptr || count <= 0) {
				return false;
			}

			mwscript::Drop(script, reference, item, count);
			return true;
		};
		state["mwscript"]["enable"] = [](sol::optional<sol::table> params) {
			auto script = getOptionalParamExecutionScript(params);
			auto reference = getOptionalParamExecutionReference(params);
			auto setModified = getOptionalParam(params, "modify", true);

			if (reference == nullptr) {
				return false;
			}

			if (setModified) {
				reference->setObjectModified(true);
			}

			mwscript::Enable(script, reference);
			return true;
		};
		state["mwscript"]["equip"] = [](sol::optional<sol::table> params) {
			auto script = getOptionalParamExecutionScript(params);
			auto reference = getOptionalParamExecutionReference(params);
			auto item = getOptionalParamObject<TES3::Item>(params, "item");
			if (item == nullptr || reference == nullptr) {
				return false;
			}

			// Fire off the event, because script calls don't hit the same code as our hooks.
			if (event::EquipEvent::getEventEnabled()) {
				auto& luaManager = mwse::lua::LuaManager::getInstance();
				auto stateHandle = luaManager.getThreadSafeStateHandle();
				sol::object response = stateHandle.triggerEvent(new event::EquipEvent(reference, item, nullptr));
				if (response.get_type() == sol::type::table) {
					sol::table eventData = response;
					if (eventData.get_or("block", false)) {
						return false;
					}
				}
			}

			mwscript::Equip(script, reference, item);
			return true;
		};
		state["mwscript"]["explodeSpell"] = [](sol::optional<sol::table> params) {
			auto script = getOptionalParamExecutionScript(params);
			auto reference = getOptionalParamExecutionReference(params);
			auto spell = getOptionalParamSpell(params, "spell");
			if (spell == nullptr) {
				return false;
			}

			mwscript::ExplodeSpell(script, reference, spell);
			return true;
		};
		state["mwscript"]["getButtonPressed"] = [](sol::optional<sol::table> params) {
			auto script = getOptionalParamExecutionScript(params);
			auto reference = getOptionalParamExecutionReference(params);

			return mwscript::GetButtonPressed(script, reference);
		};
		state["mwscript"]["hasItemEquipped"] = [](sol::optional<sol::table> params) {
			auto script = getOptionalParamExecutionScript(params);
			auto reference = getOptionalParamExecutionReference(params);
			auto item = getOptionalParamObject<TES3::Item>(params, "item");
			if (item == nullptr) {
				return false;
			}

			return mwscript::HasItemEquipped(script, reference, item);
		};
		// Obsolete. Do not document.
		state["mwscript"]["getDelete"] = [](sol::optional<sol::table> params) {
			auto script = getOptionalParamExecutionScript(params);
			auto reference = getOptionalParamExecutionReference(params);

			return BITMASK_TEST(reference->objectFlags, TES3::ObjectFlag::Delete);
		};
		state["mwscript"]["getDetected"] = [](sol::optional<sol::table> params) {
			auto script = getOptionalParamExecutionScript(params);
			auto reference = getOptionalParamExecutionReference(params);
			auto target = getOptionalParamReference(params, "target");
			if (reference == nullptr || target == nullptr) {
				return false;
			}

			return mwscript::GetDetected(script, reference, target);
		};
		state["mwscript"]["getDisabled"] = [](sol::optional<sol::table> params) {
			auto script = getOptionalParamExecutionScript(params);
			auto reference = getOptionalParamExecutionReference(params);
			return mwscript::GetDisabled(script, reference);
		};
		state["mwscript"]["getDistance"] = [](sol::optional<sol::table> params) {
			auto script = getOptionalParamExecutionScript(params);
			auto reference = getOptionalParamExecutionReference(params);
			auto target = getOptionalParamReference(params, "target");
			if (reference == nullptr || target == nullptr) {
				return -1.0f;
			}

			return mwscript::GetDistance(script, reference, target);
		};
		state["mwscript"]["getItemCount"] = [](sol::optional<sol::table> params) -> int {
			auto script = getOptionalParamExecutionScript(params);
			auto reference = getOptionalParamExecutionReference(params);
			auto item = getOptionalParamObject<TES3::Item>(params, "item");
			if (item == nullptr) {
				return 0;
			}

			return mwscript::GetItemCount(script, reference, item);
		};
		state["mwscript"]["getPCJumping"] = [](sol::optional<sol::table> params) {
			auto script = getOptionalParamExecutionScript(params);
			return mwscript::GetPCJumping(script);
		};
		state["mwscript"]["getPCRunning"] = [](sol::optional<sol::table> params) {
			auto script = getOptionalParamExecutionScript(params);
			return mwscript::GetPCRunning(script);
		};
		state["mwscript"]["getPCSneaking"] = [](sol::optional<sol::table> params) {
			auto script = getOptionalParamExecutionScript(params);
			return mwscript::GetPCSneaking(script);
		};
		state["mwscript"]["getSpellEffects"] = [](sol::optional<sol::table> params) {
			auto script = getOptionalParamExecutionScript(params);
			auto reference = getOptionalParamExecutionReference(params);
			auto spell = getOptionalParamSpell(params, "spell");
			if (spell == nullptr) {
				return false;
			}

			return mwscript::GetSpellEffects(script, reference, spell);
		};
		// Obsolete. Do not document.
		state["mwscript"]["onActivate"] = [](sol::optional<sol::table> params) {
			auto script = getOptionalParamExecutionScript(params);
			auto reference = getOptionalParamExecutionReference(params);

			auto result = reference->testActionFlag(TES3::ActionFlags::OnActivate);
			reference->clearActionFlag(TES3::ActionFlags::UseEnabled);
			reference->clearActionFlag(TES3::ActionFlags::OnActivate);
			return result;
		};
		// Obsolete. Do not document.
		state["mwscript"]["onDeath"] = [](sol::optional<sol::table> params) {
			auto reference = getOptionalParamExecutionReference(params);

			auto result = reference->testActionFlag(TES3::ActionFlags::OnDeath);
			reference->clearActionFlag(TES3::ActionFlags::OnDeath);
			return result;
		};
		// Obsolete. Do not document.
		state["mwscript"]["onKnockout"] = [](sol::optional<sol::table> params) {
			auto reference = getOptionalParamExecutionReference(params);

			auto result = reference->testActionFlag(TES3::ActionFlags::OnKnockout);
			reference->clearActionFlag(TES3::ActionFlags::OnKnockout);
			return result;
		};
		// Obsolete. Do not document.
		state["mwscript"]["onMurder"] = [](sol::optional<sol::table> params) {
			auto reference = getOptionalParamExecutionReference(params);

			auto result = reference->testActionFlag(TES3::ActionFlags::OnMurder);
			reference->clearActionFlag(TES3::ActionFlags::OnMurder);
			return result;
		};
		state["mwscript"]["placeAtPC"] = [](sol::optional<sol::table> params) -> TES3::Reference* {
			auto script = getOptionalParamExecutionScript(params);
			auto reference = getOptionalParamExecutionReference(params);
			auto object = getOptionalParamObject<TES3::BaseObject>(params, "object");
			auto count = getOptionalParam(params, "count", 1);
			auto distance = getOptionalParam(params, "distance", 256.0f);
			auto direction = getOptionalParam(params, "direction", 1.0f);
			if (object == nullptr) {
				return nullptr;
			}

			mwscript::PlaceAtPC(script, reference, object, count, distance, direction);
			return mwscript::lastCreatedPlaceAtPCReference;
		};
		state["mwscript"]["playSound"] = [](sol::optional<sol::table> params) {
			auto script = getOptionalParamExecutionScript(params);
			auto reference = getOptionalParamExecutionReference(params);
			auto sound = getOptionalParamSound(params, "sound");
			if (sound == nullptr) {
				return false;
			}

			mwscript::PlaySound(script, reference, sound);
			return true;
		};
		state["mwscript"]["position"] = [](sol::optional<sol::table> params) {
			auto script = getOptionalParamExecutionScript(params);
			auto reference = getOptionalParamExecutionReference(params);
			auto x = getOptionalParam(params, "x", 0.0f);
			auto y = getOptionalParam(params, "y", 0.0f);
			auto z = getOptionalParam(params, "z", 0.0f);
			auto rotation = getOptionalParam(params, "rotation", 0.0f);

			mwscript::Position(script, reference, x, y, z, rotation);
			return true;
		};
		state["mwscript"]["positionCell"] = [](sol::optional<sol::table> params) {
			auto script = getOptionalParamExecutionScript(params);
			auto reference = getOptionalParamExecutionReference(params);
			auto x = getOptionalParam(params, "x", 0.0f);
			auto y = getOptionalParam(params, "y", 0.0f);
			auto z = getOptionalParam(params, "z", 0.0f);
			auto rotation = getOptionalParam(params, "rotation", 0.0f);
			auto cell = getOptionalParam<std::string>(params, "cell", "");
			if (cell.empty()) {
				return false;
			}

			mwscript::PositionCell(script, reference, x, y, z, rotation, cell.c_str());
			return true;
		};
		state["mwscript"]["removeItem"] = [](sol::optional<sol::table> params) {
			auto script = getOptionalParamExecutionScript(params);
			auto reference = getOptionalParamExecutionReference(params);
			auto item = getOptionalParamObject<TES3::Item>(params, "item");
			auto count = getOptionalParam(params, "count", 1);
			if (item == nullptr) {
				return false;
			}

			mwscript::RemoveItem(script, reference, item, count);
			reference->setObjectModified(true);
			reference->baseObject->setObjectModified(true);
			return true;
		};
		state["mwscript"]["removeSpell"] = [](sol::optional<sol::table> params) {
			auto script = getOptionalParamExecutionScript(params);
			auto reference = getOptionalParamExecutionReference(params);
			auto spell = getOptionalParamSpell(params, "spell");
			if (spell == nullptr) {
				return false;
			}

			mwscript::RemoveSpell(script, reference, spell);
			return true;
		};
		state["mwscript"]["scriptRunning"] = [](sol::optional<sol::table> params) {
			auto script = getOptionalParamExecutionScript(params);
			auto targetScript = getOptionalParamScript(params, "script");
			if (targetScript == nullptr) {
				return false;
			}

			return TES3::WorldController::get()->isGlobalScriptRunning(targetScript);
		};
		// Obsolete. Do not document.
		state["mwscript"]["setDelete"] = [](sol::optional<sol::table> params) {
			auto script = getOptionalParamExecutionScript(params);
			auto reference = getOptionalParamExecutionReference(params);

			reference->setDeleted(getOptionalParam(params, "delete", true));
			reference->setObjectModified(true);

			return true;
		};
		state["mwscript"]["setLevel"] = [](sol::optional<sol::table> params) {
			auto script = getOptionalParamExecutionScript(params);
			auto reference = getOptionalParamExecutionReference(params);
			auto level = getOptionalParam<short>(params, "level", 0);
			if (level <= 0) {
				return false;
			}

			mwscript::SetLevel(script, reference, level);
			return true;
		};
		state["mwscript"]["startCombat"] = [](sol::optional<sol::table> params) {
			auto script = getOptionalParamExecutionScript(params);
			auto reference = getOptionalParamExecutionReference(params);
			auto target = getOptionalParamReference(params, "target");
			if (target == nullptr) {
				return false;
			}

			mwscript::StartCombat(script, reference, target);
			return true;
		};
		state["mwscript"]["startScript"] = [](sol::optional<sol::table> params) {
			auto script = getOptionalParamExecutionScript(params);
			auto reference = getOptionalParamExecutionReference(params);
			auto targetScript = getOptionalParamScript(params, "script");
			if (targetScript == nullptr) {
				return false;
			}

			TES3::WorldController::get()->startGlobalScript(targetScript, reference);
			return true;
		};
		state["mwscript"]["stopCombat"] = [](sol::optional<sol::table> params) {
			auto script = getOptionalParamExecutionScript(params);
			auto reference = getOptionalParamExecutionReference(params);
			if (reference == nullptr) {
				return false;
			}

			mwscript::StopCombat(script, reference);
			return true;
		};
		state["mwscript"]["stopScript"] = [](sol::optional<sol::table> params) {
			auto script = getOptionalParamExecutionScript(params);
			auto reference = getOptionalParamExecutionReference(params);
			auto targetScript = getOptionalParamScript(params, "script");
			if (targetScript == nullptr) {
				targetScript = script;
			}

			if (targetScript) {
				TES3::WorldController::get()->stopGlobalScript(targetScript);
				return true;
			}

			return false;
		};
		state["mwscript"]["stopSound"] = [](sol::optional<sol::table> params) {
			auto script = getOptionalParamExecutionScript(params);
			auto reference = getOptionalParamExecutionReference(params);
			auto sound = getOptionalParamSound(params, "sound");
			if (sound == nullptr) {
				return false;
			}

			mwscript::StopSound(script, reference, sound);
			return true;
		};
		state["mwscript"]["wakeUpPC"] = []() {
			mwscript::RunOriginalOpCode(nullptr, nullptr, OpCode::WakeUpPC);
		};
	}
}

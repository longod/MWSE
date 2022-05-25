#include "LuaPreventRestEvent.h"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "TES3MobileActor.h"
#include "TES3Reference.h"

namespace mwse::lua::event {
	PreventRestEvent::PreventRestEvent(TES3::MobileActor* mobile) :
		ObjectFilteredEvent("preventRest", mobile->reference->getBaseObject()),
		m_Mobile(mobile)
	{

	}

	sol::table PreventRestEvent::createEventTable() {
		auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
		auto& state = stateHandle.state;
		auto eventData = state.create_table();

		eventData["mobile"] = m_Mobile;
		eventData["reference"] = m_Mobile->reference;

		return eventData;
	}

	bool PreventRestEvent::m_EventEnabled = false;
}

#pragma once

#include <unordered_map>

#include "sol.hpp"

#include "LuaScript.h"

namespace mwse {
	namespace lua {
		class LuaManager {
		public:
			// Returns an instance to the singleton.
			static LuaManager& getInstance() {
				return singleton;
			};

			// Returns a reference to the sol2 lua state.
			sol::state& __fastcall getState() {
				return luaState;
			}

			// 
			void hook();
			void cleanup();

		private:
			LuaManager();

			//
			void bindData();

			// 
			static LuaManager singleton;

			// 
			sol::state luaState;

			// 
			bool hooked = false;
		};
	}
}

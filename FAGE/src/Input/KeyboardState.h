#pragma once
#include "Keyboard.h"

namespace fage {
	namespace input {
		class KeyboardState {
		public:
			bool IsKeyPressed(Keycode key);
		private:
			Keycode currentPressedKey;
		};
	}
}
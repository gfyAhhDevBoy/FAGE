#include "KeyboardState.h"

namespace fage {
	namespace input {
		bool KeyboardState::IsKeyPressed(Keycode key)
		{
			if (key == currentPressedKey)
				return true;
			return false;
		}
	}
}
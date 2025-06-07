#pragma once

#include "../Component.h"
#include "../Render/Display.h"

#include <iostream>

namespace fage {
	namespace component {
		class Test : public Component {
		public:

			Test(GameObject* parent) : Component(parent), t(true) {

			}

			void Update() override {
				if (t)
					std::cout << "test\n";
			}

			void Draw(render::Display& display) override {

			}

			void Stop() {
				t = false;
			}

		private:
			bool t;
		};
	}
}
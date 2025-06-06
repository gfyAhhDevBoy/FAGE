#pragma once

#include "../Component.h"
#include "../Render/Display.h"

namespace fage {
	namespace component {
		class Test : public Component {
		public:
			Test(GameObject* parent) : Component(parent) {

			}
			~Test() = default;

			void Update() override {
				if(t)
				std::cout << "test\n";
			}

			void Draw(render::Display& display) {

			}

			void Stop() {
				t = false;
			}

		private:
			bool t = true;
		};
	}
}
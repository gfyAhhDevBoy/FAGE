#pragma once

#include "../Component.h"
#include "../Render/Display.h"

namespace fage {
	namespace component {
		class Test : public Component {
		public:

			}
			~Test() = default;

			}

				
			void Stop() {
				t = false;
			}

		};
	}
}
#include <Engine.h>
#include <Display.h>
#include <Scene.h>

void KeyboardListener(int);

int main()
{
	fage::Core::Get().CreateDisplay();
	fage::Core::Get().AddKeyboardListener(KeyboardListener);
	std::shared_ptr<fage::Scene> scene = std::make_shared<fage::Scene>();
	fage::Core::Get().SetCurrentScene(scene);
	

	fage::Core::Get().Run();
}

void KeyboardListener(int key)
{
	if (key == fage::input::Escape)
	{
		fage::Core::Get().Stop();
		
	}
}
#include <Engine.h>
#include <Scene.h>
#include <GameObject.h>
#include <Components/Test.h>

#include <memory>

void KeyboardListener(int);

fage::component::Test* test;

int main()
{
	fage::Core::Get().CreateDisplay();
	fage::Core::Get().AddKeyboardListener(KeyboardListener);
	std::shared_ptr<fage::Scene> scene = std::make_shared<fage::Scene>();
	scene->SetClearColor({ 0.2f, 0.3f, 0.3f, 1.f });
	fage::Core::Get().ChangeScene(scene);
	
	fage::GameObject* player = scene->CreateGameObject({5, 3});
	test = player->AddComponent<fage::component::Test>();

	fage::Core::Get().Run();
}

void KeyboardListener(int key)
{
	if (key == fage::input::Escape)
	{
		fage::Core::Get().Stop();
		
	}
	else if (key == fage::input::Space) {
		
		test->Stop();
	}
}
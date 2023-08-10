// MicroECS includes
#include <micro_ecs/micro_ecs.hpp>

// STD includes
#include <iostream>

class TestComponent : public MicroECS::Component
{

public:

	TestComponent() : Component("TestComponent") {}

	void Test()
	{
		std::cout << "Entity " << GetEntity()->GetID() << " called the method Test() !" << std::endl;
	}

};

int main()
{
	// Add component
	MicroECS::EntityManager manager(10, 10);
	MicroECS::Entity * entity = manager.CreateEntity();
	TestComponent * test_component = manager.AddComponent<TestComponent>(entity);

	// Iterate entities with the component "TestComponent"
	manager.IterateEntitiesWithComponent<TestComponent>([&](const MicroECS::Entity & entity, TestComponent & component) 
	{
		std::cout << "Entity " << entity.GetID() << " has one TestComponent !" << std::endl;
		component.Test();
	});

	// Clear
	manager.ClearComponents();
	manager.ClearEntities();

	return 0;
}
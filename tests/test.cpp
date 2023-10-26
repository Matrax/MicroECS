// MicroECS includes
#include <micro_ecs/component_pool.hpp>

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
	// Component pool
	MicroECS::ComponentPool<TestComponent> manager(10);

	// Add entity
	MicroECS::Entity entity;

	// Add TestComponent to the entity
	TestComponent * test_component = manager.AddComponent(&entity);

	// Iterate entities with the component "TestComponent"
	manager.IterateEntitiesWithComponent([&](const MicroECS::Entity * entity, TestComponent * component) 
	{
		std::cout << "Entity " << entity->GetID() << " has one TestComponent !" << std::endl;
		component->Test();
	});

	return 0;
}
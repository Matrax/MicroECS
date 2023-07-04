// Test includes
#include "test_system.hpp"
#include "test_component.hpp"

// MicroECS includes
#include <component_manager.hpp>

int main()
{
	// Instantiate system
	TestSystem test_system;

	// Add component
	MicroECS::Entity test_entity;
	MicroECS::ComponentManager::AddComponent<TestComponent>(&test_entity);

	//
	std::vector<MicroECS::Entity> entities;
	entities.push_back(test_entity);
	test_system.Update(entities);

	return 0;
}
#pragma once

// MicroECS includes
#include <component_manager.hpp>
#include <system.hpp>

// STD includes
#include <iostream>

// Test includes
#include "test_component.hpp"

class TestSystem : public MicroECS::System
{

public:

	TestSystem() : MicroECS::System("TestSystem") {}

protected:

	void OnLoad()  override {}

	void OnUpdate(std::vector<MicroECS::Entity> & entities) override
	{
		for (MicroECS::Entity & entity : entities)
		{
			TestComponent* test_component = MicroECS::ComponentManager::GetComponent<TestComponent>(&entity);

			if (test_component != nullptr)
				test_component->Test();
		}
	}

	void OnUnload() override {}
};
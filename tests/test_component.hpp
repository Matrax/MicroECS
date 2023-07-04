#pragma once

// MicroECS includes
#include <component.hpp>

// STD includes
#include <iostream>

class TestComponent : public MicroECS::Component
{

public:

	TestComponent() : Component("TestComponent") {}

	void Test()
	{
		std::cout << "test" << std::endl;
	}

};
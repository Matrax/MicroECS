#pragma once

// STD includes
#include <vector>

// MicroECS includes
#include "id_generator.hpp"
#include "component.hpp"

namespace MicroECS
{
	class Entity
	{
	private:

		const MicroECS::IDGenerator::IDGeneratorType m_id;

	public:

		Entity() : m_id(MicroECS::IDGenerator::NextID()) {}

		inline MicroECS::IDGenerator::IDGeneratorType GetID() const { return m_id; }
	};
}

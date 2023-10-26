#pragma once

// STD includes
#include <functional>
#include <string>
#include <string_view>

// MicroECS includes
#include <micro_ecs/entity.hpp>

namespace MicroECS
{
	class Component
	{
	private:

		const std::string m_name;
		Entity * m_entity;

	public:

        // Constructors
        Component() = delete;
		
		Component(const std::string_view & name) : m_name(name), m_entity(nullptr) {}

        // Destructor
		virtual ~Component() {}

		inline void SetEntity(Entity* entity) { m_entity = entity; }

		inline const std::string & GetName() const { return m_name; }
		
		inline const Entity * GetEntity() const { return m_entity;  }
		
	};
}
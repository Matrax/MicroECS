#pragma once

// STD includes
#include <string>
#include <string_view>

// MicroECS includes
#include "entity.hpp"

namespace MicroECS
{
	class Component
	{
		private:

			const std::string m_name;
			Entity * m_entity;

		public:

			Component(const std::string_view & name) : m_name(name), m_entity(nullptr) {}

			virtual ~Component() {}

			inline const std::string & GetName() const { return m_name; }

			void SetEntity(Entity* entity) { m_entity = entity; }

			const Entity* GetEntity() const { return m_entity;  }
	};
}

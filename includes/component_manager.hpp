#pragma once

// STD includes
#include <vector>

// MicroECS includes
#include "component.hpp"
#include "entity.hpp"

namespace MicroECS
{
	class ComponentManager
	{
	private:

		inline static std::vector<Component *> components;

	public:

		template<typename T> static T * GetComponent(Entity * entity)
		{
			if (entity == nullptr)
				return nullptr;

			for (Component* component : components)
			{
				T * stored_components = dynamic_cast<T*>(component);

				if (stored_components != nullptr && stored_components->GetEntity()->GetID() == entity->GetID())
					return stored_components;
			}

			return nullptr;
		}

		template<typename T> static void AddComponent(Entity* entity)
		{
			T * comp = new T();

			comp->SetEntity(entity);

			ComponentManager::components.push_back(comp);
		}

	};
}

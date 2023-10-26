#pragma once

// STD includes
#include <functional>
#include <string>
#include <string_view>

// MicroECS includes
#include <micro_ecs/component.hpp>
#include <micro_ecs/entity.hpp>

namespace MicroECS
{
	
	template<typename T> class ComponentPool
	{
	private:

		T ** m_components;
		size_t m_max_components;

	public:

		ComponentPool(const size_t max_components) :
			m_max_components(max_components),
			m_components(nullptr)
		{
			m_components = new T*[max_components];

			for(size_t i = 0; i < max_components; i++)
				m_components[i] = nullptr;
		}

		// Destructor
		virtual ~ComponentPool() 
		{
			ClearComponents();

			if(m_components != nullptr) 
				delete[] m_components;
		}

		T * GetComponent(const Entity * entity)
		{
			if (entity == nullptr)
				return nullptr;

			for (size_t i = 0; i < m_max_components; i++)
			{
				if(m_components[i] != nullptr)
				{
					if (m_components[i]->GetEntity().GetID() == entity->GetID())
						return m_components[i];
				}
			}

			return nullptr;
		}

		T * AddComponent(Entity * entity)
		{
			for (size_t i = 0; i < m_max_components; i++)
			{
				if(m_components[i] == nullptr)
				{
					m_components[i] = new T();
					m_components[i]->SetEntity(entity);
					return dynamic_cast<T*>(m_components[i]);
				}
			}

			return nullptr;
		}

		bool RemoveComponent(Entity * entity)
		{
			if(entity == nullptr)
				return;

			for (size_t i = 0; i < m_max_components; i++)
			{
				if(m_components[i] != nullptr 
				&& m_components[i]->GetEntity() == entity 
				&& m_components[i]->GetName().compare(typeid(T).name()) == 0)
				{
					delete m_components[i];
					m_components[i] = nullptr;
					return true;
				}
			}

			return false;
		}

		void IterateEntitiesWithComponent(const std::function<void(const Entity * entity, T * component)> callback)
		{
			if(callback == nullptr)
				return;

			for (size_t i = 0; i < m_max_components; i++)
			{
				if(m_components[i] != nullptr && m_components[i]->GetEntity() != nullptr)
					callback(m_components[i]->GetEntity(), m_components[i]);
			}
		}
		
		void ClearEntityComponents(Entity * entity)
		{
			if(entity == nullptr)
				return;

			for (size_t i = 0; i < m_max_components; i++)
			{
				if(m_components[i] != nullptr && m_components[i]->GetEntity() == entity)
				{
					delete m_components[i];
					m_components[i] = nullptr;
				}
			}
		}

		void ClearComponents()
		{
			for(size_t i = 0; i < m_max_components; i++)
			{
				if(m_components[i] != nullptr)
				{
					delete m_components[i];
					m_components[i] = nullptr;
				}
			}
		}

	};


}

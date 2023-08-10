#pragma once

// STD includes
#include <functional>
#include <string>
#include <string_view>

namespace MicroECS
{
	// ID type
	using IDGeneratorType = unsigned long long int;

	//
	class IDGenerator
	{
	private:

		inline static IDGeneratorType ID_COUNTER = 0;

	public:

		// No constructor
		IDGenerator() = delete;

		// No copy constructor
		IDGenerator(IDGenerator & copy) = delete;
		IDGenerator(const IDGenerator & copy) = delete;

		// Destructor
		virtual ~IDGenerator() {}

		inline static IDGeneratorType NextID()
		{
			return ID_COUNTER++;
		}

		inline static IDGeneratorType ResetCounter()
		{
			ID_COUNTER = 0;
		}

	};

	//
	class Entity
	{
	private:

		const MicroECS::IDGeneratorType m_id;

	public:

		Entity() : m_id(MicroECS::IDGenerator::NextID()) {}

		Entity(Entity & copy) = delete;
		Entity(const Entity & copy) = delete;

		virtual ~Entity() {}

		inline MicroECS::IDGeneratorType GetID() const { return m_id; }
	};

	//
	class Component
	{
	private:

		const std::string m_name;
		Entity * m_entity;

	public:

		Component(const std::string_view & name) : m_name(name), m_entity(nullptr) {}

		virtual ~Component() 
		{
			m_entity = nullptr;
		}

		inline void SetEntity(Entity* entity) { m_entity = entity; }

		inline const std::string & GetName() const { return m_name; }

		inline const Entity * GetEntity() const { return m_entity;  }
		
	};

	//
	class EntityManager
	{
	private:

		Entity ** m_entities;
		Component ** m_components;
		size_t m_max_entities;
		size_t m_max_components;

	public:

		EntityManager(const size_t max_entities, const size_t max_components) :
			m_max_entities(max_entities), 
			m_max_components(max_components),
			m_entities(nullptr),
			m_components(nullptr)
		{
			m_entities = new Entity*[max_entities];
			for(size_t i = 0; i < max_entities; i++)
			{
				m_entities[i] = nullptr;
			}

			m_components = new Component*[max_components];
			for(size_t i = 0; i < max_components; i++)
			{
				m_components[i] = nullptr;
			}
		}

		// No copy constructor
		EntityManager(EntityManager & copy) = delete;
		EntityManager(const EntityManager & copy) = delete;

		// No Destructor
		virtual ~EntityManager() 
		{
			ClearEntities();
			ClearComponents();

			if(m_entities != nullptr) 
				delete[] m_entities;

			if(m_components != nullptr) 
				delete[] m_components;
		}

		template<typename T> T * GetComponent(const Entity * entity)
		{
			if (entity == nullptr)
				return nullptr;

			for (size_t i = 0; i < m_max_components; i++)
			{
				Component * component = m_components[i];

				if(component != nullptr)
				{
					if (component->GetEntity()->GetID() == entity->GetID())
						return stored_components;
				}
			}

			return nullptr;
		}

		Entity * CreateEntity()
		{
			for (size_t i = 0; i < m_max_entities; i++)
			{
				if(m_entities[i] == nullptr)
				{
					m_entities[i] = new Entity();
					return m_entities[i];
				}
			}

			return nullptr;
		}

		template<typename T> T * AddComponent(Entity * entity)
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

		template<typename T> bool RemoveComponent(Entity * entity)
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

		template<typename T> void IterateEntitiesWithComponent(std::function<void(const Entity & entity, T & component)> callback)
		{
			if(callback == nullptr)
				return;

			for (size_t i = 0; i < m_max_components; i++)
			{
				if(m_components[i] != nullptr)
				{
					const Entity * entity = m_components[i]->GetEntity();
					std::string component_name = std::string(typeid(T).name());

					if (entity != nullptr && component_name.compare(m_components[i]->GetName().c_str()))
					{
						T * founded_component = dynamic_cast<T*>(m_components[i]);
						callback(*entity, *founded_component);
					}
				}
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

		void ClearEntities()
		{
			for(size_t i = 0; i < m_max_entities; i++)
			{
				if(m_entities[i] != nullptr)
				{
					delete m_entities[i];
					m_entities[i] = nullptr;
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

#pragma once

// MicroECS includes
#include <micro_ecs/id_generator.hpp>

namespace MicroECS
{
    class Entity
    {
    private:

        const MicroECS::IDGeneratorType m_id;

    public:

        // Constructors
        Entity() : m_id(MicroECS::IDGenerator::NextID()) {}

        // No copy constructor
        Entity(Entity & copy) = delete;
        Entity(const Entity & copy) = delete;

        // Destructor
        virtual ~Entity() {}

        inline MicroECS::IDGeneratorType GetID() const { return m_id; }
    };
}

#pragma once

namespace MicroECS
{
    using IDGeneratorType = unsigned long long int;

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

        // No destructor
        virtual ~IDGenerator() = delete;

        inline static IDGeneratorType NextID() { return ID_COUNTER++; }
        inline static IDGeneratorType ResetCounter() { ID_COUNTER = 0; }

    };
}

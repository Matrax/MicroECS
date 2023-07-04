#pragma once

namespace MicroECS
{
	namespace IDGenerator
	{
		using IDGeneratorType = unsigned long long int;

		inline IDGeneratorType ID_COUNTER = 0;

		inline IDGeneratorType NextID()
		{
			return ID_COUNTER++;
		}
	}
}
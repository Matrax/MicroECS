#pragma once

// STD includes
#include <iostream>
#include <string>
#include <vector>

// MicroECS includes
#include "entity.hpp"

namespace MicroECS
{
	class System
	{

	private:

		const std::string m_name;

	protected:

		virtual void OnLoad() = 0;
		virtual void OnUpdate(std::vector<MicroECS::Entity> & entities) = 0;
		virtual void OnUnload() = 0;

	public:

		System(const std::string_view& name) : m_name(name) {}

		virtual ~System() {}

		void Load() { OnLoad(); }

		void Update(std::vector<MicroECS::Entity> & entities) { OnUpdate(entities); }

		void Unload() { OnUnload(); }

		inline const std::string & GetName() const { return m_name; }
	};
}

#include "HardwareModule.h"
#include "pch.h"


namespace Selina
{
	namespace Library
	{
		bool HardwareModule::IsUp()
		{
			std::string result = Utility::exec("ifconfig", m_InterfaceName.c_str());
			return result.find(m_InterfaceName);
		}
	}
}

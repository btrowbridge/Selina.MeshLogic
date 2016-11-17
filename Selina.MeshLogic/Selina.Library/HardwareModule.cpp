#include "HardwareModule.h"
#include "pch.h"


namespace Selina
{
	namespace Library
	{
		HardwareModule::HardwareModule(std::string initFile, std::string interfaceName) 
			: m_InitFile(initFile), m_InterfaceName(interfaceName)
		{
			
		}
		
		bool HardwareModule::IsUp() const
		{
			std::string result = Utility::exec(SYS_ifconfig, m_InterfaceName.c_str());
			return (result.find(m_InterfaceName) != std::string::npos);
		}
	}
}

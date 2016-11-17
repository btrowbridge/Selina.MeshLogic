#pragma once

#include <string>
#include <boost/asio/ip/address.hpp>
#include "netiface.h"
namespace Selina
{
	namespace Library
	{

		class HardwareModule
		{
		public:
			HardwareModule(std::string initFile, std::string interfaceName);
			~HardwareModule() = default;
		
			void StartUp();
			bool IsUp() const;
			void TakeDown();
			
			
			
			
			
		
		private:
			std::string m_InitFile;
			netiface
			
		};

	}
}
#pragma once

#include <string>
#include <boost/asio/ip/address.hpp>

namespace Selina
{
	namespace Library
	{

		class HardwareModule
		{
		public:
			HardwareModule(std::string initFile, std::string interfaceName);
			~HardwareModule();
		
			void StartUp();
			bool IsUp();
			void TakeDown();
			
			void SetIpv4(boost::asio::ip::address_v4 ipv4);
			void SetIpv6(boost::asio::ip::address_v6 ipv6);
		
			void SetIpAddress(boost::asio::ip::address address);
			boost::asio::ip::address GetIpAddress();
		
		private:
			std::string m_InitFile;
			std::string m_InterfaceName;
			boost::asio::ip::address_v4 m_IPAddress_v4;
			boost::asio::ip::address_v6 m_IPAddress_v6;
			
		};

	}
}
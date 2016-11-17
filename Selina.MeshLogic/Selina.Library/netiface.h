#pragma once
#include <boost/asio/ip/address.hpp>
#include <string>
#include <sys/ioctl.h>
#include <net/if.h>

namespace Library
{
	class Netiface
	{
	public:
		Netiface(std::string name);
		~Netiface() = default;
		
		static const std::shared_ptr<Netiface> Load(std::string ifaceName);
		
		const ifreq* Get();
		
	private:
		void _loadIfaceFromSys();
	
		
		std::weak_ptr<ifreq> m_Iface;
		std::string m_IfName;
	
	};

}
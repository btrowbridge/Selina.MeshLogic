#include "netiface.h"
#include "pch.h"

using namespace std;

namespace Library
{
	Netiface::Netiface(std::string name) : m_IfName(name)
	{
	}
	
		
	const std::shared_ptr<Netiface> Netiface::Load(std::string ifaceName)
	{
		return make_shared<Netiface>(ifaceName);
	}

	const ifreq* Netiface::Get()
	{
		this->_loadIfaceFromSys();
		return m_Iface.lock().get();
	}
	
	void Netiface::_loadIfaceFromSys()
	{
		ifreq ifr;
		size_t if_name_len=std::strlen(m_IfName.c_str());
		
		if (if_name_len<sizeof(ifr.ifr_name)) {
			memcpy(ifr.ifr_name,m_IfName.c_str(),if_name_len);
			ifr.ifr_name[if_name_len]=0;
		} else {
			 THROW("interface name is too long");
		}
		
		int fd=socket(AF_INET,SOCK_DGRAM,0);
			if (fd==-1) {
				THROW("%s",strerror(errno));
		}
		
		if (ioctl(fd,SIOCGIFADDR,&ifr)==-1) {
			int temp_errno=errno;
			close(fd);
				THROW("%s",strerror(temp_errno));
		}
		close(fd);
		
		m_Iface = make_shared<ifreq>(ifr);
	}
}

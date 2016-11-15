#pragma once
#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <stdarg.h>
#include <stdio.h>
#include <cstring>
using namespace std;


namespace Utility
{
	#define UNREFERENCED_PARAMETER(a) a=a;
	

	std::string __exec(const char* cmd) {
		char buffer[128];
		std::string result = "";
		std::shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);
		if (!pipe) throw std::runtime_error("popen() failed!");
		while (!feof(pipe.get())) {
			if (fgets(buffer, 128, pipe.get()) != NULL)
				result += buffer;
		}
		return result;
	}
	
	//variadic overload
	
	std::string exec(const char* first,...)
	{
		va_list list;
		va_start(list,first);
		
		char cmds[sizeof(list)];
		
		char* it = va_arg(list, char*);
		strcpy(cmds, it);
			
		while(*first != '\0')
		{
			it = va_arg(list, char*);
			strcat(cmds, it);
			++first;
		}
		va_end(list);
		
		return __exec(cmds);
	}
}

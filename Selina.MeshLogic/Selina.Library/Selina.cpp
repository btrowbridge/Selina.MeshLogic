#include "Selina.h"

/*
	To test the library, include "Selina.h" from an application project
	and call SelinaTest().
	
	Do not forget to add the library to Project Dependencies in Visual Studio.
*/

static int s_Test = 0;

int SelinaTest()
{
	return ++s_Test;
}
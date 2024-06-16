
#include <iostream>
#include <iomanip>
#include <string>
#include "clsLoginScreen.h"
#include "clsDate.h"
#include "clsCuranncy.h"
using namespace std;

int main()
{


	
	while (true)
	{

		if (!clsLoginScreen::ShowLoginScreen())
		{
			break;
	    }

	}


	return 0;
};


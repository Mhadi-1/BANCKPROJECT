#pragma once
#include <string>
#include <iostream>
using namespace std;


// Abstract Class or Interface or Absloid Class
class InterfaceCommnucation
{

public:

	virtual void SendEmail(string Message, string Body) = 0; 
	virtual void SendFax(string Title, string Body) = 0; 
	virtual void SendSMS(string Title, string Body) = 0; 
	virtual  short RAGE(short Age, string Name) = 0; 
	// Using  With Out Elemention
};


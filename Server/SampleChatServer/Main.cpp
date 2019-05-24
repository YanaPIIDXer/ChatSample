#include <iostream>
#include "Server/Server.h"

int main()
{
	std::cout << "Chat Sample Server Boot..." << std::endl;

	Server Sv;
	Sv.StartListen(1234);

	while(Sv.Service()) {}

	return 0;
}

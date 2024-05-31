#include "Online.h"
#include "Ping.h"
#include <iostream>

void Online::FirstServer()
{
	listener.listen(53001);

	if (listener.accept(socket) == sf::Socket::Done)
	{
		waitm.wait.close();
	}
}

void Online::FirstClient()
{
	if (socket.connect("127.0.0.1", 53001) == sf::Socket::Done)
	{
		waitm.wait.close();
	}

}

void Online::Server()
{
	PacketForClient.clear();
	PacketForClient << y1plat1 << x1plat1 << x << y;

	socket.send(PacketForClient);
	socket.receive(PacketForServer);

	PacketForServer >> y1plat2 >> x1plat2;

	//std::cout << y1plat2 << x1plat2 << std::endl;
}

void Online::Client()
{
	PacketForServer.clear();
	PacketForServer << y1plat2 << x1plat2;

	socket.send(PacketForServer);
	socket.receive(PacketForClient);

	PacketForClient >> y1plat1 >> x1plat1 >> x >> y;

	//std::cout << y1plat2 << x1plat2 << std::endl;

}

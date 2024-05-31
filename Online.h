#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include "WaitMenu.h"
#include "Ping.h"

class Online
{
private:
	sf::IpAddress ip = sf::IpAddress::getLocalAddress();
	sf::TcpListener listener;
	sf::TcpSocket socket;
	sf::Packet PacketForClient;
	sf::Packet PacketForServer;
public:
	WaitMenu& waitm;
	Online(WaitMenu& newwaitm) :waitm(newwaitm) {}

	void FirstServer();
	void FirstClient();
	void Server();
	void Client();
};
/*---- OVERLOAD FLUX OPERATOR ----*/

/*---- LIBRARY ----*/

/*---- LIBRARY SFML ----*/
#include "SFML/Network.hpp"

/*---- LOCAL FILE ----*/
#include "ClientToServer.hpp"
#include "ServerToClient.hpp"

/*======== SERVER_TO_CLIENT ========*/

/*==== PROTOCOL ====*/

sf::Packet& operator >>(sf::Packet& packet, STC::Protocol& data) {   
	sf::Uint16 receive;
    packet >> receive
	data = (STC::Protocol)receive;
    return packet;
}

/*---- LOAD_MAP ----*/

sf::Packet& operator >>(sf::Packet& packet, STC::LoadMap& data) {   
	sf::Uint16 receive;
    packet >> receive
	data = (STC::LoadMap)receive;
    return packet;
}

//---- PLAYER
sf::Packet& operator >>(sf::Packet& packet, STC::Player& data) {
    packet >> data.userName;
    return packet;
}

//---- MONSTER
sf::Packet& operator >>(sf::Packet& packet, STC::Monster& data) {
    return packet;
}

/*---- UPDATE_MAP ----*/

sf::Packet& operator >>(sf::Packet& packet, STC::UpdateMap& data) {   
	sf::Uint16 receive;
    packet >> receive
	data = (STC::UpdateMap)receive;
    return packet;
}

/*---- LOGGED ----*/
sf::Packet& operator >>(sf::Packet& packet, STC::Logged& data) {
	sf::Uint16 receive;
    packet >> receive
	data = (STC::Logged)receive;
    return packet;
}

/*======== CLIENT_TO_SERVER ========*/

/*==== PROTOCOL ====*/

sf::Packet& operator >>(sf::Packet& packet, CTS::Protocol& data){   
	sf::Uint16 receive;
	packet >> receive;
    data = (CTS::Protocol)receive;
    return packet;
}

/*---- LOGGED ----*/

sf::Packet& operator >>(sf::Packet& packet, CTS::Logged& data){   
    return packet >> data.userName;
}
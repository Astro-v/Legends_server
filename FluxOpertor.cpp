/*---- OVERLOAD FLUX OPERATOR ----*/

#include "ClientToServer.hpp"
#include "ServerToClient.hpp"
#include "Player.hpp"
#include "Map.hpp"

/*---- MAP ----*/
sf::Packet& operator <<(sf::Packet& packet, const Map& data) {
    for (int i=0;i<data.getNumberPlayer();++i) {
        packet << data.getPlayer(i);
    }
    return packet;
}

/*---- PLAYER ----*/

/*---- LOAD_MAP ----*/ 
sf::Packet& operator <<(sf::Packet& packet, const STC::LoadMapData& data) {   
    for (auto & player : data.player) {
        packet << STC::PLAYER << *player;
    }
    return packet;
}
//---- PLAYER
sf::Packet& operator <<(sf::Packet& packet, const Player& data) {
    packet << data.getUserName() << data.getId() << data.getPos();
    return packet;
}

/*---- SERVER_TO_CLIENT ----*/

/*---- PROTOCOL ----*/

sf::Packet& operator <<(sf::Packet& packet, const STC::Protocol& data) {   
	int send;
	send = (int)data;
    return packet << send;
}

/*---- LOAD_MAP ----*/

sf::Packet& operator <<(sf::Packet& packet, const STC::LoadMap& data) {   
	int send;
	send = (int)data;
    return packet << send;
}

/*---- UPDATE_MAP ----*/

sf::Packet& operator <<(sf::Packet& packet, const STC::UpdateMap& data) {   
	int send;
	send = (int)data;
    return packet << send;
}

/*---- CLIENT_TO_SERVER ----*/

/*---- PROTOCOL ----*/

sf::Packet& operator >>(sf::Packet& packet, CTS::Protocol& data){   
	int receive;
	packet >> receive;
    data = (CTS::Protocol)receive;
    return packet;
}

/*---- LOGGED ----*/

sf::Packet& operator >>(sf::Packet& packet, CTS::Logged& data){   
    return packet >> data.userName;
}
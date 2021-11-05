#ifndef __SERVER_TO_CLIENT__
#define __SERVER_TO_CLIENT__

/*---- LIBRARY ----*/
#include <vector>
#include <string>

/*---- LIBRARY SFML ----*/
#include "SFML/Network.hpp"

/*---- LOCAL FILE ----*/
#include "Player.hpp"
#include "Map.hpp"

namespace STC { // Server To Client
    enum Protocol {
        EOF, CHECK_CONNECTION, UPDATE_MAP, LOAD_MAP, FIGHT
    };

    /*---- LOAD_MAP ----*/ 
    enum LoadMap {
        EOF, PLAYER, MONSTER
    };

    /*---- UPDATE_MAP ----*/
    enum UpdateMap {
        EOF, PLAYER_MOVE, PLAYER_APPEAR, MONSTER_MOVE, MONSTER_APPEAR, FIGHT_BEGIN
    };

    //---- PLAYER_MOVE
    struct PlayerMove {
        sf::Uint32 newPosPlayer;       // New position of the player on the Map (index in the list _tile)
        sf::Uint32 idPlayer;           // Id of the player that move
    };
}

/*---- FLUX OPERATOR ----*/

/*---- PROTOCOL ----*/

sf::Packet& operator <<(sf::Packet& packet, const STC::Protocol& data){   
	int send;
	send = (int)data;
    return packet << send;
}

/*---- LOAD_MAP ----*/

sf::Packet& operator <<(sf::Packet& packet, const STC::LoadMap& data){   
	int send;
	send = (int)data;
    return packet << send;
}

//---- PLAYER
sf::Packet& operator <<(sf::Packet& packet, const Player& data) {
    packet << data.getName() << data.getId() << data.getPos();
    return packet;
}

sf::Packet& operator <<(sf::Packet& packet, const Map& data) {
    for (int i=0;i<data.getNumberPlayer();++i) {
        packet << data.getPlayer(i);
    }
    return packet;
}

/*---- UPDATE_MAP ----*/

sf::Packet& operator <<(sf::Packet& packet, const STC::UpdateMap& data){   
	int send;
	send = (int)data;
    return packet << send;
}





/*sf::Packet& operator <<(sf::Packet& packet, const UpdateMap& data) {
    for (auto & element : data) {
        packet << element;
    }
    return packet;
} */

#endif // __SERVER_TO_CLIENT__
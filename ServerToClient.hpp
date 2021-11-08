#ifndef __SERVER_TO_CLIENT__
#define __SERVER_TO_CLIENT__

/*---- LIBRARY ----*/
#include <vector>
#include <string>

/*---- LIBRARY SFML ----*/
#include "SFML/Network.hpp"

/*---- LOCAL FILE ----*/

namespace STC { // Server To Client
    enum Protocol {
        EOF_PROTOCOL, CHECK_CONNECTION, UPDATE_MAP, LOAD_MAP, FIGHT, LOGGED
    };

    /*---- LOAD_MAP ----*/ 
    enum LoadMap {
        EOF_LOAD_MAP, PLAYER, MONSTER
    };

    //---- PLAYER 
    struct Player {
        std::string userName;
        // sf::Uint32 pos;
    }

    //---- MONSTER 
    struct Monster {
        std::string userName;
        // sf::Uint32 pos;
    }

    /*---- UPDATE_MAP ----*/
    enum UpdateMap {
        EOF_UPDATE_MAP, PLAYER_MOVE, PLAYER_APPEAR, MONSTER_MOVE, MONSTER_APPEAR, FIGHT_BEGIN
    };

    /*---- LOGGED ----*/
    enum Logged {
        SUCCEED, FAILURE
    }

}

/*---- FLUX OPERATOR ----*/
/*==== PROTOCOL ====*/
sf::Packet& operator <<(sf::Packet& packet, const STC::Protocol& data);   
/*---- LOAD_MAP ----*/
sf::Packet& operator <<(sf::Packet& packet, const STC::LoadMap& data);
//---- PLAYER
sf::Packet& operator <<(sf::Packet& packet, const STC::Player& data);
//---- MONSTER
sf::Packet& operator <<(sf::Packet& packet, const STC::Monster& data);
/*---- UPDATE_MAP ----*/
sf::Packet& operator <<(sf::Packet& packet, const STC::UpdateMap& data);

#endif // __SERVER_TO_CLIENT__
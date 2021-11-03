#ifndef __SERVER_TO_CLIENT__
#define __SERVER_TO_CLIENT__

/*---- LIBRARY ----*/
#include <vector>

/*---- LIBRARY SFML ----*/
#include "SFML/Network.hpp"

/*---- LOCAL FILE ----*/

namespace STC { // Server To Client
    enum Protocol {
        CHECK_CONNECTION, UPDATE_MAP
    };

    /*---- UPDATE_MAP ----*/
    enum UpdateMap {
        PLAYER_MOVE, PLAYER_APPEAR, MONSTER_MOVE, MONSTER_APPEAR
    };

    // PLAYER_MOVE
    struct PlayerMove {
        sf::Uint32 newPosPlayer;       // New position of the player on the Map (index in the list _tile)
        sf::Uint32 idPlayer;           // Id of the player that move
    };
}

/*---- FLUX OPERATOR ----*/
/*sf::Packet& operator <<(sf::Packet& packet, const UpdateMap& data) {
    for (auto & element : data) {
        packet << element;
    }
    return packet;
} */

#endif // __SERVER_TO_CLIENT__
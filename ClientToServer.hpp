#ifndef __CLIENT_TO_SERVER__
#define __CLIENT_TO_SERVER__

/*---- LIBRARY ----*/
#include <string>

/*---- LIBRARY SFML ----*/
#include "SFML/Network.hpp"

/*---- LOCAL FILE ----*/

namespace CTS { // Client To Server 
    enum Protocol {
        EOF_PROTOCOL, NOTHING, LOGGED, CHECK_CONNECTION
    };

    /*---- LOGGED ----*/
    struct Logged {
        std::string userName;
        // std::string password;
    };
}

/*---- FLUX OPERATOR ----*/

sf::Packet& operator >>(sf::Packet& packet, CTS::Protocol& data);
sf::Packet& operator >>(sf::Packet& packet, CTS::Logged& data);

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

#endif // __CLIENT_TO_SERVER__
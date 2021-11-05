#ifndef __CLIENT_TO_SERVER__
#define __CLIENT_TO_SERVER__

/*---- LIBRARY ----*/
#include <string>

/*---- LIBRARY SFML ----*/
#include "SFML/Network.hpp"

/*---- LOCAL FILE ----*/

namespace CTS { // Client To Server 
    enum Protocol {
        CONNECTION, CHECK_CONNECTION
    };

    /*---- CONNECTION ----*/
    struct Connection {
        std::string userName;
        // std::string password;
    }
}

/*---- FLUX OPERATOR ----*/

/*---- PROTOCOL ----*/

sf::Packet& operator >>(sf::Packet& packet, const CTS::Protocol& data){   
	int receive;
	packet >> receive;
    data = (CTS::Protocol)receive;
    return packet;
}

/*---- CONNECTION ----*/

sf::Packet& operator >>(sf::Packet& packet, const CTS::Connection& data){   
    return packet >> Connection.userName;
}

#endif // __CLIENT_TO_SERVER__
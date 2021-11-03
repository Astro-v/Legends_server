#ifndef __PLAYER__
#define __PLAYER__

/*---- LIBRARY ----*/

/*---- LIBRARY SFML ----*/
#include "SFML/Network.hpp"

/*---- LOCAL FILE ----*/
#include "ServerToClient.hpp"
#include "ClientToServer.hpp"

/*---- SERVER ----*/
#define SERVER_PORT 5500	
#define SERVER_ADRESS sf::IpAddress::getLocalAddress() // IP adress of the server

class Player {
    public:
    /*---- CONSTRUCTOR ----*/
    Player();

    /*---- DESTRUCTOR ----*/
    ~Player();

    /*---- COMMUNICATION ----*/
    bool send(STC::Protocol protocol) const;       // Return true if everything has been sent well
    bool receive();                                // Return true if something has been receive

    protected:

    private:
    sf::TcpSocket _socket;                         // Socket for comunication
    sf::IpAddress _ipAddress;                      // Ip address of the player
    unsigned short _port;                          // Port for the connection
}

#endif // __PLAYER__
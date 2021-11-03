#ifndef __PLAYER__
#define __PLAYER__

/*---- LIBRARY ----*/
#include <string>

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
    bool loadMap(STC::Protocol protocol) const;       // Return true if everything has been sent well
    bool receive();                                // Return true if something has been receive

    /*---- ACCESSOR ----*/
    std::string getName() const;
    sf::Uint32 getPos() const;
    sf::Uint32 getId() const;

    protected:

    private:
    sf::TcpSocket _socket;                         // Socket for comunication
    sf::IpAddress _ipAddress;                      // Ip address of the player
    unsigned short _port;                          // Port for the connection
    std::string _name;
    sf::Uint32 _pos;                               // Pos of the player
    sf::Uint32 _id;
}

#endif // __PLAYER__
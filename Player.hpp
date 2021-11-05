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
    bool loadMap(STC::LoadMap protocol) const;                                   // Send the map to the player, return true if everything has been sent well
    CTS::Protocol receive();                                // Receive data from the player, return the protocol

    /*---- ACCESSOR ----*/
    std::string getUserName() const;
    sf::Uint32 getPos() const;
    sf::Uint32 getId() const;
    sf::TcpSocket* getSocket();
    void gotConnection();

    /*---- NUMBER OF PLAYER ----*/
    static int _numberOfPlayer;

    protected:

    private:
    /*---- CONECTION DATA ----*/
    sf::TcpSocket* _socket;                        // Socket for comunication
    sf::Packet _packetReceive;                     // Packet for reception
    sf::IpAddress _ipAddress;                      // Ip address of the player
    unsigned short _port;                          // Port for the connection
    CTS::Protocol _protocolCTS;

    /*---- PLAYER DATA ----*/
    std::string _userName;
    sf::Uint32 _pos;                               // Pos of the player
    sf::Uint32 _id;
};

Player::_numberOfPlayer = 0;

#endif // __PLAYER__
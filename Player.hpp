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
    sf::Status receive(sf::Packet& packetReceive);                                // Receive data from the player, return the protocol
    void send(const sf::Packet packetSend) const;

    /*---- ACCESSOR ----*/
    std::string getUserName() const;
    sf::Uint32 getPos() const;
    sf::Uint32 getId() const;
    sf::TcpSocket* getSocket();
    void gotConnection();

    /*---- LOAD THE PLAYER DATA ----*/
    void logPlayer(CTS::Logged logged);

    /*---- NUMBER OF PLAYER ----*/

    static int getNumberPlayer();
    
    protected:
    

    private:
    /*---- CONECTION DATA ----*/
    sf::TcpSocket* _socket;                        // Socket for comunication
    sf::IpAddress _ipAddress;                      // Ip address of the player
    unsigned short _port;                          // Port for the connection
    CTS::Protocol _protocolCTS;
    sf::Packet _packetSend;

    /*---- PLAYER DATA ----*/
    std::string _userName;
    sf::Uint32 _pos;                               // Pos of the player
    sf::Uint32 _id;
    std::string _path;                             // Path to the player data
    std::string _password;                         // Password of the player
    bool _logged; 


    /*---- NUMBER OF PLAYER ----*/
    static int _numberOfPlayer;
};

#endif // __PLAYER__
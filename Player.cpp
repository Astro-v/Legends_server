/*---- LIBRARY ----*/
#include <iostream>
#include <string>

/*---- LIBRARY SFML ----*/
#include "SFML/Network.hpp"

/*---- LOCAL FILE ----*/
#include "Player.hpp"
#include "ServerToClient.hpp"
#include "ClientToServer.hpp"
#include "Map.hpp"

/*---- CONSTRUCTOR ----*/
Player::Player():_userName("Unknown"),_pos(0),_id(0),_ipAddress("0.0.0.0"),_port(0) {
    _socket = new sf::TcpSocket;
    _packetReceive.clear();
}

/*---- DESTRUCTOR ----*/
Player::~Player() {
    delete _socket;
    //--_numberOfPlayer;
    //std::cout << "Number of player : " << _numberOfPlayer << std::endl;
}

/*---- COMMUNICATION ----*/
// Return true if everything has been sent well
bool Player::loadMap() const {
    return true;
}     

// Receive data from the player, return the protocol
CTS::Protocol Player::receive() {
    _packetReceive.clear();
    if (_socket->receive(_packetReceive) == sf::Socket::Done) {
        _packetReceive >> _protocolCTS;
        while (_protocolCTS != CTS::EOF_PROTOCOL) {
            if (_protocolCTS == CTS::LOGGED) {
                CTS::Logged logged;
                _packetReceive >> logged;
                _userName = logged.userName;
                //++_numberOfPlayer;
                //std::cout << "Number of player : " << _numberOfPlayer << std::endl;
                return CTS::LOGGED; // receive a connection
            }
            _packetReceive >> _protocolCTS;
        }
    }
    return CTS::NOTHING; // nothing receive
}                     

/*---- ACCESSOR ----*/
std::string Player::getUserName() const {
    return _userName;
}

sf::Uint32 Player::getPos() const {
    return _pos;
}

sf::Uint32 Player::getId() const {
    return _id;
}

sf::TcpSocket* Player::getSocket() {
    return _socket;
}

void Player::gotConnection() {
    _ipAddress = _socket->getRemoteAddress();
    _port = _socket->getRemotePort();
}

/*---- OVERLOAD FLUX OPERATOR ----*/

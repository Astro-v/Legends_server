/*---- LIBRARY ----*/
#include <iostream>
#include <string>

/*---- LIBRARY SFML ----*/
#include "SFML/Network.hpp"

/*---- LOCAL FILE ----*/
#include "Player.hpp"
#include "ServerToClient.hpp"
#include "ClientToServer.hpp"

/*---- CONSTRUCTOR ----*/
Player::Player():_userName("Unknown"),_pos(0),_id(0),_socket(socket),_ipAddress("0.0.0.0"),_port(0) {
    _socket = new sf::TcpSocket;
    _packetReceive.clear();
}

/*---- DESTRUCTOR ----*/
Player::~Player() {
    --_numberPlayers;
    std::cout << "Number of player : " << _numberPlayers << std::endl;
}

/*---- COMMUNICATION ----*/
// Return true if everything has been sent well
bool Player::sendMap(STC::Protocol protocol) const {
    
}     

// Receive data from the player, return the protocol
CTS::Protocol Player::receive() {
    _packetReceive.clear();
    if (_socket[index].receive(_packetReceive) == sf::Socket::Done) {
        _packetReceive >> _protocolCTS;
        if (_protocolCTS == CTS::CONNECTION) {
            CTS::Connection connection;
            _packetReceive >> connection;
            _userName = connection.userName;
            return CTS::CONNECTION; // receive a connection
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
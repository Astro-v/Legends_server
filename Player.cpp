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
Player::Player(std::string name, sf::TcpSocket* socket):_name(name),_pos(0),_id(0),_socket(socket) {
    _ipAddress = _socket->getRemoteAddress();
    _port = _socket->getRemotePort();
    ++_numberOfPlayer;
    std::cout << "Number of player : " << _numberPlayers << std::endl;
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

// Return true if something has been receive
bool Player::receive() {

}                     

/*---- ACCESSOR ----*/
std::string Player::getName() const {
    return _name;
}

sf::Uint32 Player::getPos() const {
    return _pos;
}

sf::Uint32 Player::getId() const {
    return _id;
}
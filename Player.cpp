/*---- LIBRARY ----*/
#include <iostream>
#include <string>
#include <fstream>

/*---- LIBRARY SFML ----*/
#include "SFML/Network.hpp"

/*---- LOCAL FILE ----*/
#include "Player.hpp"
#include "ServerToClient.hpp"
#include "ClientToServer.hpp"
#include "Map.hpp"

int Player::_numberOfPlayer = 0;

/*---- CONSTRUCTOR ----*/
Player::Player():_userName("Unknown"),_pos(0),_id(0),_ipAddress("0.0.0.0"),_port(0),_logged(false) {
    _socket = new sf::TcpSocket;
    _socket->setBlocking(false);
    ++_numberOfPlayer;
    std::cout << "Number of class player : " << _numberOfPlayer << std::endl;
    _packetSend.clear();
}

/*---- DESTRUCTOR ----*/
Player::~Player() {
    delete _socket;
    --_numberOfPlayer;
    std::cout << "Number of class player : " << _numberOfPlayer << std::endl;
}

/*---- COMMUNICATION ----*/
// Receive data from the player, return the status
sf::Status receive(sf::Packet& packetReceive)  {
    return _socket->receive(packetReceive);
}

void Player::send(const sf::Packet& packetSend) const {
    _socket->send(packetSend);
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

bool Player::setLogged(CTS::Logged logged) {
    _path = std::string("Player/")+logged.userName;
    _userName = logged.userName;
    _password = logged.password;
    _packetSend.clear();
    _packetSend << STC::LOGGED;
    // Opening the file
    std::ifstream file(_path);
    if (file) {
        // Read Data of the player
        _packetSend << STC::SUCCEED;
        _packetSend << STC::EOF_PROTOCOL;
        _socket->send(_packetSend);
    } else {
        _packetSend << STC::FAILURE;
        _packetSend << STC::EOF_PROTOCOL;
        _socket->send(_packetSend);
        std::cout << "ERROR: Impossible to open the file " << _path << std::endl;
    }
    return false;
}

/*---- NUMBER OF PLAYER ----*/
int  Player::getNumberPlayer() {
    return _numberOfPlayer-1;
}

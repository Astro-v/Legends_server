/*---- LIBRARY ----*/
#include <vector>
#include <iostream>

/*---- LIBRARY SFML ----*/
#include "SFML/Network.hpp"

/*---- LOCAL FILE ----*/
#include "Map.hpp"
#include "Player.hpp"
#include "Legends.hpp"
#include "Dimension.hpp"


/*---- CONSTRUCTOR ----*/
Legends::Legends():_running(0),_numberPlayers(0) {
    _listener.listen(SERVER_PORT);
    LoadMaps();

}

/*---- DESTRUCTOR ----*/
Legends::~Legends() {
    for (int i=0;i<_socket.length();++i) {
        delete _socket[i];
    }
    _socket.clear();
    for (int i=0;i<_players.length();++i) {
        delete _players[i];
    }
    _players.clear();
}

/*---- INITIALIZE ----*/
// Load all the maps
void Legends::LoadMaps() {
    for (int index=0;index<NUMBER_MAPS;++index) {
        std::cout << "Map loaded : Maps/map"+std::to_string(index+1) << std::endl;
        _maps[index].loadMap(std::string("Maps/map"+std::to_string(index)));
    }
}


/*---- OTHER ----*/
// Main thread that wait for players
void Legends::waitForPlayer() { 
    std::cout << "everything is ok" << std::endl;
    _socket.push_back(new sf::TcpSocket);
    while (_running) {
        if (_listener.accept(*_socket[numberPlayer]) == sf::Socket::Done) {
            if (FIRST_CONNECTION)
            _players.push_back(nuw Player());
            _socket.push_back(new sf::TcpSocket);
        }
    }
}

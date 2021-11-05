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
#include "ClientToServer.hpp"


/*---- CONSTRUCTOR ----*/
Legends::Legends():_running(0),_numberPlayers(0) {
    _listener.listen(SERVER_PORT);
    LoadMaps();

}

/*---- DESTRUCTOR ----*/
Legends::~Legends() {
    for (int i=0;i<_players.length();++i) {
        delete _players[i];
    }
    _players.clear();
        for (int i=0;i<_playersUnloged.length();++i) {
        delete _playersUnloged[i];
    }
    _playersUnloged.clear();
    delete _newPlayer;
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
    _newPlayer = new Player;
    while (_running) {
        if (_listener.accept(*_newPlayer->getSocket()) == sf::Socket::Done) {
            _newPlayer->gotConnection();
            _playersUnloged.push_back(_newPlayer);
            _newPlayer = new Player;
        }
        for (auto & player : _playersUnloged) {
            if (player->receive() == CTS::CONNECTION)
        }
    }
}

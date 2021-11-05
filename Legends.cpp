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
Legends::Legends():_running(0) {
    _listener.listen(SERVER_PORT);
    LoadMaps();

}

/*---- DESTRUCTOR ----*/
Legends::~Legends() {
    //---- DELETE PLAYER
    for (auto & player : _players) {
        delete player;
    }
    _players.clear();
    for (auto & player : _playersUnlogged) {
        delete player;
    }
    _playersUnlogged.clear();
    delete _newPlayer;

    //---- DELETE MAPS
    for (auto & map : _maps) {
        delete map;
    }
}

/*---- INITIALIZE ----*/
// Load all the maps
void Legends::LoadMaps() {
    for (int index=0;index<NUMBER_MAPS;++index) {
        std::cout << "Map loaded : Maps/map"+std::to_string(index+1) << std::endl;
        _maps.push_back(new Map);
        (--end(_maps))->loadMap(std::string("Maps/map"+std::to_string(index)));
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
            _playersUnlogged.push_back(_newPlayer);
            _newPlayer = new Player;
        }
        for (auto it = begin(_playersUnlogged); it != end(_playersUnlogged); ++it) {
            if ((*it)->receive() == CTS::LOGGED) {
                _players.push_back(*it);
                _playersUnlogged.erase(it);
                --it;
            }
        }
    }
}

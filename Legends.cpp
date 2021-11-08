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
Legends::Legends():_running(true) {
    _listener.listen(SERVER_PORT);
    _listener.setBlocking(false);
    _packetReceive.clear();
    loadMaps();
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
void Legends::loadMaps() {
    for (int index=0;index<NUMBER_MAPS;++index) {
        std::cout << "Map loaded : Maps/map"+std::to_string(index+1) << std::endl;
        _maps.push_back(new Map);
        _maps[_maps.size()-1]->loadMap(std::string("Maps/map")+std::to_string(index));
    }
}


/*---- OTHER ----*/
// Main thread that wait for players
void Legends::waitForPlayer() { 
    std::cout << "Waiting for player ..." << std::endl;
    _newPlayer = new Player;
    while (_running) {
        if (_listener.accept(*_newPlayer->getSocket()) == sf::Socket::Done) {
            std::cout << "Connection receive" << std::endl;
            _newPlayer->gotConnection();
            _playersUnlogged.push_back(_newPlayer);
            _newPlayer = new Player;
        }
        for (auto it = begin(_playersUnlogged); it != end(_playersUnlogged); ++it) {
            if ((*it)->receive(_packetReceive) == sf::Socket::Done) {
                CTS::Protocol protocol;
                _packetReceive >> protocol;
                if (protocol == CTS::LOGGED) {
                    CTS::Logged logged;
                    _packetReceive >> logged;
                    if ((it*)->setLogged(logged)) {
                        _players.push_back(*it);
                        _playersUnlogged.erase(it);
                        --it;
                    }
                }

                _packetReceive.clear();
            }
        }
    }
}

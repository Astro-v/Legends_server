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
Legends::Legends():_running(0) {
    _listener.listen(SERVER_PORT);
    LoadMaps();

}

/*---- DESTRUCTOR ----*/
Legends::~Legends() {

}

/*---- INITIALIZE ----*/
// Load all the maps
void Legends::LoadMaps() {
    for (int index=0;index<NUMBER::MAPS;++i) {
        _maps.push_back();
        _maps[index].loadMap(std::string("Maps/map"+std::to_string(index)));
    }
}


/*---- OTHER ----*/
// Main thread that wait for players
void Legends::waitForPlayer() { 
    std::cout << "everything is ok" << std::endl;
}

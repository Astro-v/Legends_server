/*---- LIBRARY ----*/
#include <vector>
#include <fstream>
#include <string>
#include <iostream>

/*---- LIBRARY SFML ----*/
#include "SFML/Network.hpp"

/*---- LOCAL FILE ----*/
#include "Map.hpp"
#include "Tile.hpp"
#include "Dimension.hpp"

/*---- CONSTRUCTOR ----*/
Map::Map():_namePlayer(0),_numberOfNeighbors(0),_posX(0),_posY(0),_posZ(0) {
    for (int index=0;index<NUMBER::TILE;++index) {
        _tile.push_back(Tile(VOID,0));
    }
}

/*---- DESTRUCTOR ----*/
Map::~Map() {

}

/*---- INITIALIZE ----*/
// Load the map
void Map::loadMap(std::string const& path) {
    // Opening the file
    std::ifstream file(path);
    if(file) {
        // Everything is ok for reading
        std::string line;
        while(std::getline(file, line)) {
            if (std::stoi(line[0]) == LOAD::POS_MAP) {
                _posX = (sf::Uint32)std::stoi(line[2]);
                _posY = (sf::Uint32)std::stoi(line[4]);
                _posZ = (sf::Uint32)std::stoi(line[6]);
            } else if (std::stoi(line[0]) == LOAD::POS_NEIGHBORS) {
                ++_numberOfNeighbors;
                _posXNeighbors.push_back((sf::Uint32)std::stoi(line[2]));
                _posYNeighbors.push_back((sf::Uint32)std::stoi(line[4]));
                _posZNeighbors.push_back((sf::Uint32)std::stoi(line[6]));
            } else if std::stoi(line[0]) == LOAD::TILE) {
                for (int index=2;index<line.length();index+=2) {
                    _tile[(index-2)/2] = Tile((sf::Uint32)std::stoi(line[index]),0);
                }
            }
        }
    } else {
        std::cout << "ERROR: Impossible to open the file " << path << std::endl;
    }
} 

/*---- COMMUNICATION ----*/
void Map::receive() {

}

// Add the player and send to this player the data about the map
//void Map::addPlayer(Player& player) {

}

// Move a player to another map
void Map::changeMap(const int& index) {

}  

/*---- ACCESSOR ----*/
int Map::getNumberPlayer() const {
    return _numberPlayers;
}

/*Player& Map::getPlayer(const int& index) {
    return _players[index];
}*/


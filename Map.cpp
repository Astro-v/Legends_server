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
#include "Header.hpp"

/*---- CONSTRUCTOR ----*/
Map::Map():_numberPlayers(0),_numberOfNeighbors(0),_posX(0),_posY(0),_posZ(0) {

}

/*---- DESTRUCTOR ----*/
Map::~Map() {

}

/*---- INITIALIZE ----*/
// Load the map
void Map::loadMap(std::string const& path) {
    // Opening the file
    std::ifstream file(path);
    if (file) {
        // Everything is ok for reading
        std::string line;
        int it = 0;
        while (std::getline(file, line)) {
            if (ctoi(line[0]) == (int)LOAD::POS_MAP) {
                _posX = ctoi(line[2]);
                _posY = ctoi(line[4]);
                _posZ = ctoi(line[6]);
            } else if (ctoi(line[0]) == (int)LOAD::POS_NEIGHBORS) {
                ++_numberOfNeighbors;
                _posXNeighbors.push_back(ctoi(line[2]));
                _posYNeighbors.push_back(ctoi(line[4]));
                _posZNeighbors.push_back(ctoi(line[6]));
            } else if (ctoi(line[0]) == (int)LOAD::TILE) {
                for (int index=0;index<NUMBER_TILE_Y;++index) {
                    _tile[it][index].setVal(ctoi(line[2*index+2]));
                }
                ++it; 
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
void Map::addPlayer(Player& player) {

}

// Move a player to another map
void Map::changeMap(const int& index) {

}  

/*---- ACCESSOR ----*/
int Map::getNumberPlayer() const {
    return _numberPlayers;
}

Player& Map::getPlayer(const int& index) {
    return _players[index];
}


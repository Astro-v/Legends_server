#ifndef __MAP__
#define __MAP__

/*---- LIBRARY ----*/
#include <vector>
#include <string>

/*---- LIBRARY SFML ----*/
#include "SFML/Network.hpp"

/*---- LOCAL FILE ----*/
#include "Tile.hpp"

class Map {
    public:
    /*---- CONSTRUCTOR ----*/
    Map();

    /*---- DESTRUCTOR ----*/
    ~Map();

    /*---- INITIALIZE ----*/
    void loadMap(std::string const& path);   // Load the map

    /*---- COMMUNICATION ----*/
    void receive();
    //void addPlayer(Player& player);    // Add the player and send to this player the data about the map
    void changeMap(const int& index);  // Move a player to another map

    /*---- ACCESSOR ----*/
    int getNumberPlayer() const;
    //Player& getPlayer(const int& index);

    protected:
    
    private:
    //std::vector<Player &> _players;          // List all player on the map
    int _numberPlayers;                      // Number of player on the map
    std::vector<TILE> _tile;                 // Table of all tiles

    std::vector<Map &>  _neighbors;          // References over the neighbors map

    sf::Uint32 _posX;                        // Position of the map
    sf::Uint32 _posY;                        // Position of the map
    sf::Uint32 _posZ;                        // Altitude of the map (<0 for underground maps)

    std::vector<sf::Uint32> _posXNeighbors;  // Position of the neighbors map
    std::vector<sf::Uint32> _posYNeighbors;  // Position of the neighbors map
    std::vector<sf::Uint32> _posZNeighbors;  // Altitude of the neighbors map

    int _numberOfNeighbors;                   // Number of Neighbors
}

namespace LOAD { // For loading the map
    /*
    0: Pos of the map
    1: Pos of the Neighbors
    2: List of tiles
    */
    enum Map {
        POS_MAP, POS_NEIGHBORS, TILE
    }
}


#endif // __MAP__
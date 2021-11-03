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
    void addPlayer(Player* player);    // Add the player and send to this player the data about the map

    protected:
    
    private:
    std::vector<Player *> _players;          // List all player on the map
    int _numberPlayers;                      // Number of player on the map
    std::vector<TILE> _tile;                 // Table of all tiles

    std::vector<Map *>  _neighboor;          //

    sf::Uint32 _posX;                        // Position of the map
    sf::Uint32 _posY;                        // Position of the map
    sf::Uint32 _posZ;                        // Altitude of the map (<0 for underground maps)
}

#endif // __MAP__
#ifndef __MAP__
#define __MAP__

/*---- LIBRARY ----*/
#include <vector>
#include <string>

/*---- LIBRARY SFML ----*/

/*---- LOCAL FILE ----*/
#include "Tile.hpp"

class Map {
    public:
    /*---- CONSTRUCTOR ----*/
    Map();

    /*---- DESTRUCTOR ----*/
    ~Map();

    /*---- INITIALIZE ----*/
    void loadMap(std::string const& path);  // Load the map

    protected:
    
    private:
    std::vector<*Player> _listPlayer;       // List all player on the map
    int _numberPlayer;                      // Number of player on the map
    std::vector<TILE> _tile;                // Table of all tiles

    int _posX;                              // Position of the map
    int _posY;                              // Position of the map
    int _posZ;                              // Altitude of the map (<0 for underground maps)
}

#endif // __MAP__
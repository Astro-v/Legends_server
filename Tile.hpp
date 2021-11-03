#ifndef __TILE__
#define __TILE__

/*---- LIBRARY ----*/

/*---- LIBRARY SFML ----*/
#include "SFML/Network.hpp"

/*---- LOCAL FILE ----*/

#define CROSSABLE 10000             // if _val<10000 the tile is crossable
#define VOID 0                      // void tile (uncrossable)

class Tile {
    public:
    /*---- CONSTRUCTOR ----*/
    Tile(sf::Uint32 val, sf::Uint32 subspace);

    /*---- DESTRUCTOR ----*/
    ~Tile();

    /*---- ACCESSOR ----*/
    bool getCrossable();           // Return the crossability of the tile

    protected:

    private:
    sf::Uint32 _val;               // Value for the tile (0:Nothing)    
    bool _crossable;               // True if it's crossable
    sf::Uint32 _subspace;          // number of the corresponding subspace. All the tile with the same subspace value can be reach
};

/*
0: void
1: grassFull
2: sandFull
*/

#endif // __TILE__
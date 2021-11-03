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
    Tile();
    Tile(int val, int subspace);

    /*---- DESTRUCTOR ----*/
    ~Tile();

    /*---- ACCESSOR ----*/
    bool getCrossable();           // Return the crossability of the tile
    void setVal(int val);

    protected:

    private:
    int _val;               // Value for the tile (0:Nothing)    
    bool _crossable;               // True if it's crossable
    int _subspace;          // number of the corresponding subspace. All the tile with the same subspace value can be reach
};

/*
0: void
1: grassFull
2: sandFull
*/

#endif // __TILE__
#ifndef __TILE__
#define __TILE__

/*---- LIBRARY ----*/

/*---- LIBRARY SFML ----*/

/*---- LOCAL FILE ----*/

#define CROSSABLE 10000             // if _val<1000 the tile is crossable

class Tile {
    public:
    /*---- CONSTRUCTOR ----*/
    Tile(int val);

    /*---- DESTRUCTOR ----*/
    ~Tile();

    /*---- ACCESSOR ----*/
    bool getCrossable();           // Return the crissability of the tile

    protected:

    private:
    sf::Uint32 _val;               // Value for the tile (0:Nothing)    
    bool _crossable;               // True if it's crossable
    sf::Uint32 _subspace;          // number of the corresponding subspace. All the tile with the same subspace value can be reach
};

#endif // __TILE__
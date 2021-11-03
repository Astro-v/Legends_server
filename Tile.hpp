#ifndef __TILE__
#define __TILE__

/*---- LIBRARY ----*/

/*---- LIBRARY SFML ----*/


/*---- LOCAL FILE ----*/

class Tile {
    public:
    /*---- CONSTRUCTOR ----*/
    Map();

    /*---- DESTRUCTOR ----*/
    ~Map();

    /*---- ACCESSOR ----*/
    bool getCrossable();    // Return True if the object if crossable

    protected:

    private:
    sf::Uint32 _val;               // Value for the tile (0:Nothing)    
};

#endif // __TILE__
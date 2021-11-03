/*---- LIBRARY ----*/

/*---- LIBRARY SFML ----*/
#include "SFML/Network.hpp"

/*---- LOCAL FILE ----*/
#include "Tile.hpp"

/*---- CONSTRUCTOR ----*/
Tile::Tile(sf::Uint32 val, sf::Uint32 subspace):_val(val),_subspace(subspace) {
    if (_val < CROSSABLE && _val != VOID) {
        _crossable = true;
    } else {
        _crossable = false;
    }
}

/*---- DESTRUCTOR ----*/
Tile::~Tile() {

}

/*---- ACCESSOR ----*/
// Return the crossability of the tile
bool Tile::getCrossable() {
    return _crossable;
}
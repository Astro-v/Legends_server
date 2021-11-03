/*---- LIBRARY ----*/

/*---- LIBRARY SFML ----*/
#include "SFML/Network.hpp"

/*---- LOCAL FILE ----*/
#include "Tile.hpp"

/*---- CONSTRUCTOR ----*/
Tile::Tile():_val(VOID),_subspace(0) {
    _crossable = false;
}

Tile::Tile(int val, int subspace):_val(val),_subspace(subspace) {
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

void Tile::setVal(int val) {
    _val = val;
    if (_val < CROSSABLE && _val != VOID) {
        _crossable = true;
    } else {
        _crossable = false;
    }
}
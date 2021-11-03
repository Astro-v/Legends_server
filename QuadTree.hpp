#ifndef __QUAD_TREE__
#define __QUAD_TREE__

/*---- LIBRARY ----*/
#include <vector>

/*---- LIBRARY SFML ----*/
#include "SFML/System.hpp"

/*---- LOCAL FILE ----*/
#include "Map.hpp"
#include "Score.hpp"

class QuadTree {
    public:
    /*---- CONSTRUCTOR ----*/
    QuadTree();

    /*---- DESTRUCTOR ----*/
    ~QuadTree();

    /*---- OTHER ----*/
    void routine();                    // Routine of the tree

    protected:
    /*---- ACCESSOR ----*/
    void updateScore();                // Update the score
    void updateTree();                 // Update the score and then the tree if _score > SCORE::LIMIT

    private:
    bool _leaf;                        // True if it's a leaf
    QuadTree* _child[2];               // Pointer on child (0 if its a leaf)
    std::vector<*Map> _map;            // Pointer on all maps in that QuadTree

    /*---- THREAD ----*/
    sf::Mutex _mutex;           
    sf::Thread _thread;                // Thread on routine

    /*---- SCORE ----*/
    SCORE::Score _score;
}

#endif // __QUAD_TREE__
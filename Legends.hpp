#ifndef __LEGENDS__
#define __LEGENDS__

/*---- LIBRARY ----*/
#include <vector>

/*---- LIBRARY SFML ----*/

/*---- LOCAL FILE ----*/
#include "Map.hpp"
#include "Player.hpp"

class Legends {
    public:
    /*---- CONSTRUCTOR ----*/
    Legends();

    /*---- DESTRUCTOR ----*/
    ~Legends();

    /*---- OTHER ----*/
    void run();                         // Main thread that coordonate everything

    protected:

    private:
    std::vector<Map> _maps;             // All maps in the 
    std::vector<Player> _players;       // All the players

    /*---- THREAD ----*/
    sf::Mutex _mutex;
}

#endif // __LEGENDS__
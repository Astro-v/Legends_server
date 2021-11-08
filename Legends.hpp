#ifndef __LEGENDS__
#define __LEGENDS__

/*---- LIBRARY ----*/
#include <vector>

/*---- LIBRARY SFML ----*/
#include "SFML/Network.hpp"

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
    void waitForPlayer();                         // Main thread that wait for players

    protected:
    /*---- INITIALIZE ----*/
    void loadMaps();                              // Load all the maps

    private:

    /*---- COMMUNICATION ----*/
    sf::TcpListener _listener;
    sf::Packet _packetReceive;

    bool _running;

    std::vector<Map *> _maps;                  // All maps
    std::vector<Player *> _playersUnlogged;    // All the unloged players
    std::vector<Player *> _players;            // All the loged players
    Player *_newPlayer;                        // Waiting for new player

    /*---- THREAD ----*/
    sf::Mutex _mutex;
};

#endif // __LEGENDS__
#include <vector>
#include <iostream>
#include <unordered_set>
#include <algorithm>
#include "Cards.h"
#include "Player.h"
#include "Deck.h"
#include "HandIdentification.h"


class Simulation {
    public:
        Simulation();
        float runSimulation(int numSimulations);
    private:
        std::vector<Player> players;
        Deck mainDeck;
};
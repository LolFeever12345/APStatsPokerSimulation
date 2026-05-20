#include "Cards.h"
#include "Deck.h"
#include "Player.h"
#ifndef SIMULATION_H
#define SIMULATION_H

class Simulation {
    public:
        Simulation();
        void runSimulation();
        
    private:
        Deck deck;
        Player players[9]; // Assuming a maximum of 9 players in the simulation
};

#endif // SIMULATION_H
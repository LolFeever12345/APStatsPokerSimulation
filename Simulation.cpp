#include "Simulation.h"

Simulation::Simulation() {
    for(int i = 0; i < 9; i++) {
        players[i] = Player();
    }
}

void Simulation::runSimulation() {
    deck.shuffleDeck();
    
    // Deal two cards to each player
    for(int i = 0; i < 9; i++) {
        players[i].receiveCard(deck.drawCard());
        players[i].receiveCard(deck.drawCard());
    }

    
    
    // Show each player's hand
    for(int i = 0; i < 9; i++) {
        std::cout << "Player " << (i + 1) << "'s hand:" << std::endl;
        players[i].showHand();
        std::cout << std::endl;
    }
}
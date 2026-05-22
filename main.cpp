#include <vector>
#include <iostream>
#include <unordered_set>
#include <algorithm>
#include "Cards.h"
#include "Player.h"
#include "Deck.h"
#include "HandIdentification.h"
#include "Simulation.h"


int main() {
    Simulation sim;
    std::cout << sim.runSimulation(100000) << std::endl;
    // Deck deck;
    // // deck.shuffleDeck();
    // Card t1 = deck.dealCard(Card("Hearts", 6));
    // Card t2 = deck.dealCard(Card("Spades", 1));
    // t1.displayCard();
    // t2.displayCard();
    // for(int i = 0; i < 52; i++) {
    //     Card card = deck.drawCard();
    //     card.displayCard();
    // }
    // std::cout<<deck.deck.size()<<std::endl; // Should be 0 after drawing all cards
}
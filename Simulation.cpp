#include <vector>
#include <iostream>
#include <unordered_set>
#include <algorithm>
#include "Cards.h"
#include "Player.h"
#include "Deck.h"
#include "HandIdentification.h"
#include "Simulation.h"

Simulation::Simulation() {
    // Constructor logic if needed
    for(int i = 0; i < 8; i++) {
        players.push_back(Player());
    }
    Deck mainDeck = Deck();
}

float Simulation::runSimulation(int numSimulations) {
    int player1Wins = 0;

    for (int sim = 0; sim < numSimulations; sim++) {
        for(Player& player : players) {
            player.emptyHand(); // Clear player's hand for the new simulation
        }
        mainDeck.refill();
        mainDeck.shuffleDeck();

        Card communityCards[5];
        for (int i = 0; i < 5; i++) {
            communityCards[i] = mainDeck.drawCard();
        }

        players[0].receiveCard(mainDeck.dealCard(Card("Hearts", 6)));
        players[0].receiveCard(mainDeck.dealCard(Card("Spades", 1)));

        for(int i = 1; i < 8; i++) {
            players[i].receiveCard(mainDeck.drawCard());
            players[i].receiveCard(mainDeck.drawCard());
        }

        int bestHandStrength = 0;
        int winningPlayerIndex = -1;
        for (int j = 0; j < 5; j++) {
            std::cout << "Community Card " << j + 1 << ": ";
            communityCards[j].displayCard();
        }

        for (size_t i = 0; i < players.size(); i++) {
            int handStrength = HandIdentification::identifyHand(players[i], communityCards);
            for(int j = 0; j < 2; j++) {
                std::cout << "Player " << i << " Hand Card " << j << ": ";
                players[i].hand[j].displayCard();
            }
            if (handStrength > bestHandStrength) {
                bestHandStrength = handStrength;
                winningPlayerIndex = i;
            }
        }

        if (winningPlayerIndex == 0) {
            player1Wins++;
        }
        std::cout << "Winning Player: " << winningPlayerIndex << " with hand strength: " << bestHandStrength << std::endl;
        std::cout << "-----------------------------" << std::endl;
    }

    return static_cast<float>(player1Wins) / numSimulations;
}


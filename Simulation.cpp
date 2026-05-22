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
    Deck mainDeck = Deck();
    for(int i = 0; i < 2; i++) {
        players.push_back(Player());
    }
}

float Simulation::runSimulation(int numSimulations) {
    int player1Wins = 0;

    for (int sim = 0; sim < numSimulations; sim++) {
        int bestHandStrength = 0;
        for (Player& player : players) {
            player.emptyHand();
        }
        mainDeck.refill();
        mainDeck.shuffleDeck();

        players[0].receiveCard(mainDeck.dealCard(Card("Hearts", 6)));
        players[0].receiveCard(mainDeck.dealCard(Card("Spades", 1)));

        for(int i = 1; i < 2; i++) {
            players[i].receiveCard(mainDeck.drawCard());
            players[i].receiveCard(mainDeck.drawCard());
        }

        Card communityCards[5];
        mainDeck.Burn(); // Burn the first card
        for (int i = 0; i < 3; i++) {
            communityCards[i] = mainDeck.drawCard();
        }

        mainDeck.Burn(); // Burn the first card
        communityCards[3] = mainDeck.drawCard();
        mainDeck.Burn(); // Burn the second card
        communityCards[4] = mainDeck.drawCard();

        int winningPlayerIndex = -1;
        // for (int j = 0; j < 5; j++) {
        //     std::cout << "Community Card " << j + 1 << ": ";
        //     communityCards[j].displayCard();
        // }

        // std::cout << "-----------------------------" << std::endl;

        for (size_t i = 0; i < players.size(); i++) {
            int handStrength = HandIdentification::identifyHand(players[i], communityCards);
            // for(int j = 0; j < 2; j++) {
            //     std::cout << "Player " << i << " Hand Card " << j << ": ";
            //     players[i].hand[j].displayCard();
            // }
            // std::cout << "Hand Strength: " << handStrength << std::endl;
            // std::cout << "-----------------------------" << std::endl;
            if (handStrength > bestHandStrength) {
                bestHandStrength = handStrength;
                winningPlayerIndex = i;
            }
        }

        if (winningPlayerIndex == 0) {
            player1Wins++;
        }
        // std::cout << "Winning Player: " << winningPlayerIndex << " with hand strength: " << bestHandStrength << std::endl;
        // std::cout << "-----------------------------" << std::endl;
    }

    return static_cast<float>(player1Wins) / numSimulations;
}


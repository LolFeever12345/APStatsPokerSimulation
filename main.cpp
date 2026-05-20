#include <vector>
#include <iostream>
#include <unordered_set>
#include <algorithm>
#include "Cards.h"
#include "Player.h"
#include "Deck.h"
#include "Simulation.h"
#include "HandIdentification.h"


int main() {
    Player player1;
    Player player2;
    Player player3;
    Player player4;
    Player player5;
    Player player6;
    Player player7;
    Player player8;

    player1.setHand(Card("Hearts", 7), Card("Spades", 2));

    Card communityCards[5] = {
        Card("Hearts", 7),
        Card("Diamonds", 7),
        Card("Clubs", 7),
        Card("Spades", 3),
        Card("Hearts", 2)
    };

    int handStrength = HandIdentification::identifyHand(player1, communityCards);
    std::cout << "Player 1's hand strength: " << handStrength << std::endl;
}
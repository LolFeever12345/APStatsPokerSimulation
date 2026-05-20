#include <vector>
#include <iostream>
#include <unordered_set>
#include <algorithm>
#include "Cards.h"
#include "Player.h"
#include "Deck.h"
#include "HandIdentification.h"


int main() {
    Player playerList[8];
    Deck mainDeck = Deck();

    mainDeck.shuffleDeck();

    Card communityCards[5] = {
        mainDeck.drawCard(),
        mainDeck.drawCard(),
        mainDeck.drawCard(),
        mainDeck.drawCard(),
        mainDeck.drawCard()
    };

    playerList[0].receiveCard(mainDeck.dealCard(Card("Hearts", 6)));
    playerList[0].receiveCard(mainDeck.dealCard(Card("Spades", 1)));

    for(int i = 1; i < 8; i++) {
        playerList[i].receiveCard(mainDeck.drawCard());
        playerList[i].receiveCard(mainDeck.drawCard());
    }

    for(int j = 0; j < 5; j++) {
        communityCards[j].displayCard();
    }

    for(int i = 0; i < 8; i++) {
        int handStrength = HandIdentification::identifyHand(playerList[i], communityCards);
        std::cout << "Player " << i + 1 << " has hand strength: " << handStrength << std::endl;
        std::cout << "Player " << i + 1 << "'s hand: ";
        playerList[i].hand[0].displayCard();
        playerList[i].hand[1].displayCard();
    }


}
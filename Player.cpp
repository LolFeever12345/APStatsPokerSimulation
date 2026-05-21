#include "Player.h"
#include "Cards.h"



void Player::receiveCard(const Card& card) {
    // Add the received card to the player's hand
    if (hand[0].getSuit() == "") {
        hand[0] = card; // Place card in the first slot if it's empty
    } else if (hand[1].getSuit() == "") {
        hand[1] = card; // Place card in the second slot if it's empty
    } else {
        std::cout << "Hand is full! Cannot receive more cards." << std::endl;
    }
}

void Player::setHand(const Card& card1, const Card& card2) {
    hand[0] = card1;
    hand[1] = card2;
}

void Player::emptyHand() {
    hand[0] = Card(); // Reset to default card (empty)
    hand[1] = Card(); // Reset to default card (empty)
}


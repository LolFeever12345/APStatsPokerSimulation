#include "Player.h"
#include <Cards.h>

Player::Player() {
    // Initialize hand with default cards (could be empty or a placeholder)
    hand[0] = Card();
    hand[1] = Card();
}

Player::~Player() {
    // Destructor logic if needed (not necessary in this case since we are not dynamically allocating memory)
}

void Player::receiveCard(const Card& card) {
    // Add the received card to the player's hand
    if (hand[0].getSuit() == "" && hand[0].getRank() == "") {
        hand[0] = card; // Place card in the first slot if it's empty
    } else if (hand[1].getSuit() == "" && hand[1].getRank() == "") {
        hand[1] = card; // Place card in the second slot if it's empty
    } else {
        std::cout << "Hand is full! Cannot receive more cards." << std::endl;
    }
}
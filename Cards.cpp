#include "Cards.h"

Card::Card(std::string suit, std::string rank) {
    this->suit = suit;
    this->rank = rank;
}

std::string Card::getSuit() const {
    return suit;
}

std::string Card::getRank() const {
    return rank;
}

void Card::displayCard() const {
    std::cout << rank << " of " << suit << std::endl;
}
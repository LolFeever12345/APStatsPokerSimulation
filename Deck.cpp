#include "Deck.h"
#include "Cards.h"
#include <vector>
#include <algorithm>
#include <random>

Deck::Deck() {
    std::string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    int ranks[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    
    int index = 0;
    for (const auto& suit : suits) {
        for (const auto& rank : ranks) {
            deck.push_back(Card(suit, rank));
        }
    }
}

void Deck::shuffleDeck() {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::shuffle(deck.begin(), deck.end(), gen);
}

Card Deck::drawCard() {
    Card card = deck.back();
    deck.pop_back();
    return card;
}

Card Deck::dealCard(Card hand) {
    removeCard(hand);
    return hand;
}

void Deck::removeCard(Card card) {
    deck.erase(std::remove(deck.begin(), deck.end(), card), deck.end());
}

void Deck::refill() {
    deck.clear();
    std::string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    int ranks[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    
    for (const auto& suit : suits) {
        for (const auto& rank : ranks) {
            deck.push_back(Card(suit, rank));
        }
    }
}

void Deck::Burn() {
    if (!deck.empty()) {
        deck.pop_back();
    }
}
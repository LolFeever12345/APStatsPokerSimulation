#include "Deck.h"
#include "Cards.h"

Deck::Deck() {
    std::string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    int ranks[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    
    int index = 0;
    for (const auto& suit : suits) {
        for (const auto& rank : ranks) {
            deck[index] = Card(suit, rank);
            index++;
        }
    }
}

void Deck::shuffleDeck() {
    for (int i = 0; i < 52; i++) {
        int randomIndex = rand() % 52;
        std::swap(deck[i], deck[randomIndex]);
    }
    topCardIndex = 0;
}

Card Deck::drawCard() {
    return deck[topCardIndex++];
}
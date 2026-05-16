#include "Deck.h"
#include "Cards.h"

Deck::Deck() {
    std::string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    std::string ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
    
    int index = 0;
    for (const auto& suit : suits) {
        for (const auto& rank : ranks) {
            deck[index] = Card(suit, rank);
            index++;
        }
    }
}
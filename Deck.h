#include "Cards.h"
#include <vector>
#ifndef DECK_H
#define DECK_H

class Deck {
    public:
        Deck();
        void shuffleDeck();
        Card drawCard();
        Card dealCard(Card hand);
        void removeCard(Card card);
    private:
        std::vector<Card> deck;
};

#endif // DECK_H
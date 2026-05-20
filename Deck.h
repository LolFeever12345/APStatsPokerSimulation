#include "Cards.h"
#ifndef DECK_H
#define DECK_H

class Deck {
    public:
        Deck();
        void shuffleDeck();
        Card drawCard();
    private:
        Card deck[52];
        int topCardIndex;
};

#endif // DECK_H
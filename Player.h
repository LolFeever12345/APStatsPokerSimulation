#include "Cards.h"
#ifndef PLAYER_H
#define PLAYER_H

class Player {
    public:
        void receiveCard(const Card& card);
        void setHand(const Card& card1, const Card& card2);
        Card hand[2];
};

#endif // PLAYER_H
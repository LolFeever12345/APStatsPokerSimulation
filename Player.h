#include "Cards.h"

class Player {
    public:
        Player();
        ~Player();
        void receiveCard(const Card& card);
        void showHand() const;
        Card hand[2];
};
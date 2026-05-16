#include "Cards.h"

class Player {
    public:
        Player();
        ~Player();
        void receiveCard(const Card& card);
        void showHand() const;
    private:
        Card hand[2];
};
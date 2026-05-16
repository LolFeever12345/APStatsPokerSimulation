#include <Player.h>
#include <Cards.h>
#include <vector>
#ifndef HANDIDENTIFICATION_H
#define HANDIDENTIFICATION_H

class HandIdentification {
    public:
        static int identifyHand(const Player& player, const Card communityCards[5]);
        static bool isStraightFlush(const Card comhand[7]);
        static bool isFlush(const Card comhand[7]);
        static bool isStraight(const Card comhand[7]);
        static bool isFourOfAKind(const Card comhand[7]);
        static bool isFullHouse(const Card comhand[7]);
        static bool isThreeOfAKind(const Card comhand[7]);
        static bool isTwoPair(const Card comhand[7]);
        static bool isOnePair(const Card comhand[7]);
        static std::vector<Card> useComCards;

};

#endif // HANDIDENTIFICATION_H
#include <HandIdentification.h>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <algorithm>

int HandIdentification::identifyHand(const Player& player, const Card communityCards[5]) {
    Card comhand[7];
    int handstr;
    int highcard = 0;
    int output;
    // Combine player's hand and community cards into a single array
    for (int i = 0; i < 2; i++) {
        comhand[i] = player.hand[i];
    }
    for (int i = 0; i < 5; i++) {
        comhand[i + 2] = communityCards[i];
    }

    if(isStraightFlush(comhand)) {
        handstr = 9;
    } else {
        useComCards.clear();
        if(isFourOfAKind(comhand)) {
            handstr = 8;
        } else {
            useComCards.clear();
            if(isFullHouse(comhand)) {
                handstr = 7;
            } else {
                useComCards.clear();
                if(isFlush(comhand)) {
                    handstr = 6;
                } else {
                    useComCards.clear();
                    if(isStraight(comhand)) {
                        handstr = 5;
                    } else {
                        useComCards.clear();
                        if(isThreeOfAKind(comhand)) {
                            handstr = 4;
                        } else {
                            useComCards.clear();
                            if(isTwoPair(comhand)) {
                                handstr = 3;
                            } else {
                                useComCards.clear();
                                if(isOnePair(comhand)) {
                                    handstr = 2;
                                } else {
                                    handstr = 1; // High card
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    if(handstr == 7){
        std::vector<Card> ThreeOfAKind;
        std::vector<Card> Pair;

        for(int i = 0; i < 3; i++) {
            ThreeOfAKind.push_back(useComCards[i]);
        }
        for(int i = 3; i < 5; i++) {
            Pair.push_back(useComCards[i]);
        }
        output = handstr*10000 + ThreeOfAKind[0].getRank()*200 + Pair[0].getRank();
    }else{
        for(Card card : useComCards) {
            if(card.getRank() > highcard) {
                highcard = card.getRank();
            }
        }
        output = handstr*10000 + highcard*200;
    }

    return output;
};

bool HandIdentification::isStraightFlush(const Card comhand[7]) {
    if(isFlush(comhand) && isStraight(comhand)) {
        for(int i = 0; i < 5; i++) {
            if(useComCards[i].getSuit() != useComCards[i+5].getSuit() || useComCards[i].getRank() != useComCards[i+5].getRank()) {
                return false; // Not a straight flush if suits or ranks don't match
            }
        }
        return true; // Found a straight flush
    }
    return false; // Placeholder return value
}

bool HandIdentification::isFlush(const Card comhand[7]) {
    std::vector<Card> usedCards;
    for(int i = 0; i < 7; i++) {
        for(int j = i + 1; j < 7; j++) {
            if(comhand[i].getSuit() == comhand[j].getSuit()) {
                for(int k = j + 1; k < 7; k++) {
                    if(comhand[j].getSuit() == comhand[k].getSuit()) {
                        for(int l = k + 1; l < 7; l++) {
                            if(comhand[k].getSuit() == comhand[l].getSuit()) {
                                for(int m = l + 1; m < 7; m++) {
                                    if(comhand[l].getSuit() == comhand[m].getSuit()) {
                                        useComCards.push_back(comhand[i]);
                                        useComCards.push_back(comhand[j]);
                                        useComCards.push_back(comhand[k]);
                                        useComCards.push_back(comhand[l]);
                                        useComCards.push_back(comhand[m]);
                                        
                                        std::string flushSuit = useComCards[useComCards.size() - 1].getSuit();
                                        for(int i = 0; i < 7; i++) {
                                            if(comhand[i].getSuit() == flushSuit) {
                                                usedCards.push_back(comhand[i]);
                                            }
                                        }
                                        if(usedCards.size() == 5) {
                                            return true; // Found a flush
                                        }else if (usedCards.size() < 5) {
                                            return false;
                                        }

                                        std::vector<Card> sortedCards = usedCards;

                                        std::sort(sortedCards.begin(), sortedCards.end(),
                                                [](const Card& a, const Card& b) {
                                                    return a.getRank() > b.getRank(); // descending
                                                });
                                        
                                        

                                        return true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    

    return false; // Placeholder return value
}

bool HandIdentification::isStraight(const Card comhand[7]) {
    for(int i = 0; i < 7; i++) {
        for(int j = i + 1; j < 7; j++) {
            if(comhand[i].getRank() == comhand[j].getRank() + 1) {
                for(int k = j + 1; k < 7; k++) {
                    if(comhand[j].getRank() == comhand[k].getRank() + 1) {
                        for(int l = k + 1; l < 7; l++) {
                            if(comhand[k].getRank() == comhand[l].getRank() + 1) {
                                for(int m = l + 1; m < 7; m++) {
                                    if(comhand[l].getRank() == comhand[m].getRank() + 1) {
                                        useComCards.push_back(comhand[i]);
                                        useComCards.push_back(comhand[j]);
                                        useComCards.push_back(comhand[k]);
                                        useComCards.push_back(comhand[l]);
                                        useComCards.push_back(comhand[m]);
                                        return true; // Found a straight
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return false; // Placeholder return value
}

bool HandIdentification::isFourOfAKind(const Card comhand[7]) {
    for(int i = 0; i < 7; i++) {
        for(int j = i + 1; j < 7; j++) {
            if(comhand[i].getRank() == comhand[j].getRank()) {
                for(int k = j + 1; k < 7; k++) {
                    if(comhand[j].getRank() == comhand[k].getRank()) {
                        for(int l = k + 1; l < 7; l++) {
                            if(comhand[k].getRank() == comhand[l].getRank()) {
                                useComCards.push_back(comhand[i]);
                                useComCards.push_back(comhand[j]);
                                useComCards.push_back(comhand[k]);
                                useComCards.push_back(comhand[l]);
                                return true; // Found four of a kind
                            }
                        }
                    }
                }
            }
        }
    }
    return false; // Placeholder return value
}

bool HandIdentification::isFullHouse(const Card comhand[7]) {
    std::vector<Card> usedCards;
    if(isThreeOfAKind(comhand) && isTwoPair(comhand)) {
        for(Card card : useComCards) {
            bool counted = false;
            for(Card usedCard : usedCards) {
                if(card.getRank() == usedCard.getRank() && card.getSuit() == usedCard.getSuit()) {
                    counted = true;
                    break;
                }
            }
            if(!counted) {
                usedCards.push_back(card);
            }
        }
        useComCards = usedCards; // Update useComCards with the cards that form the full house
        return true; // Found a full house
    }
    return false; // Placeholder return value
}

bool HandIdentification::isThreeOfAKind(const Card comhand[7]) {
    for(int i = 0; i < 7; i++) {
        for(int j = i + 1; j < 7; j++) {
            if(comhand[i].getRank() == comhand[j].getRank()) {
                for(int k = j + 1; k < 7; k++) {
                    if(comhand[j].getRank() == comhand[k].getRank()) {
                        useComCards.push_back(comhand[i]);
                        useComCards.push_back(comhand[j]);
                        useComCards.push_back(comhand[k]);
                        return true; // Found three of a kind
                    }
                }
            }
        }
    }
    return false; // Placeholder return value
}

bool HandIdentification::isTwoPair(const Card comhand[7]) {
    for (int i = 0; i < 7; i++) {
        for (int j = i + 1; j < 7; j++) {
            if (comhand[i].getRank() == comhand[j].getRank()) {
                for (int k = j + 1; k < 7; k++) {
                    for (int l = k + 1; l < 7; l++) {
                        if (comhand[k].getRank() == comhand[l].getRank() && comhand[k].getRank() != comhand[i].getRank()) {
                            useComCards.push_back(comhand[i]);
                            useComCards.push_back(comhand[j]);
                            useComCards.push_back(comhand[k]);
                            useComCards.push_back(comhand[l]);
                            return true; // Found two pairs
                        }
                    }
                }
            }
        }
    }
    return false; // Placeholder return value
}

bool HandIdentification::isOnePair(const Card comhand[7]) {
    for (int i = 0; i < 7; i++) {
        for (int j = i + 1; j < 7; j++) {
            if (comhand[i].getRank() == comhand[j].getRank()) {
                useComCards.push_back(comhand[i]);
                useComCards.push_back(comhand[j]);
                return true; // Found a pair
            }
        }
    }
    return false; // Placeholder return value
}

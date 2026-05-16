#include <HandIdentification.h>
#include <vector>
#include <iostream>
#include <unordered_set>

int HandIdentification::identifyHand(const Player& player, const Card communityCards[5]) {
    Card comhand[7];
    int handstr;
    int highcard;
    // Combine player's hand and community cards into a single array
    for (int i = 0; i < 2; i++) {
        comhand[i] = player.hand[i];
    }
    for (int i = 0; i < 5; i++) {
        comhand[i + 2] = communityCards[i];
    }

    for (int i = 0; i < 7; i++) {
        comhand[i].displayCard();
    }

    return handstr*highcard;
};

bool HandIdentification::isFlush(const Card comhand[7]) {
    for(int i = 0; i < 7; i++) {
        for(int j = i + 1; j < 7; j++) {
            if(comhand[i].getSuit() == comhand[j].getSuit()) {
                for(int k = j + 1; k < 7; k++) {
                    if(comhand[j].getSuit() == comhand[k].getSuit()) {
                        for(int l = k + 1; l < 7; l++) {
                            if(comhand[k].getSuit() == comhand[l].getSuit()) {
                                for(int m = l + 1; m < 7; m++) {
                                    if(comhand[l].getSuit() == comhand[m].getSuit()) {
                                        return true; // Found a flush
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
            for(Card usedCard : usedCards) {
                if(card.getRank() == usedCard.getRank() && card.getSuit() == usedCard.getSuit()) {
                    usedCards.push_back(card);
                }
            }
        }
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

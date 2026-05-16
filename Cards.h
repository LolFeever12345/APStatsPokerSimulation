#include <iostream>
#include <string>

#ifndef CARDS_H
#define CARDS_H

class Card {
    public:
        Card();
        Card(std::string suit, int rank);
        std::string getSuit() const;
        int getRank() const;
        void displayCard() const;
    private:
        std::string suit;
        int rank;
};

#endif // CARDS_H
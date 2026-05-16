#include <iostream>
#include <string>

#ifndef CARDS_H
#define CARDS_H

class Card {
    public:
        Card();
        Card(std::string suit, std::string rank);
        std::string getSuit() const;
        std::string getRank() const;
        void displayCard() const;
    private:
        std::string suit;
        std::string rank;
};

#endif // CARDS_H
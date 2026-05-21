#include <vector>
#include <iostream>
#include <unordered_set>
#include <algorithm>
#include "Cards.h"
#include "Player.h"
#include "Deck.h"
#include "HandIdentification.h"
#include "Simulation.h"


int main() {
    Simulation sim;
    std::cout << sim.runSimulation(1) << std::endl;
}
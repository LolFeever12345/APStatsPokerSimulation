CPPFILES = main.cpp Player.cpp Cards.cpp Deck.cpp HandIdentification.cpp Simulation.cpp

main:
	g++ $(CPPFILES) -o main
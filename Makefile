BOOST = /usr/local/Cellar/boost/1.56.0/lib/
CC = -O3 -g3 -Wall -c -fmessage-length=0
OBJS = AsciiArt.o Blackjack.o Card.o Dealer.o Hand.o Player.o Deck.o main.o

all:
	g++ $(CC) -o AsciiArt.o ./Blackjack/AsciiArt.cpp
	g++ $(CC) -o Blackjack.o ./Blackjack/Blackjack.cpp
	g++ $(CC) -o Card.o ./Blackjack/Card.cpp
	g++ $(CC) -o Dealer.o ./Blackjack/Dealer.cpp
	g++ $(CC) -o Deck.o ./Blackjack/Deck.cpp
	g++ $(CC) -o Hand.o ./Blackjack/Hand.cpp
	g++ $(CC) -o Player.o ./Blackjack/Player.cpp
	g++ $(CC) -o main.o ./Blackjack/main.cpp
	g++ -o blackjack.exe $(OBJS)

clean:
	rm *.o blackjack.exe

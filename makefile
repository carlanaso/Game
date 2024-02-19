CC=g++ 
exe=run_asm4

$(exe): bats.o event.o game.o gold.o room.o stalactites.o armor.o wumpus.o main.o
	$(CC) bats.o event.o game.o gold.o room.o armor.o stalactites.o wumpus.o main.o -o $(exe)

bats.o: bats.cpp
	$(CC) -c bats.cpp
event.o: event.cpp
	$(CC) -c event.cpp
game.o: game.cpp
	$(CC) -c game.cpp
gold.o: gold.cpp
	$(CC) -c gold.cpp
room.o: room.cpp
	$(CC) -c room.cpp
stalactites.o: stalactites.cpp
	$(CC) -c stalactites.cpp
wumpus.o: wumpus.cpp
	$(CC) -c wumpus.cpp

armor.o: armor.cpp
	$(CC) -c armor.cpp

main.o: main.cpp
	$(CC) -c main.cpp

clean:
	rm -f *.o $(exe)


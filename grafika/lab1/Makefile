LIBS-dynamicznie=-lsfml-system -lsfml-window -lsfml-graphics

includs = \SFML-2.5.1\include
libs = \SFML-2.5.1\lib

name=main

all: $(name)

$(name).o: $(name).cpp
	g++ -std=c++17 -IC:$(includs) -c $(name).cpp -o $(name).o 

$(name): $(name).o
	g++ -std=c++17 -LC:$(libs) -o $(name).exe $(name).o $(LIBS-dynamicznie)

all: compile link

compile: main handler manager menuState pongState

main:
	cd src/compiled/ && g++ -c ../../pong/*.cpp

handler:
	cd src/compiled/ && g++ -c ../../pong/handler/*.cpp

manager:
	cd src/compiled/ && g++ -c ../../pong/manager/*.cpp

menuState:
	cd src/compiled/ && g++ -c ../../pong/states/menu/*.cpp

pongState:
	cd src/compiled/ && g++ -c ../../pong/states/pong/*.cpp
	cd src/compiled/ && g++ -c ../../pong/states/pong/ball/*.cpp
	cd src/compiled/ && g++ -c ../../pong/states/pong/player/*.cpp

link:
	g++ src/compiled/*.o -o main -Lsrc/lib -Isrc/include -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

run:
	main.exe
all: compile link

compile: main handler manager menuState pongState

main:
	cd src/compiled/ && g++ -c -Lsrc/lib -Isrc/include ../../pong/*.cpp

handler:
	cd src/compiled/ && g++ -c -Lsrc/lib -Isrc/include ../../pong/handler/*.cpp

manager:
	cd src/compiled/ && g++ -c -Lsrc/lib -Isrc/include ../../pong/manager/*.cpp

menuState:
	cd src/compiled/ && g++ -c -Lsrc/lib -Isrc/include ../../pong/states/menu/*.cpp

pongState:
	cd src/compiled/ && g++ -c -Lsrc/lib -Isrc/include ../../pong/states/pong/*.cpp
	cd src/compiled/ && g++ -c -Lsrc/lib -Isrc/include ../../pong/states/pong/ball/*.cpp
	cd src/compiled/ && g++ -c -Lsrc/lib -Isrc/include ../../pong/states/pong/player/*.cpp

link:
	g++ src/compiled/*.o -o main -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

run:
	main.exe
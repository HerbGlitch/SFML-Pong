all: compile link

compile: main handler manager menuState pongState

main:
	cd src/compiled/ && g++ -c ../../pong/main.cpp -o main.o
	cd src/compiled/ && g++ -c ../../pong/game.cpp -o game.o

handler:
	cd src/compiled/ && g++ -c ../../pong/handler/handler.cpp -o handler.o

manager:
	cd src/compiled/ && g++ -c ../../pong/manager/texture.cpp -o manager.o

menuState:
	cd src/compiled/ && g++ -c ../../pong/states/menu/menu.cpp -o menuState.o

pongState:
	cd src/compiled/ && g++ -c ../../pong/states/pong/game.cpp -o pongState.o
	cd src/compiled/ && g++ -c ../../pong/states/pong/ball/ball.cpp -o ball.o
	cd src/compiled/ && g++ -c ../../pong/states/pong/player/player.cpp -o player.o

link:
	g++ src/compiled/*.o -o main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

run:
	main.exe
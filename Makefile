all: compile link

compile: main handler manager menuState pongState

main:
	cd src/compiled/ && g++ -c ../../pong/*.cpp -Lsrc/lib -Isrc/include

handler:
	cd src/compiled/ && g++ -c ../../pong/handler/*.cpp -Lsrc/lib -Isrc/include

manager:
	cd src/compiled/ && g++ -c ../../pong/manager/*.cpp -Lsrc/lib -Isrc/include

menuState:
	cd src/compiled/ && g++ -c ../../pong/states/menu/*.cpp -Lsrc/lib -Isrc/include

pongState:
	cd src/compiled/ && g++ -c ../../pong/states/pong/*.cpp -Lsrc/lib -Isrc/include
	cd src/compiled/ && g++ -c ../../pong/states/pong/ball/*.cpp -Lsrc/lib -Isrc/include
	cd src/compiled/ && g++ -c ../../pong/states/pong/player/*.cpp -Lsrc/lib -Isrc/include

link:
	g++ src/compiled/*.o -o main -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

run:
	main.exe
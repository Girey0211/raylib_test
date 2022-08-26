gcc main.c -o game.exe -Wall -std=c11 -I ./include/ -L ./lib/ -lraylib -lm -lpthread -ldl -lrt -lX11 -lGL
./game.exe
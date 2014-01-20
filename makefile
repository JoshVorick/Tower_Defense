FLAGS = -Wall -Werror
LFLAGS = `sdl-config --libs` -lSDL_image -lSDL_mixer -lSDL_ttf
OBJS = src/init.o src/graphics.o src/main.o src/Game/Towers/towers.o src/Game/Enemies/enemies.o src/StartMenu/startMenu.o src/input.o src/Game/game.o
CXX = gcc

%.o: %.c %.h src/defs.h src/structs.h src/Game/Towers/towers.c src/Game/Towers/towers.h src/Game/Enemies/enemies.c src/Game/Enemies/enemies.h src/StartMenu/startMenu.c src/StartMenu/startMenu.h
	$(CXX) $(FLAGS) -c -s $< -o $@

Tower_Defense: $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LFLAGS)

clean:
	rm $(PROG) *.o

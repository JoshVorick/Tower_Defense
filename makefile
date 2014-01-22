FLAGS = -Wall -Werror
LFLAGS = `sdl-config --libs` -lSDL_image -lSDL_mixer -lSDL_ttf
OBJS = src/init.o src/graphics.o src/main.o src/Game/Towers/towers.o src/Game/Enemies/enemies.o src/StartMenu/startMenu.o src/input.o src/Game/game.o src/Game/grid.o
CXX = gcc

%.o: %.c %.h src/defs.h src/structs.h 
	$(CXX) $(FLAGS) -c -s $< -o $@

Tower_Defense: $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LFLAGS)

clean:
	rm Tower_Defense $(OBJS)

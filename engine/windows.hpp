#ifndef WINDOW_CPP
#define WINDOW_CPP
#include "SDL/SDL.h"

class window{
	private:
		SDL_Surface *screen;


	public:
		//constructor/s to create a window
		window(int w, int h);
		
		//Draw image to screen at respective coordinates
		void draw(char *filename, int x, int y);
		
		
		//Draw image to respective coordinates ignoring specific colors
		void draw(char *filename, int x, int y, int ix, int iy);

		//reload the window
		void reload();

		//close the window
		void close();
}

#endif

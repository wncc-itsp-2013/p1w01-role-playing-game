#ifndef WINDOW_HPP
#define WINDOW_HPP
#include "SDL/SDL.h"

class window{
	private:
		SDL_Surface *screen,*background;
		Uint32 bgcolor;


	public:
		//constructor/s to create a window
		window(int w, int h);

		//resets the screen to bgcolor
		void refresh();

		//changes the background color
		void setbgcolor(int x,int y, int z);
		
		//Draw image to screen at respective coordinates
		void draw(char *filename, int x, int y);
		
		
		//Draw image to respective coordinates ignoring specific colors
		void draw(char *filename, int x, int y, int ix, int iy);

		//reload the window
		void reload();

		//close the window
		void close();
};

#endif

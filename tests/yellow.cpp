#include "SDL/SDL.h"
#include "putget.cpp"


int main(){
/* Code to set a yellow pixel at the center of the screen */
int x, y;
Uint32 yellow;
/* Map the color yellow to this display (R=0xff, G=0xFF, B=0x00)
Note: If the display is palettized, you must set the palette first.
*/
yellow = SDL_MapRGB(screen->format, 0xff, 0xff, 0x00);
x = screen->w / 2;
y = screen->h / 2;
/* Lock the screen for direct access to the pixels */
if ( SDL_MUSTLOCK(screen) ) {
if ( SDL_LockSurface(screen) < 0 ) {
fprintf(stderr, "Can’t lock screen: %s\n", SDL_GetError());
return;
}
}
putpixel(screen, x, y, yellow);
if ( SDL_MUSTLOCK(screen) ) {
SDL_UnlockSurface(screen);
}
/* Update just the part of the display that we’ve changed */
SDL_UpdateRect(screen, x, y, 1, 1);
return;
}

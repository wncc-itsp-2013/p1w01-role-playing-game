#include "SDL/SDL.h"
#include <iostream>
using namespace std;

int main(){
	if( SDL_Init(SDL_INIT_JOYSTICK)){
		fprintf(stderr, "Couldn't initialize joystick: %s\n",SDL_GetError());
		return 1;
	}

	cout<<"no of joysticks found: "<<SDL_NumJoysticks()<<endl;

	SDL_Joystick *joystick;
	SDL_JoystickEventState(SDL_ENABLE);
	joystick = SDL_JoystickOpen(0);

	cout<<"joystick axes: "<<SDL_JoystickNumAxes(joystick)<<endl;
	cout<<"joystick buttons: "<<SDL_JoystickNumButtons(joystick)<<endl;
	cout<<"joystick balls: "<<SDL_JoystickNumBalls(joystick)<<endl;
	cout<<"joystick hats: "<<SDL_JoystickNumHats(joystick)<<endl;

	SDL_Event event;

	while(SDL_PollEvent(&event)){
		switch(event.type){
			case SDL_JOYAXISMOTION:
				cout<<"Event.jaxix.value is: "<<event.jaxis.value<<endl;
				break;
			case SDL_JOYBUTTONDOWN:
				cout<<"The button pressed is: "<<event.jbutton.button<<endl;
				break;
		}
	}


	SDL_JoystickClose(joystick);

	sleep(2);
	SDL_Quit();
	cout<<"quit"<<endl;
	return 0;
}

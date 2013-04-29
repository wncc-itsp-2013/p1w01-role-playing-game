#ifndef TIMER_CPP
#define TIMER_CPP

#include "SDL/SDL.h"

class timer{
	public:
		timer(int p_interval = 1000){
			interval = p_interval;
			accumulator = 0;
			total = 0;
			cur_time = last_time = SDL_GetTicks();
		}
		bool ready(){
			return accumulator > interval;
		}
		int check(){
			if(ready ()){
				//accumulator -= interval;
				accumulator = 0;
				return 1;
			}
			return 0;
		}
		void update(){
			int delta;
			cur_time= SDL_GetTicks();
			delta=cur_time - last_time;
			total += delta;
			accumulator += delta;
			last_time = cur_time;
		}

	private:
		int last_time;
		int cur_time;
		int accumulator;
		int total;
		int interval;
};

//A continuous timer
class contimer{
	public:
		contimer(){
			cur_time = start_time = last_time = SDL_GetTicks();
			total_time = 0;
			diff_time =0.0f;
		}
		float getDelta(){
			cur_time = SDL_GetTicks();
			diff_time = float(cur_time- last_time)/1000.0f;
			last_time = cur_time;
			return diff_time;
		}
	private:
		int start_time;
		int cur_time;
		int last_time;
		int total_time;
		float diff_time;
};

#endif

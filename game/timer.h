#ifndef TIMER_CPP
#define TIMER_CPP

#include "SDL/SDL.h"
#include <cmath>
#include <iostream>

class timer{
	private:
		int last_time;
		int cur_time;
		int accumulator;
		int total;
		int interval;
	public:
		timer(int p_interval = 1000){
			interval = p_interval;
			accumulator = 0;
			total = 0;
			last_time = SDL_GetTicks();
			cur_time = last_time;
		}
		bool ready(){
			return (accumulator >= interval);
		}
		bool check(){
			if(ready ()){
				accumulator = 0;
				return true;
			}
			return false;
		}
		void update(){
			int delta;
			cur_time= SDL_GetTicks();
			delta=cur_time - last_time;
			total += delta;
			accumulator += delta;
			last_time = cur_time;
			return;
		}
		//for use in static timers
		void reset(){
			accumulator = 0;
			total = 0;
		}

};

//A continuous timer
class contimer{
	public:
		contimer(){
			cur_time = start_time = last_time = SDL_GetTicks();
			total_time = 0;
			diff_time =0.0f;
		}
		double getDelta(){
			cur_time = SDL_GetTicks();
			diff_time = double(cur_time- last_time)/1000.0f;
			last_time = cur_time;
			return diff_time;
		}
        void reset(){
			cur_time = start_time = last_time = SDL_GetTicks();
			total_time = 0;
			diff_time =0.0f;
        }
	private:
		int start_time;
		int cur_time;
		int last_time;
		int total_time;
		double diff_time;
};

//Parametric timer
class parametricBase{
	public:
		parametricBase(){
			accumulator = 0;
			total = 0;
			cur_time = last_time = SDL_GetTicks();
		}
		float getFloat(){
			update();
			return genValue();
		}
	protected:
		virtual float genValue() = 0;
		void update(){
			int delta;
			cur_time = SDL_GetTicks();
			delta =cur_time - last_time;
			total+=delta;
			accumulator += delta;
			last_time = cur_time;
		}
		int last_time;
		int cur_time;
		int accumulator;
		int total;
		int interval;
};

class parametricSine : public parametricBase{
	virtual float genValue(){
		return sinf(accumulator/1000.0f);
	}
};


#endif

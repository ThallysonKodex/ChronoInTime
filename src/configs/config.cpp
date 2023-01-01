#include "config.h"



Config::Config(WINDOW* scr){

		raw();
		noecho();
		nodelay(scr, true);

		start_color();


		//INITIATION OF COLORS
		// LIGHT BLUE - BLACK BG 1
		init_color(9, 100, 700, 1000);

		// INITIATION OF COLOR PAIRS
		// LIGHT BLUE - BLACK BG 1
		init_pair(1, 9, COLOR_BLACK);

		// GREEN - BLACK BG 2
		init_pair(2, COLOR_GREEN, COLOR_BLACK);
	
}

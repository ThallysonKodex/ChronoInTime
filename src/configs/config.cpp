#include "config.h"



Config::Config(WINDOW* scr){

		raw();
		noecho();
		nodelay(scr, true);

		start_color();


		//INITIATION OF COLORS
		// LIGHT BLUE
		init_color(9, 100, 700, 1000);
		// RED
		init_color(10, 1000, 100, 100);

		// INITIATION OF COLOR PAIRS
		// RED - BLACK BG 3
		init_pair(3, 10, COLOR_BLACK);

		// LIGHT BLUE - BLACK BG 1
		init_pair(1, 9, COLOR_BLACK);

		// GREEN - BLACK BG 2
		init_pair(2, COLOR_GREEN, COLOR_BLACK);
	
}

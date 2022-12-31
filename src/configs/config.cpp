#include "config.h"



Config::Config(WINDOW* scr){

		raw();
		noecho();
		nodelay(scr, true);

		start_color();

}

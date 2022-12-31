#include <iostream>
#include "commons.h"
#include "config.h"
#include "update.h"
#include <string>
#include <ncurses.h>
#include <cstring>

int main(){
	
	// Init app
	initscr();

  // Configs
	Config* config = new Config(stdscr);
	
	// Call the updater non repeating methods
	Updater* updater = new Updater();

	bool running = true;
	while(running){

		// Ask for inputs
		int ch = getch();
		// Call the game methods			
		updater->update(ch);



		// EXIT THE GAME LOOP
		if(ch == 'q'){
			running = false;
			endwin();
			break;
		}
	}
	
	

	// ENDING APP
	endwin();
	updater->release();
	delete config;
	config = nullptr;
	delete updater;
	updater = nullptr;

	return 0;
}

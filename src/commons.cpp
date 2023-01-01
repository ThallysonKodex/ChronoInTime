#include <iostream>
#include "commons.h"
#include <unistd.h>
#include <string>
#include <ncurses.h>

void sleeper(int millis){
	usleep(millis * 1000);
}

void typer(char key, const std::string text){

	for(int i = 0; i < text.length(); i++){

		if(key == 'q'){
			refresh();
			return;
		} 
		if(key < 0){
			addch(text[i]);
			refresh();
			sleeper(100);
		}

	}
	sleeper(100);
	
}



void typer(char key, const std::string text, int timer){
	for(int i = 0; i < text.length(); i++){
	
		if(key == 'q'){
			refresh();
			return;
		} 

		if(key < 0){
			addch(text[i]);
			refresh();
			sleeper(timer);
		}

	}
	sleeper(timer);
}


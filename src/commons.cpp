#include <iostream>
#include "commons.h"
#include <unistd.h>
#include <string>
#include <ncurses.h>


void registerPerson(std::map<int, Person>& people, int& count, Person person){

	people.insert(std::make_pair(count, person));
	++count;


}

void registerRoom(std::map<int, Room>& roomMap, int& count, Room room){
	roomMap.insert(std::make_pair(count, room));
	++count;
}


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


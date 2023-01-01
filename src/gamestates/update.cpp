#include "update.h"
#include "commons.h"
#include "person.h"
#include "room.h"
#include "currentState.h"
#include <map>
#include <ncurses/ncurses.h>
#include <string>


void addRoom(std::map<int, Room>& roomMap, int& count, Room room){
	roomMap.insert(std::make_pair(count, room));
	++count;
}


// Local variables

Person* alex;
StateManager* state;
Updater::Updater(){
	

	int room_count {0};
	std::map<int, Room> rooms; 
	addRoom(rooms, room_count, Room("Alex's room"));
	addRoom(rooms, room_count, Room("Livingroom"));
	

	alex = new Person("Alex", 16, rooms.at(0));	
	state = new StateManager(*alex);	

}

// Main Timeline


bool redrewn1 {true};

void Updater::update(char key){
	
	// DRAW


	// DRAW CURRENT STATE
	if( redrewn1 == true ){
		redrewn1 = false;
		move(1, 6);
		attron(COLOR_PAIR(1));
		addstr("Current State:");
		attroff(COLOR_PAIR(1));

		move(2, 10);
		attron(COLOR_PAIR(2));
		typer(key, "Name: " + state->getCurrent().getName(), 1);
		attroff(COLOR_PAIR(2));

		typer(key, " - ", 1);	

		attron(COLOR_PAIR(2));
		typer(key, "Age: " + std::to_string(state->getCurrent().getAge()), 1);
		attroff(COLOR_PAIR(2));

		typer(key, " - ", 1);	
		
		attron(COLOR_PAIR(2));
		typer(key, "Current Room: " + state->getCurrent().getRoom().getName(), 1);
		attroff(COLOR_PAIR(2));

	}




	refresh();

}
void Updater::release(){

	// DELETE STATE VARIABLES
	delete alex;
	delete state;
	alex = nullptr;
	state = nullptr;


}

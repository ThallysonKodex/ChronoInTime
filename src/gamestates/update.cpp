#include "update.h"
#include "commons.h"
#include "person.h"
#include "room.h"
#include "currentState.h"
#include <map>
#include <vector>
#include <ncurses/ncurses.h>
#include <string>




// Local variables

// To store all rooms in the game and retrieve them.
std::map<int, Room> rooms;

// To store all people in the game and retrieve them.
std::map<int, Person> people;


// How many rooms are in the whole game
int room_count {0};

// How many people are in the whole game;
int people_count {0};


StateManager* state;
Updater::Updater(){
	



	// Functions to add rooms to rooms and to add to room_count
	registerRoom(rooms, room_count, Room("Alex's room"));
	registerRoom(rooms, room_count, Room("Livingroom"));
	
	// To add doors to link rooms to other rooms
	rooms.at(0).addDoor(rooms.at(1));

	// People creation to insert them into the room (declare outside updater for easy access)
	registerPerson(people, people_count, Person("Alex", 16, 'm', rooms.at(0)));
	registerPerson(people, people_count, Person("Sam", 17, 'f', rooms.at(0)));
	registerPerson(people, people_count, Person("Robin", 17, 'f', rooms.at(0)));
	

	// The state manager to switch between who is the playable character right now/
	state = new StateManager(people.at(0));	

}

bool redrewn1 {true};

void Updater::update(char key){
	
	// DRAW
	
	attron(COLOR_PAIR(1));
	mvwaddstr(stdscr, 1, 6, "Current State:");
	attroff(COLOR_PAIR(1));

	attron(COLOR_PAIR(2));
	mvwaddstr(stdscr, 2, 10, ("Name: " + state->getCurrent().getName()).c_str());
	attroff(COLOR_PAIR(2));
	
	addstr(" - ");	
	
	attron(COLOR_PAIR(2));
	addstr(("Age: " + std::to_string(state->getCurrent().getAge())).c_str());
	attroff(COLOR_PAIR(2));

	addstr(" - ");
		
	attron(COLOR_PAIR(3));
	addstr(("Current Room: " + state->getCurrent().getRoom()->getRoomName()).c_str());
	addstr((" [ Doors: " + std::to_string(state->getCurrent().getRoom()->getDoorCount()) + " ]").c_str());
	attroff(COLOR_PAIR(3));

	attron(COLOR_PAIR(1));
	mvwaddstr(stdscr, 3, 6, "Description:");
	attroff(COLOR_PAIR(1));
	

	// DRAW CURRENT STATE
	if( redrewn1 == true ){
		redrewn1 = false;

		move(4, 10);
		typer(key, state->getCurrent().getName() + " is in " + 
				(state->getCurrent().getRoom()->getRoomName() == state->getCurrent().getName() + "'s room" ? 
				 (state->getCurrent().getGender() == 'm' ? "his room" : "her room") : "the " + state->getCurrent().getRoom()->getRoomName()) +
					"" , 100);
		if(people_count < 2){
			typer(key, " alone.", 100);
		} else {

			typer(key, " with ", 100);
			for(std::map<int, Person>::iterator i = people.begin(); i != people.end(); i++){
				if(i->second.getName() == state->getCurrent().getName()){
					continue;
				}
				if(i == std::prev(people.end())){
					typer(key, (i->second.getName() + ".").c_str(), 100);
				}
				else if(i == std::prev(std::prev(people.end()))){
					typer(key, (i->second.getName() + " and ").c_str(), 100);
				}
				else{
					typer(key, (i->second.getName() + ", ").c_str(), 100);
				}
			 	
			}

		}

		// NEW CODE HERE
		
		
		// :)
}




	refresh();

}
void Updater::release(){

	// DELETE STATE VARIABLES
	delete state;
	state = nullptr;


}

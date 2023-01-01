#include "update.h"
#include "commons.h"
#include "person.h"
#include "currentState.h"
#include <ncurses.h>


// Local variables
int y = 0; 

Updater::Updater(){

	
}


Person* alex = new Person("Alex", 16);	
StateManager* state = new StateManager(*alex);	

bool redrewn1 {true};

void Updater::update(char key){
	
	// DRAW
	
	if( redrewn1 == true ){
		redrewn1 = false;
		move(1 + y, 6);
		attron(COLOR_PAIR(1));
		addstr("Current State:");
		attroff(COLOR_PAIR(1));

		move(2 + y, 10);
		attron(COLOR_PAIR(2));
		typer(key, "Name: " + state->getCurrent().getName(), 1);
		attroff(COLOR_PAIR(2));
		typer(key, " - ", 1);	

		attron(COLOR_PAIR(2));
		typer(key, "Age: " + std::to_string(state->getCurrent().getAge()), 1);
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

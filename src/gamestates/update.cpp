#include "update.h"
#include "commons.h"
#include "person.h"
#include "currentState.h"
#include <ncurses.h>

// Local variables



Person* alex;
StateManager* state;

Updater::Updater(){

	alex = new Person("Alex", 16);	
	state = new StateManager(*alex);	

	move(1, 6);
	
	init_pair(1, COLOR_RED, COLOR_BLACK);
	
	attron(COLOR_PAIR(1));
	typer("Current State:");
	attroff(COLOR_PAIR(1));

	move(2, 10);
	typer("Name: " + state->getCurrent().getName());
	typer(" - ");	
	typer("Age: " + std::to_string(state->getCurrent().getAge()));

	
}


void Updater::update(char key){




}

void Updater::release(){

	delete alex;
	delete state;
	alex = nullptr;
	state = nullptr;


}

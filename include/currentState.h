#ifndef STATEMANAGER
#define STATEMANAGER
#include "person.h"

class StateManager{

	public:
		StateManager(Person& person);

		Person getCurrent();

	private:

		Person currentCharacter;


};

#endif

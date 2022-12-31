#include "currentState.h"
#include "person.h"

StateManager::StateManager(Person& person) : currentCharacter(person) {};

Person StateManager::getCurrent(){


	return currentCharacter;
}

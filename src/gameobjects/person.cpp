#include "person.h"
#include <string>

Person::Person(std::string name, int age, Room& initialRoom) 
	: m_name(name), m_age(age), m_currentRoom(initialRoom){};


std::string Person::getName(){

	return m_name;
}

void Person::addAge(){
	++m_age;
}

int Person::getAge(){

	return m_age;
}


void Person::switchRoom(Room& room){
	m_currentRoom = room;
}

Room Person::getRoom(){
	return m_currentRoom;
}

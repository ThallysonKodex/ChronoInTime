#ifndef PERSON
#define PERSON
#include "room.h"
#include <string>

class Person{

	public:
		Person(std::string, int, Room&);
		std::string getName();
		
		void addAge();
		int getAge();
		
		void switchRoom(Room&);
		Room getRoom();

	private:
		std::string m_name;
		int m_age;
		Room m_currentRoom;
};



#endif


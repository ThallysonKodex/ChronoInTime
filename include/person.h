#ifndef PERSON
#define PERSON
#include <string>

class Room;


class Person{

	public:
		Person(std::string, int, char, Room& room);
		std::string getName();
		
		void addAge();
		int getAge();
	
		char getGender();
		void switchRoom(Room& room);
		Room* getRoom();

	private:
		char m_gender;
		std::string m_name;
		int m_age;
		Room* m_currentRoom;
};


#include "room.h"


#endif


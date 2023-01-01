#include "room.h"

template<typename T>
DOOR<T>::DOOR(T room) : m_room(&room){};


Room::Room(std::string roomName) : m_roomName(roomName), m_doorCount(0) {};

int Room::getDoorCount(){
	return m_doorCount;
}

void Room::addDoor(Room room){
	DOOR<Room> door(room);
	m_doors.insert(std::make_pair(m_doorCount, door));
	++m_doorCount;
}

std::string Room::getName(){
	return m_roomName;
}

#ifndef ROOM
#define ROOM
#include <map>
#include <string>

template<typename T>
class DOOR{
	
	public:
		DOOR(T room);
		T* m_room;


}; 


class Room{

	public:
	

	Room(std::string roomName);
	
	int getDoorCount();

	void addDoor(Room);
	void removeDoor(int door);
	std::string getName();

	private:
	std::string m_roomName;
	int m_doorCount;
	std::map<int, DOOR<Room>> m_doors;



};



#endif

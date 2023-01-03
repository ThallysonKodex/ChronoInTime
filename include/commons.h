#ifndef COMMONS
#define COMMONS
#include <string>
#include "room.h"
#include "person.h"

void registerRoom(std::map<int, Room>&, int&, Room);

void registerPerson(std::map<int, Person>&, int&, Person);

void typer(char, const std::string);

void typer(char, const std::string, int);


void sleeper(int millis);



#endif



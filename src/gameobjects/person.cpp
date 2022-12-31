#include "person.h"
#include <string>

Person::Person(std::string name, int age) : m_name(name), m_age(age) {};

int Person::getAge(){

	return m_age;
}

std::string Person::getName(){

	return m_name;
}

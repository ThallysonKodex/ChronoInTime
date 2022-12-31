#ifndef PERSON
#define PERSON
#include <string>

class Person{

	public:
		Person(std::string, int);
		std::string getName();
		int getAge();

	private:
		std::string m_name;
		int m_age;

};



#endif


#include <iostream>
#include "student.h";
#include "networkStudent.h";
#include "degree.h";
using namespace std;

// Constructors
NetworkStudent::NetworkStudent() : Student() {};
NetworkStudent::NetworkStudent(string _studentID, string _firstName, string _lastName, string _emailAddress, int _age, int daysInCourse1, int daysInCourse2, int daysInCourse3) : Student(_studentID, _firstName, _lastName, _emailAddress, _age, daysInCourse1, daysInCourse2, daysInCourse3)
{
	this->degreeType = DEGREES::NETWORK;
}

// Class Methods
DEGREES NetworkStudent::GetDegreeProgram() const {
	return degreeType;
}

void NetworkStudent::print() {
	 Student::print();
	 cout << "Degree Type: " << DEGREE_STRINGS[degreeType] << "\n";
}
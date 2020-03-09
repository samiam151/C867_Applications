#include <iostream>
#include "student.h";
#include "securityStudent.h";
#include "degree.h";
using namespace std;

// Constructors
SecurityStudent::SecurityStudent() : Student() {};
SecurityStudent::SecurityStudent(string _studentID, string _firstName, string _lastName, string _emailAddress, int _age, int daysInCourse1, int daysInCourse2, int daysInCourse3) : Student(_studentID, _firstName, _lastName, _emailAddress, _age, daysInCourse1, daysInCourse2, daysInCourse3)
{
	this->degreeType = DEGREES::SECURITY;
}

// Class Methods
DEGREES SecurityStudent::GetDegreeProgram() const {
	return degreeType;
}

void SecurityStudent::print() {
	Student::print();
	cout << "Degree Type: " << DEGREE_STRINGS[degreeType] << "\n";
}
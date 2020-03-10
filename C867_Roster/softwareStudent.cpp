#include <iostream>
#include "student.h";
#include "softwareStudent.h";
#include "degree.h";
using namespace std;

// Constructors
SoftwareStudent::SoftwareStudent() : Student() {};
SoftwareStudent::SoftwareStudent(string _studentID, string _firstName, string _lastName, string _emailAddress, int _age, int daysInCourse1, int daysInCourse2, int daysInCourse3) : Student(_studentID, _firstName, _lastName, _emailAddress, _age, daysInCourse1, daysInCourse2, daysInCourse3)
{
	this->degreeType = DEGREES::SOFTWARE;
}

// Class Methods
DEGREES SoftwareStudent::GetDegreeProgram() const {
	return degreeType;
}

void SoftwareStudent::print() {
	Student::print();
	cout << "\tDegree Type: " << DEGREE_STRINGS[degreeType] << endl;
}
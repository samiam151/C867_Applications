#include <iostream>
using namespace std;
#include "student.h";
#include "degree.h";

// Constructor
Student::Student() {};

Student::Student(string _studentID, string _firstName, string _lastName, string _emailAddress, int _age, int daysInCourse1, int daysInCourse2, int daysInCourse3)
{
	studentID = _studentID;
	firstName = _firstName;
	lastName = _lastName;
	emailAddress = _emailAddress;
	age = _age;
	daysToCompleteThreeCourses = { daysInCourse1, daysInCourse2, daysInCourse3 };
}

// Destructor
Student::~Student() { }

// Getters
string Student::GetStudentID() const { return studentID; }

string Student::GetFirstName() const { return firstName; }

string Student::GetLastName() const { return lastName; }

string Student::GetEmailAddress() const { return emailAddress; }

int Student::GetAge() const { return age; }

array<int, 3> Student::GetDaysToCompleteThreeCourses() const { 
	return daysToCompleteThreeCourses; 
};

DEGREES Student::GetDegreeProgram() const { return DEGREES::SECURITY; };

// Setters
void Student::SetStudentID(string newID) {
	studentID = newID;
}

void Student::SetFirstName(string newFirstName) {
	firstName = newFirstName;
}

void Student::SetLastName(string newLastName) {
	lastName = newLastName;
}

void Student::SetEmailAddress(string newEmailAddress) {
	emailAddress = newEmailAddress;
}

void Student::SetAge(int newAge) {
	age = newAge;
}

void Student::SetDaysToCompleteThreeCourses(int days1, int days2, int days3) {
	daysToCompleteThreeCourses = { days1, days2, days3 };
}

void Student::SetDegreeType(DEGREES newDegreeType) {
	degreeType = newDegreeType;
}

// Methods
void Student::print() {
	cout << "First Name: " << GetFirstName() << " \t" 
		<< "Last Name: " << GetLastName() << " \t"
		<< "Email Address: " << GetEmailAddress() << " \t"
		<< "Age: " << GetAge() << " \t"
		<< "Days In Three Courses: {"; cout << GetDaysToCompleteThreeCourses()[0] << ", " << GetDaysToCompleteThreeCourses()[1] << ", " << GetDaysToCompleteThreeCourses()[2] << "}";
};
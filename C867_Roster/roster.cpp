#include <iostream>
#include <array>
#include <vector>
#include <sstream>
#include <string>
#include "degree.h";
#include "student.h";
#include "networkStudent.h";
#include "roster.h";
#include "securityStudent.h";
#include "softwareStudent.h";
using namespace std;


Roster::Roster() {
	for (int i = 0; i < 5; i++)
	{
		classRosterArray[i] = new Student;
	}
}

Roster::~Roster() {
	cout << "---------------------------------" << endl;
	for (int i = 0; i < 5; i++)
	{
		if (classRosterArray[i] != NULL) {
			string id = classRosterArray[i]->GetStudentID();
			delete classRosterArray[i];
			classRosterArray[i] = NULL;
			cout << "Student " << id << " cleared from memory." << endl;
		}
	}
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DEGREES _degreeType) {
	Student *newStudent = nullptr;
	//Student *newStudent;

	if (_degreeType == DEGREES::SECURITY) {
		newStudent = new SecurityStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3);
	}
	if (_degreeType == DEGREES::NETWORK) {
		newStudent = new NetworkStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3);
	}
	if (_degreeType == DEGREES::SOFTWARE) {
		newStudent = new SoftwareStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3);
	}
	classRosterArray[addIndex] = newStudent;
	addIndex++;
	//delete newStudent;
}

void Roster::remove(string studentID) {
	bool isRemoved = false;
	for (int i = 0; i < 5; i++) {		
		Student* student;
		if (classRosterArray[i] != NULL) {
			string id = classRosterArray[i]->GetStudentID();
			if (id == studentID) {
				delete classRosterArray[i];
				classRosterArray[i] = NULL;
				cout << "Student #" << studentID << " has been removed from the roster." << endl;
				isRemoved = true;
			}
		}
	}
	if (!isRemoved) {
		cout << "Student #" << studentID << " could not be found in the roster." << endl;
	}
};

void Roster::printAll() {
	for (int i = 0; i < 5; i++) {
		if (*(classRosterArray + i) != NULL) {
			classRosterArray[i]->print();
			cout << endl;
		}
	}
};

void Roster::printDaysInCourse(string studentID) {
	for (int i = 0; i < 5; i++)
	{
		if (classRosterArray[i] != NULL) {
			Student* student = this->classRosterArray[i];
			string id = student->GetStudentID();
			if (id == studentID) { 
				array<int, 3> days = student->GetDaysToCompleteThreeCourses();
				int totalDays = 0;

				for (int ii = 0; ii < 3; ii++)
				{
					totalDays += days[ii];
				}

				cout << "Student " << student->GetStudentID() << " averaged " << totalDays / 3 << " in three courses" << endl;
			}

		}
	}
};

void Roster::printInvalidEmails() {
	for (int i = 0; i < 5; i++)
	{
		if (classRosterArray[i] != NULL) {
			bool isValid = true;
			Student* student = this->classRosterArray[i];
			string studentEmail = student->GetEmailAddress();

			size_t found = studentEmail.find('@');
			if (found == string::npos) {
				isValid = false;
			}

			found = studentEmail.find('.');
			if (found == string::npos) {
				isValid = false;
			}

			found = studentEmail.find(' ');
			if (found != string::npos) {
				isValid = false;
			}

			if (!isValid) {
				cout << "Invalid email address: " << studentEmail << endl;
			}
		}

	}
};

void Roster::printByDegreeProgram(DEGREES degreeProgram) {
	cout << "Students in the " << DEGREE_STRINGS[degreeProgram] << " program:" << endl;
	for (int i = 0; i < 5; i++)
	{
		if (classRosterArray[i] != NULL) {
			Student* student = this->classRosterArray[i];
			if (student->GetDegreeProgram() == degreeProgram) {
				student->print();
			}
		}
	}
};

void main() {
	cout << "Scripting and Programming-Applications-C867\t" << "Language: C++\t" << "StudentID: 001249697\t" << "Name: Nicolas Sam" << endl << endl;

	Roster classRoster = Roster();
	const string studentData[] = { 
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Nicolas,Sam,nsam2@wgu.edu,31,10,15,5,SOFTWARE" 
	};

	
	for (int i = 0; i < 5; i++)
	{
		vector<string> parsedDataString;
		stringstream ss(studentData[i]);

		while (ss.good()) {
			string substr;
			getline(ss, substr, ',');
			parsedDataString.push_back(substr);
		}
		DEGREES degree;

		if (parsedDataString[8] == "NETWORK") { degree = DEGREES::NETWORK; };
		if (parsedDataString[8] == "SECURITY") { degree = DEGREES::SECURITY; };
		if (parsedDataString[8] == "SOFTWARE") { degree = DEGREES::SOFTWARE; };

		classRoster.add(
			parsedDataString[0],
			parsedDataString[1],
			parsedDataString[2],
			parsedDataString[3],
			stoi(parsedDataString[4]),
			stoi(parsedDataString[5]),
			stoi(parsedDataString[6]),
			stoi(parsedDataString[7]),
			degree
		);
	}

	classRoster.printAll();
	cout << "---------------------------------" << endl;
	classRoster.printInvalidEmails();
	cout << "---------------------------------" << endl;
	classRoster.printByDegreeProgram(SOFTWARE);
	cout << "---------------------------------" << endl;

	for (int i = 0; i < 5; i++)
	{
		Student *student = classRoster.classRosterArray[i];
		string id = student->GetStudentID();
		classRoster.printDaysInCourse(id);
	}
	cout << "---------------------------------" << endl;
	classRoster.remove("A3");
	cout << "---------------------------------" << endl;
	classRoster.remove("A3");
}
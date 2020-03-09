#pragma once
#ifndef ROSTER_H
#define ROSTER_H

#include <string>
#include <array>

#include "degree.h";
#include "student.h";
#include "networkStudent.h";
#include "securityStudent.h";
#include "softwareStudent.h";

class Roster {
public:
	Roster();
	~Roster();

	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DEGREES degreeType);
	void remove(string studentID);
	void printAll();
	void printDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DEGREES degreeProgram);
	int addIndex = 0;
	Student* classRosterArray[5];
};
#endif
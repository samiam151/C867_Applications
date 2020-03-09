#pragma once
#ifndef NETWORKSTUDENT_H
#define NETWORKSTUDENT_H

#include "student.h";

class NetworkStudent : public Student {
public:
	NetworkStudent();

	NetworkStudent(
		string _studentID,
		string _firstName,
		string _lastName,
		string _emailAddress,
		int _age,
		int daysInCourse1,
		int daysInCourse2,
		int daysInCourse3
	);

	DEGREES GetDegreeProgram() const;
	void print();

private:
	DEGREES degreeType;
};

#endif
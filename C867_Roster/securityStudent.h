#pragma once
#ifndef SECURITYSTUDENT_H
#define SECURITYSTUDENT_H

#include "student.h";

class SecurityStudent : public Student {
public:
	SecurityStudent();

	SecurityStudent(
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
#pragma once
#ifndef SOFTWARESTUDENT_H
#define SOFTWARESTUDENT_H

#include "student.h";

class SoftwareStudent : public Student {
public:
	SoftwareStudent();

	SoftwareStudent(
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
	void print() override;

private:
	DEGREES degreeType;
};

#endif
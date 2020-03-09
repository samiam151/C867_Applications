#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <array>
#include "degree.h";
using namespace std;

class Student {
public:
	Student();
	Student(
		string _studentID,
		string _firstName,
		string _lastName,
		string _emailAddress,
		int _age,
		int daysInCourse1,
		int daysInCourse2,
		int daysInCourse3
	);
	~Student();

	const static int daysArrayLength = 3;

	string GetStudentID() const;
	string GetFirstName() const;
	string GetLastName() const;
	string GetEmailAddress() const;
	int GetAge() const;
	array<int, 3> GetDaysToCompleteThreeCourses() const;

	void SetStudentID(string newID);
	void SetFirstName(string newFirstName);
	void SetLastName(string newLastName);
	void SetEmailAddress(string newEmailAddress);
	void SetAge(int newAge);
	void SetDaysToCompleteThreeCourses(int days1, int days2, int days3);
	void SetDegreeType(DEGREES newDegreeType);

	virtual void print();
	virtual DEGREES GetDegreeProgram() const;

protected:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	array<int, 3> daysToCompleteThreeCourses;
	DEGREES degreeType;
};

#endif
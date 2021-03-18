#pragma once
#include <string>
using namespace std;

// you declare the class here
class Employee
{
public:
	// this the employee constructor default
	Employee();
	// the constructor with arguments
	Employee(string,int,int, string,int);
	Employee(int);
	~Employee();
	void printEmployee();
	void printEmployeeID();
	void writeFile(ofstream&);
	string getName();
public:
	// private fields declared here
	string name;
	int id;
	int age;
	string job;
	int hireYear;

};


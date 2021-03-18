#include "Employee.h"
#include <string>
#include <iostream>
#include<fstream>

using namespace std;

// You define the class here
Employee::Employee()
{
	name=" John Doe";
	id = 12345;
	age = 20;
	job = "Programmer";
	hireYear = 1999;
}

// the parameters are named with the "in" prefix so it wont be confused with the private classes
Employee::Employee(string inName, int inId, int inAge, string inJob, int inYear)
{
	name = inName;
	id = inId;
	age = inAge;
	job = inJob;
	hireYear = inYear;
}

// constructor used to store just the ID numbers 
Employee::Employee(int inId) {
	id = inId;
}

// this is the method that prints the data in a class in this format
void Employee::printEmployee() {

	cout << "Name: " << name << endl;
	cout << "ID: " << id << endl;
	cout << "Age: " << age << endl;
	cout << "Job: " << job << endl;
	cout << "Hire Year: " << hireYear << endl;
	cout << "****************************" << endl;
}


void Employee::printEmployeeID() {

	cout << "ID: " << id << endl;
	cout << "****************************" << endl;
}


// Method that will print the output file 
void Employee::writeFile(ofstream& ofs) {
	ofs << id<<endl;
}


string Employee::getName() {
	return name;
}



Employee::~Employee() {
	//nothing here hehe
}

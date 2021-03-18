// File Input in C++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include "Employee.h"

using namespace std;

// global variable 
// Employee array for its objects 
Employee** list;

// pointer 
Employee* temporaryEmployeeVar;

// this is how you check how many comparison
int numberOfComparison =0;
int numberOfExchanges = 0;


// to do: create the lookup method and include the arraylist as the parameter to measure n.
// the code is from the book's pseudocode
/*void bubbleSort(int arrayLength)
{
	for (int i = 1;i <= arrayLength - 1; i++ ) {
		for (int j = arrayLength; j >= i + 1; j--) {
			numberOfComparison += 1;
				if (list[j]->id < list[j-1]->id) {
					numberOfExchanges += 1;
					// this the exchange of the id algorithm
					temporaryEmployeeVar = list[j];
					list[j] = list[j - 1];
					list[j - 1] = temporaryEmployeeVar;
					for (int s = 1; s <= arrayLength; s++) {
						cout << list[s]->id << " ";
					}
					cout << endl;
					
			}
			
		}
		
}
	cout << "Number of Comparisons; " << numberOfComparison << endl;
	cout << "Number of Exchanges; " << numberOfExchanges << endl;

}*/

void insertionSort(int arrayLength) {
	for (int j = 2; j <=arrayLength; j++) {		
		temporaryEmployeeVar = list[j];
		//int key = list[j]->id;
		int index = j - 1;
		while (index>0 && list[index]->id > temporaryEmployeeVar->id) {
			
			numberOfComparison += 1;
			numberOfExchanges += 1;
			list[index + 1]= list[index];
			index = index - 1;

		}

		numberOfExchanges += 1;
		list[index + 1]= temporaryEmployeeVar;

		// the printing of the array each exchange on the console	
		for (int s = 1; s <= arrayLength; s++) {
			cout << list[s]->id << " ";
		}
		cout << endl;
	}

	// printing the file 
	ofstream ofs;
	ofs.open("output.txt", ios::out);

	for (int fileIndex = 1; fileIndex <=arrayLength; fileIndex++) {
		list[fileIndex]->writeFile(ofs);
		
	}
	ofs.close();

	cout << endl;
	cout << "Number of Comparisons; " << numberOfComparison << endl;
	cout << "Number of Exchanges; " << numberOfExchanges << endl;
	cout << "seth";
}




int main(int argc, char** argv)
{
	// Global Vars 
	//Employee** idList;

	// int n is the arrayLength
	int n;



	if (argc != 2) {
		cout << "Are you forgetting the command-line parameter?" << endl;
		exit(0);
	}
	ifstream ifs;
	ifs.open(argv[1], ios::in);

	if (!ifs) {
		cout << "Error! Please check filename." << endl;
	}
	else {
		string topNumber;
		getline(ifs, topNumber);
		n = stoi(topNumber);
		list = new Employee * [n+1];
		//idList = new Employee * [n];

		for (int i = 1; i<=n; i++) {

			// these variables are just named the same as the global variables under the Employee class
			// these variable will is a temporary var to convert to int using stoi
			string temporaryVariable;
			string name;
			int idNumber;
			int age;
			string job;
			int hireYear;
			getline(ifs, name, '|');
			getline(ifs, temporaryVariable, '|');
			idNumber = stoi(temporaryVariable);
			getline(ifs, temporaryVariable, '|');
			age = stoi(temporaryVariable);
			getline(ifs, job, '|');
			getline(ifs, temporaryVariable);
			hireYear=stoi(temporaryVariable);
			
			list[i] = new Employee(name, idNumber, age,job,hireYear);
			//idList[i] = new Employee(idNumber);

		}
		ifs.close();


		//bubbleSort(n);
		insertionSort(n);

		// output code

		/*ofstream ofs;
		ofs.open("output.txt", ios::out);

		for (int fileIndex = 2; fileIndex <=n; fileIndex++) {
			list[fileIndex]->writeFile(ofs);
		}
		/*for (int i = 0; i < n; i++) {
			//list[i]->printEmployee();
			idList[i]->printEmployeeID();
		}*/
	}


	}
	

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

	// This is the code block for query file
	/*
	ifs.open(argv[2], ios::in);
	if (!ifs) {
		cout << "Error! Please check filename for the query file." << endl;
		exit(0);
	}
	else {
		double total=0;
		string tempVar;
		getline(ifs, tempVar);
		int numberOfQueries = stoi(tempVar);


		for (int j = 0; j < numberOfQueries;j++) {

			getline(ifs,tempVar);

			// the currentID is the current line the program is reading
			int currentID = stoi(tempVar);
			int index = lookUp(currentID, n);
			//int numberOfComaparisons = index+ 1;
			total += numberOfBinaryComparison;

			cout << "Looking for " << currentID <<"..." << "Found "<< list[index]->getName()<<"at position "<< index <<" after "<<numberOfBinaryComparison<< " of comparisons." <<endl;

		}
		double averageQueries = total / numberOfQueries;
		cout<<"Average number of comparisons overall : " << averageQueries<<endl;

	}*/
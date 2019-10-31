/*
Program No.         : Farmer_Garcia_Elliot_H6.cpp
Programmer          : Elliot Farmer Garcia
Course / Section    : ELET 2300 - 07 / 23493
Instructor          : Dr. F. Attarzadeh
Date Assigned       : 10/31/2019
Date Modified       : 10/31/2019
Due Date            : 11/12/2019
Compiler            : Microsoft Visual Studio Enterprise 2019
Environment         : Console Applications
Operating System    : Windows 7
*/

/*
Problem Statement
This is a menu-driven program allowing the user to select various operations
to be performed on 1 or 2 integers. The user selects the group of operations
they wish to use by entering the operation's initial, followed by a 1 or 2
to indicate the particular operation they wish to perform, and finally
enter the two integers they wish to perform the operation on.
The operations are separated into Arithmetic (addition and multiplication),
Relational (!= and >=), and Logical (AND and OR), as well as a Help section.
Q to Quit.
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void help(void);
void smallest(float s[], int size);
int sizeOfArray(void);
float findSmallest(float s[], int myS);
int frequency(float s[], float smallestNo, int myS);
void display(float s[], float smallestNo, int freq, int myS);


//main() simply calls menu(). The program is exited when char op is set to
//'q' or 'Q' in menu().
int main(void) {

	system("cls");  //clears terminal screen

	//variable set by user to call the desired operation
	char op;
	
	float s[12];

	//strings for menu handling
	string menu = "\n\tHelp\t\tSmallest\tQuit\n\n";
	string prompt = "Please enter the initial of your desired operation: ";
	string inv = "Invalid selection.\n";

	//loop runs until 'q' or 'Q' is selected
	while (true) {

		//prints menu and asks user for menu selection
		cout << menu;
		cout << prompt;
		cin >> op;
		cout << "\n";

		//menu selection is evaluated
		switch (op) {

			//help has been selected
		case 'h':
		case 'H':
			help();
			break;

			//arithmetic has been selected
		case 's':
		case 'S':
			smallest(s, sizeOfArray());
			break;

			//quit program has been selected
		case 'q':
		case 'Q':
			system("cls");  //clears terminal screen
			return 0;       //exits program

		default:
			cout << inv;

		}

	}

}

//menu() is responsible for printing the menu, acquiring an operation
//selection from the user, calling the appropriate operation function,
//and error checking.

//prints a brief explanation of the program and its various operations
void help(void) {

	string help = "This program will evaluate various operations based on "
		"the menu selection.\nEntering 'A' or 'a' accesses the '+' or '*' "
		"operations.\nEntering 'R' or 'r' accesses the '!=' or '>=' "
		"operations.\nEntering 'L' or 'l' accesses the 'AND' or 'OR' "
		"operations.\nEntering 'Q' or 'q' will exit the program.\n\n";


	cout << help;
	system("pause");    //waits for user to press a key before continuing
	system("cls");
	return;
}

void smallest(float s[], int size) {
	double min, max;

	cout << "Please enter minimum value for array: ";
	cin >> min;

	cout << "Please enter maximum value for array: ";
	cin >> max;
	
	for (int i = 0; i < size; i++)
		s[i] = min + (rand() / (RAND_MAX / (max - min)));

	float smallestNo = findSmallest(s, size);
	int freq = frequency(s, smallestNo, size);
	display(s, smallestNo, freq, size);

	return;
}

int sizeOfArray(void) {

	int i;

	while (true) {
		cout << "Please enter integer value for array size (must be >0 and <=12): ";
		cin >> i;
		
		if ((i > 0) && (i <= 12))
			break;
		cout << "Integer must be > 0 and <= 12.\n";
	}

	return i;

}

float findSmallest(float s[], int myS) {

	float smallestNo = s[0];

	for (int i = 1; i < myS; i++) {
		if (s[i] < smallestNo)
			smallestNo = s[i];
	}

	return smallestNo;

}

int frequency(float s[], float smallestNo, int myS) {

	int freq = 0;

	for (int i = 0; i < myS; i++) {
		if (smallestNo == s[i])
			freq++;
	}

	return freq;

}


//lower right
void display(float s[], float smallestNo, int freq, int myS) {
	
	for (int i = 0; i < myS; i++)
		cout << setprecision(2) << "s[" << i << "] = " << s[i] << "\n";

	cout << setprecision(2) << "Smallest no. = " << smallestNo << "\tFrequency: "
		<< freq << "\n\t\t\t\tStrike any key to continue...";
	
	cin.get();
	system("cls");
	return;

}
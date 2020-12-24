#include <iostream>
#include <string>
#include "StringHandle.h"

using namespace std;

int main() {
	string input;
	int choice;
	cout << "Examples" << endl;
	cout << "This examples shows different types of wrong input-----------------------------------------------------------------------------" << endl;
	StringHandle("");
	StringHandle(" ");
	StringHandle("02");
	StringHandle(".02");
	StringHandle("a");
	StringHandle("h");
	StringHandle("sin");
	StringHandle("pin");
	StringHandle("pi3");
	StringHandle("(");
	StringHandle(")");
	StringHandle("()");
	StringHandle("()()()");
	StringHandle("((((()))))");
	StringHandle("((2+3)");
	StringHandle("(2+3))");
	StringHandle("sinsinsin(4)");
	StringHandle("1.1.1");
	cout << "This examples shows different types correct input -----------------------------------------------------------------------------" << endl;
	StringHandle("sqrt(sinh(e))");
	StringHandle("e*pi");
	StringHandle("2/((2+3)*2+-10)");
	StringHandle("-64");
	StringHandle("sqrt(sinh(e))");
	StringHandle("101.0101");
	StringHandle("1");
	StringHandle("((2-3)/(2+-3))");
	StringHandle("-9^-1");
	cout << "Now you can process you own string -------------------------------------------------------------------------------------------" << endl;
	cout << "Enter 1 to process your string" << endl;
	cout << "Enter anything except 1 to break" << endl;

	do {
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter your string" << endl;
			cin >> input;
			StringHandle(input);
			cout << "Enter 1 to process your string" << endl;
			cout << "Enter anything except 1 to break" << endl;
		default:
			break;
		}
	} while (choice == 1);

	return 0;
}


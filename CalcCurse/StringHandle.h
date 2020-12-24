#pragma once
#include <iostream>
#include <string>
#include "InfixToPostfix.h"
#include "SyntaxAnalyzer.h"

void StringHandle(string input) {
	string infix = input;
	string postfix;
	SyntaxAnalyzer isCorrectExpression;
	cout << "Entered string:" << endl;
	cout << input << endl;
	try {
		if (isCorrectExpression.CheckExpression(infix)) {
			postfix = InfixToPostfix(infix);
			cout << "Note that ~ stands for unary minus" << endl;
			cout << "Postfix form of expression is:" << endl;
			cout << postfix << endl;
			cout << "Note that result is rounded to 3 decimal places or represented in scientific form" << endl;
			cout << "Result is: ";
			cout << solve(postfix) << endl;
			cout << endl;
		}
	}
	catch (invalid_argument exception) {
		cout << exception.what() << endl;
		cout << endl;
	}
}
#pragma once
#include <string>
#include <iostream>
#include "Stack.h"
#include "Check.h"

using namespace std;

// 1 = true
// 0 = false
// 2 = checkFunction
// 3 = checkZero
// 4 = checkDot
class SyntaxAnalyzer {
private:
	size_t Alphabet[33][33] = {                         /*Second*/
		   // 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, (, ), *, /, +, -, ^, c, s, t, o, i, g, n, q, r, l, p, e, h, x, .,  ,
		/*0*/{3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},//
		/*1*/{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},//
		/*2*/{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},//
		/*3*/{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},//
		/*4*/{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},//
		/*5*/{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},//
		/*6*/{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},//
		/*7*/{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},//
		/*8*/{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},//
/*f*/	/*9*/{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},//
/*i*/	/*(*/{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0},//
/*r*/	/*)*/{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},//
/*s*/	/***/{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0},//
/*t*/	/*/*/{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0},//
		/*+*/{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0},//
		/*-*/{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0},//
		/*^*/{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0},//
		/*c*/{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2},//
		/*s*/{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 2},//
		/*t*/{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},//
		/*o*/{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},//
		/*i*/{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 2},//
		/*g*/{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2},//
		/*n*/{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2},//
		/*q*/{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 2},//
		/*r*/{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},//
		/*l*/{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 2},//
		/*p*/{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},//
		/*e*/{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 2},//
		/*h*/{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},//
		/*x*/{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 2},//
		/*.*/{4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},//
		/* */{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},//
	};
	size_t CanChangeState(char first, char second){
		return Alphabet[GetState(first)][GetState(second)];
	}
	size_t GetState(char symbol){
		switch (symbol){
		case '0': return 0;
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
		case '(': return 10;
		case ')': return 11;
		case '*': return 12;
		case '/': return 13;
		case '+': return 14;
		case '-': return 15;
		case '^': return 16;
		case 'c': return 17;
		case 's': return 18;
		case 't': return 19;
		case 'o': return 20;
		case 'i': return 21;
		case 'g': return 22;
		case 'n': return 23;
		case 'q': return 24;
		case 'r': return 25;
		case 'l': return 26;
		case 'p': return 27;
		case 'e': return 28;
		case 'h': return 29;
		case 'x': return 30;
		case '.': return 31;
		case ' ': return 32;
		default: return -1;
		}
	}
public:
	bool CheckExpression(string expression) {
		if (expression.empty()) {
			cout << "Empty string" << endl;
			throw invalid_argument("Invalid input");
			return false;
		}
		if (expression[0] == '.' || !isAlphabet(expression[0]) || expression[0] == ')' || expression[0] == ' ') {
			cout << "First symbol went wrong" << endl;
			throw invalid_argument("Invalid input");
			return false;
		}
		Stack<char> expr;
		string tmp;
		bool ErrorFunction = false;
		bool ErrorSymbol = false;
		bool Bracket = true;
		size_t dots = 0;
		size_t ErrorPosition;
		expression += ' ';
		for (auto i = 0; i < expression.length() - 1; i++) {
			if (dots > 1) {
				ErrorPosition = i - 2;
				ErrorSymbol = true;
				break;
			}
			if (isAlphabet(expression[i]) && isAlphabet(expression[i + 1])) {
				if (CanChangeState(expression[i], expression[i + 1]) == 1) {
					expr.push(expression[i]);
					if (isMark(expression[i])) {
						dots = 0;
					}
				}
				else if (CanChangeState(expression[i], expression[i + 1]) == 2) {
					expr.push(expression[i]);
					while (!expr.isEmpty()) {
						if (expr.peek() != '(' && !isMark(expr.peek())) {
							tmp += expr.pop();
						}
						else {
							break;
						}
					}
					if (isFunction(tmp) && expression[i + 1] == '(' || isConst(tmp)) {
						tmp.clear();
					}
					else {
						ErrorFunction = true;
						ErrorPosition = i;
						break;
					}
				}
				else if (CanChangeState(expression[i], expression[i + 1]) == 3) {
					expr.push(expression[i]);
					while (expr.peek() != '.' && expr.peek() == '0') {
						if (!isdigit(expr.peek())) {
							ErrorPosition = i;
							ErrorSymbol = true;
							break;
						}
						else {
							expr.pop();
							if (expr.isEmpty()) {
								ErrorPosition = i;
								ErrorSymbol = true;
								break;
							}
						}
					}
				}
				else if (CanChangeState(expression[i], expression[i + 1]) == 4) {
					dots++;
				}
				else {
					ErrorPosition = i;
					ErrorSymbol = true;
					break;
				}
			}
			else {
				cout << expression << endl;
				if (isAlphabet(expression[i + 1]))
					i++;
				for (auto j = 0; j < i + 1; j++)
					cout << " ";
				cout << "^" << endl;
				for (auto j = 0; j < i + 1; j++)
					cout << " ";
				cout << "|" << "Wrong Symbol" << endl;
				throw invalid_argument("Invalid input");
				return false;
			}
			if (expression[i + 1] == ')') {
				expr.push(expression[i]);
					while (!expr.isEmpty()) {					
						if (expr.peek() == '(') {
							Bracket = true;
							expr.pop();
							break;
						}
						else {
							Bracket = false;
							expr.pop();
						}
					}
			}
			if (!Bracket) {
				cout << expression << endl;
				cout << "Expression has missmatched brackets" << endl;
				throw invalid_argument("Invalid input");
				return false;
			}
		}
		if (ErrorSymbol) {
			cout << expression << endl;
			for (auto j = 0; j < ErrorPosition + 1; j++)
				cout << " ";
			cout << "^" << endl;
			for (auto j = 0; j < ErrorPosition + 1; j++)
				cout << " ";
			cout << "|" << "Wrong Symbol" << endl;
			throw invalid_argument("Invalid input");
			return false;
		}
		if (ErrorFunction) {
			cout << expression << endl;
			if (ErrorPosition <= 0) {
				ErrorPosition = 1;
			}
			for (auto j = 0; j < ErrorPosition - 1; j++)
				cout << " ";
			cout << "^^" << endl;
			for (auto j = 0; j < ErrorPosition - 1; j++)
				cout << " ";
			cout << "||" << "Something wrong with this function" << endl;
			throw invalid_argument("Invalid input");
			return false;
		}
		while (!expr.isEmpty()) {
			if (expr.peek() == '(') {
				cout << expression << endl;
				cout << "Expression has missmatched brackets" << endl;
				throw invalid_argument("Invalid input");
				return false;
			}
			expr.pop();
		}
		expression.pop_back();
		return true;
	}
};
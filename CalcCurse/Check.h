#pragma once
#include <string>
using namespace std;
bool isMark(char symbol) { // является ли знаком
	if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^' || symbol == '~')
		return true;
	else
		return false;
}

bool isNumber(string expression) {
	if (expression[0] == '0' || expression[0] == '1' || expression[0] == '2' || expression[0] == '3' || expression[0] == '4' || expression[0] == '5' || expression[0] == '6' || expression[0] == '7' || expression[0] == '8' || expression[0] == '9')
		return true;
	else
		return false;
}

bool isNumber(char symbol) {
	if (symbol == '0' || symbol == '1' || symbol == '2' || symbol == '3' || symbol == '4' || symbol == '5' || symbol == '6' || symbol == '7' || symbol == '8' || symbol == '9')
		return true;
	else
		return false;
}

bool isFunction(string expression) {
	if (expression == "nis") return true;		//sin
	else if (expression == "soc") return true;  //cos
	else if (expression == "gt") return true;   //tg
	else if (expression == "gtc") return true;  //ctg
	else if (expression == "hnis") return true; //sinh
	else if (expression == "hsoc") return true; //cosh
	else if (expression == "hgt") return true;  //tgh
	else if (expression == "hgtc") return true; //ctgh
	else if (expression == "csc") return true;  //csc
	else if (expression == "hcsc") return true; //csch
	else if (expression == "ces") return true;  //sec
	else if (expression == "hces") return true; //sech
	else if (expression == "pxe") return true;  //exp
	else if (expression == "nl") return true;   //ln
	else if (expression == "gol") return true;  //log
	else if (expression == "trqs") return true; //sqrt
	else return false;
}

bool isConst(string expression) {
	if (expression == "ip") return true;		//pi
	else if (expression == "e") return true;    //e
	else return false;
}

bool isAlphabet(char symbol) {
	switch (symbol) {
	case '0': return true;
	case '1': return true;
	case '2': return true;
	case '3': return true;
	case '4': return true;
	case '5': return true;
	case '6': return true;
	case '7': return true;
	case '8': return true;
	case '9': return true;
	case '(': return true;
	case ')': return true;
	case '*': return true;
	case '/': return true;
	case '+': return true;
	case '-': return true;
	case '^': return true;
	case 'c': return true;
	case 's': return true;
	case 't': return true;
	case 'o': return true;
	case 'i': return true;
	case 'g': return true;
	case 'n': return true;
	case 'q': return true;
	case 'r': return true;
	case 'l': return true;
	case 'p': return true;
	case 'e': return true;
	case 'h': return true;
	case 'x': return true;
	case '.': return true;
	case ' ': return true;
	default: return false;
	}
}
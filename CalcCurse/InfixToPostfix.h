#pragma once
#include "Stack.h"
#include "AdditionalTrig.h"
#include <string>
#include <cmath>
#include <iostream>
#include "Check.h"

constexpr auto E = 2.71828182845904523536028747135266249775724709369995;
constexpr auto PI = 3.14159265358979323846264338327950288419716939937510;

using namespace std;

int operation_order(char mark) {
	if (mark == '~')
		return 0;
	else if (mark == '^')
		return 1;
	else if (mark == '*' || mark == '/')
		return 2;
	else if (mark == '+' || mark == '-')
		return 3;
}

string InfixToPostfix(string infix_expression) {
	string postfix_expression; // результат
	Stack<char> Marks; // стэк дл€ знаков
	bool unary_first = false;
	for (auto i = 0; i < infix_expression.length(); i++) { //прохожу по каждому символу выражени€
		if (isMark(infix_expression[i])) { // если знак
			if (i - 1 < 0 && infix_expression[i] == '-') //если перва€ опреаци€ унарный минус
				unary_first = true;
			switch (unary_first)
			{
			case true:
				Marks.push('~'); //унарный минус в стэк
				unary_first = false;
				break;
			case false:
				if (infix_expression[i] == '-' && infix_expression[i - 1] == ')' || infix_expression[i - 1] == '(' || isMark(infix_expression[i - 1])) // если унарный минус
					Marks.push('~');	//унарный минус в стэк
				else {
					while (!Marks.isEmpty() && operation_order(Marks.peek()) <= operation_order(infix_expression[i])) { // пока не пустой стэк и текущее действие менее приоритетно чем последнее в стэке
						postfix_expression += Marks.pop(); // вывожу действи€
						postfix_expression += ' ';
					}
					Marks.push(infix_expression[i]); // добавл€ю текущее в стэк
				}
				break;
			}
		}
		//если функци€ одной переменной
		else if (infix_expression[i] == 's' || infix_expression[i] == 'c' || infix_expression[i] == 't' || infix_expression[i] == 'l' || infix_expression[i+1] == 'x') {
			switch (infix_expression[i]) { //определ€ю что за функци€
				case 's': {
					if (infix_expression[i + 1] == 'i') {
						if (infix_expression[i + 3] == 'h') {
							Marks.push('h'); //функцию в стек //sinh
							Marks.push('n');
							Marks.push('i');
							Marks.push('s');
							i += 3; //сдвигаю до открытой круглой скобки
						}
						else {
							Marks.push('n'); //sin
							Marks.push('i');
							Marks.push('s');
							i += 2;
						}
					}
					else if (infix_expression[i + 1] == 'e'){
						if (infix_expression[i + 3] == 'h') {
							Marks.push('h'); //sech
							Marks.push('c');
							Marks.push('e');
							Marks.push('s');
							i += 3;
						}
						else {
							Marks.push('c'); //sec
							Marks.push('e');
							Marks.push('s');
							i += 2;
						}
					}
					else {
						Marks.push('t'); //sqrt
						Marks.push('r');
						Marks.push('q');
						Marks.push('s');
						i += 3;
					}
					break;
				}
				case 'c': {
					if (infix_expression[i + 1] == 'o') {
						if (infix_expression[i + 3] == 'h') {
							Marks.push('h'); //cosh
							Marks.push('s');
							Marks.push('o');
							Marks.push('c');
							i += 3;
						}
						else {
							Marks.push('s'); //cos
							Marks.push('o');
							Marks.push('c');
							i += 2;
						}
					}
					else if (infix_expression[i + 1] == 's') {
						if (infix_expression[i + 3] == 'h') {
							Marks.push('h'); //csch
							Marks.push('c');
							Marks.push('s');
							Marks.push('c');
							i += 3;
						}
						else {
							Marks.push('c'); //cosec
							Marks.push('s');
							Marks.push('c');
							i += 2;
						}
					}
					else {
						if (infix_expression[i + 3] == 'h') {
							Marks.push('h');
							Marks.push('g'); //ctgh
							Marks.push('t');
							Marks.push('c');
							i += 3;
						}
						else {
							Marks.push('g'); //ctg
							Marks.push('t');
							Marks.push('c');
							i += 2;
						}
					}
					break;
				}
				case 't': { // tg
					Marks.push('g');
					Marks.push('t');
					i += 1;
					break;
				}
				case 'l': {
					if (infix_expression[i + 1] == 'n') {
						Marks.push('n'); //ln
						Marks.push('l');
						i += 1;
					}
					else {
						Marks.push('g'); //log
						Marks.push('o');
						Marks.push('l');
						i += 2;
					}
				}
				case 'e': { // exp
					if (infix_expression[i + 1] == 'x') {
						Marks.push('p');
						Marks.push('x');
						Marks.push('e');
						i += 2;
						break;
					}
					else
						break;
				}
			}
		}  
		else if (infix_expression[i] == '(') // если открыта€ скобка
			Marks.push(infix_expression[i]); // засовываю в стэк
		else if (infix_expression[i] == ')') { // если закрыта€ скобка
			while (Marks.peek() != '(') { // пока не найду открытую в стеке
				postfix_expression += Marks.pop(); //вывожу содержимое стэка
				postfix_expression += ' ';
			}
			Marks.pop(); // удал€ю открытую скобку из стэка
			if (!Marks.isEmpty()) {
				if (Marks.peek() == 's' || Marks.peek() == 'c' || Marks.peek() == 't' || Marks.peek() == 'l' || Marks.peek() == 'e') {
					while (Marks.peek() != '(' && !isMark(Marks.peek())) {
						postfix_expression += Marks.pop(); //вывожу содержимое стэка   // вывод функции
						if (Marks.isEmpty())
							break;
					}
					postfix_expression += ' ';
				}			
			}
		}
		else { // во всех остальных случа€х
			while (infix_expression[i] != ')' && infix_expression[i] != '(' && !isMark(infix_expression[i]) && infix_expression[i] != 's' && infix_expression[i] != 'c' && infix_expression[i] != 't' && infix_expression[i] != 'l') {
				if (infix_expression[i] == 'e' && infix_expression[i + 1] != 'x' || i + 1 >= infix_expression.length()) {
					postfix_expression += infix_expression[i]; // вывожу e
					i++;
					break;
				}
				else if (infix_expression[i] == 'p' && infix_expression[i + 1] == 'i') {
					postfix_expression += infix_expression[i]; // вывожу pi
					postfix_expression += infix_expression[i + 1];
					i += 2;
					break;
				}
				else {
					postfix_expression += infix_expression[i]; // вывожу текущий символ
					i++;
				}	
			}
			postfix_expression += ' ';
			i--;
		}
	}	
	while (!Marks.isEmpty()) { // пока не пустой стэк
		postfix_expression += Marks.pop(); // вывожу все из стэка
		postfix_expression += ' ';
	}
	return postfix_expression;
}

double solve(string postfix_expression) {
	Stack<double> numbers;
	double num; // result of stod() function
	double left, right; //values for counting
	bool isResult = false;
	bool DivisionByZero = false;
	bool FunctionError = false;
	float ErrorLeft = 0;
	float ErrorRight = 0;
	size_t NoISTP = 0; //number of important string parts // equivalent to number of spaces
	string empty;
	string temp;
	size_t position = 0;

	for (auto i = 0; i < postfix_expression.length(); i++)
		if (postfix_expression[i] == ' ')
			NoISTP++;
	
	for (auto i = 0; i < NoISTP; i++) {
		while (postfix_expression[position] != ' ') {
			temp += postfix_expression[position];
			position++;
		}
		position++;
		if (isNumber(temp)) {
			num = stod(temp);
			numbers.push(num);
		}
		else {
			switch (temp.length())
			{
			case 1: //operator
				switch (temp[0])//operator value
				{
				case '+':
					right = numbers.pop();
					left = numbers.pop();
					numbers.push(left + right);
					break;
				case '-':
					right = numbers.pop();
					left = numbers.pop();
					numbers.push(left - right);
					break;
				case '*':
					right = numbers.pop();
					left = numbers.pop();
					numbers.push(left * right);
					break;
				case '/':
					right = numbers.pop();
					left = numbers.pop();
					if (right != 0)
						numbers.push(left / right);
					else {
						DivisionByZero = true;
						break;
					}
					break;
				case '~':
					right = numbers.pop();
					numbers.push(right * -1);
					break;
				case 'e':
					numbers.push(E);
					break;
				case '^':
					right = numbers.pop();
					left = numbers.pop();
					numbers.push(pow(left, right));
					break;
				}
				break;
			case 2: //ln, tg
				switch (temp[0])//operator value
				{
				case 'l':
					right = numbers.pop();
					if (right >= 0)
						numbers.push(log(right));
					else {
						FunctionError = true;
						break;
					}
					break;
				case 't':
					right = numbers.pop();
					numbers.push(tan(right));
					break;
				case 'p':
					numbers.push(PI);
					break;
				}
				break;
			case 3:
				switch (temp[0])//operator value
				{
				case 's':
					switch (temp[1])//operator value
					{
					case 'i':
						right = numbers.pop();
						numbers.push(sin(right));
						break;
					case 'e':
						right = numbers.pop();
						numbers.push(sec(right));
						break;
					}
					break;
				case 'c':
					switch (temp[1])//operator value
					{
					case 'o':
						right = numbers.pop();
						numbers.push(cos(right));
						break;
					case 't':
						right = numbers.pop();
						numbers.push(ctg(right));
						break;
					case 's':
						right = numbers.pop();
						numbers.push(csc(right));
						break;
					}
					break;
				case 't':
					right = numbers.pop();
					numbers.push(tanh(right));
					break;
				case 'e':
					right = numbers.pop();
					numbers.push(exp(right));
					break;
				case 'l':
					right = numbers.pop();
					if (right >= 0)
						numbers.push(log10(right));
					else {
						FunctionError = true;
						break;
					}
					break;
				}
				break;
			case 4:
				switch (temp[0])//operator value
				{
				case 's':
					switch (temp[1])//operator value
					{
					case 'i':
						right = numbers.pop();
						numbers.push(sinh(right));
						break;
					case 'e':
						right = numbers.pop();
						numbers.push(sech(right));
						break;
					case 'q':
						right = numbers.pop();
						numbers.push(sqrt(right));
						break;
					}
					break;
				case 'c':
					switch (temp[1])//operator value
					{
					case 'o':
						right = numbers.pop();
						numbers.push(cosh(right));
						break;
					case 't':
						right = numbers.pop();
						numbers.push(ctgh(right));
						break;
					case 's':
						right = numbers.pop();
						numbers.push(csch(right));
						break;
					}
					break;
				}
				break;
			}
		}
		if (!FunctionError)
			temp = empty;
	}
	if (DivisionByZero) {
		cout << "Division by zero" << endl;
		cout << left << " / 0" << endl;;
		throw invalid_argument("Computation error");
		return right;
	}
	if (FunctionError) {
		cout << "Function Error" << endl;
		for (auto i = 0; i < temp.length(); i++)
			cout << temp[i];
		cout << " from 0" << endl;
		throw invalid_argument("Computation error");
		return right;
	}
	double result = round(numbers.pop()*1000)/1000;
	return result;
}

//Rita (Eteri) Sachechelashvili
//1928162
//sache100@mail.chapman.edu
//CPSC-350-02
//Assignment 3
//purpose of this file is to serve as the implementaion file for the program

#include "Syntax.h"
using namespace std;
//method that returns an opposite delimiter based on the current delimiter on top of the stack
char Syntax::opposite(char current) {
	char opposite;
	if (current == '(') {
		opposite = ')';
	}
	else if (current == '{') {
		opposite = '}';
	}
	else {
		opposite = ']';
	}
	return opposite;

}


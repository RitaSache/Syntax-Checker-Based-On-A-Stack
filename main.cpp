//Rita (Eteri) Sachechelashvili
//1928162
//sache100@mail.chapman.edu
//CPSC-350-02
//Assignment 3
//purpose of this file is to serve as the main file for the program.

#include <iostream>
#include "GenStack.h"
#include "Syntax.h"
#include <fstream>

using namespace std;
//method checkSyntax accepts a file as an argument or an input, checks for missing or extra delimiters
//prints status of the file and asks for another file
void checkSyntax(string fileName);
//main method calls for the checkSyntax method with the argument file
int main(int argc, char **argv) {

if (argc > 1) {
	checkSyntax(argv[1]);
	return 0;
}
else {
	cout << "Invalid input" << endl;
}
}
//description on lines 14-15
void checkSyntax(string fileName) {
	string anotherFile;
	int lineCounter = 0;
	char opposite;
	Syntax c;
	string response;
	GenStack<char> syntax(10);
	
	ifstream inputFile;
	inputFile.open(fileName);
	if(!inputFile) {
		cout << "File was not found, exiting program" << endl;
		exit(0);
	}
	string line;
	while (getline(inputFile,line)) {
		lineCounter++;
		for (int i = 0; i < line.size(); i++) {
			if (line[i] == '(' || line[i] == '{' || line[i] == '[') {
				cout << "Line " << lineCounter << " push " << line[i] << endl;
				syntax.push(line[i]);
				opposite = c.opposite(line[i]);
			}
			if (line[i] == ')' || line[i] == '}' || line[i] == ']') {
				if(syntax.isEmpty()) {
					cout << "Line " << lineCounter << ": extra " << line[i] << endl;
					exit(0);
				}
				else if(line[i] != opposite) {
					cout << "Line " << lineCounter << ": expected " << opposite << " and found " << line[i] << endl;
					exit(0);
				}
				else {
					cout << "Line " << lineCounter << " pop " << opposite << endl;
					syntax.pop();
					opposite = c.opposite(syntax.peek());
				}
			}
		}
	}
	inputFile.close();
	for (int i = 0; i < syntax.top; i++) { 
			cout << syntax.myArray[i];
		}
	cout << endl;

	if(!syntax.isEmpty()) {
		opposite = c.opposite(syntax.peek());
		cout << "Reached the end of the file, missing " << opposite << endl;
		exit(0);
	}
	else {
		cout << "delimeter syntax is correct, do you want to process another file? (yes),(no)" << endl;
		cin >> response;

		if (response == "yes") {
			cout << "please provide file name path " << endl;
			cin >> anotherFile;
			checkSyntax(anotherFile);
		}
		else if (response == "no") {
			exit(0);
		}
		else {
			cout << "Invalid response, exiting program" << endl;
			exit(0);
		}
	}
}



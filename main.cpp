#include <iostream>
#include "GenStack.h"
#include "Syntax.h"
#include <fstream>

using namespace std;

void checkSyntax(string fileName);

int main(int argc, char **argv) {

if (argc > 1) {
	checkSyntax(argv[1]);
	return 0;
}
else {
	cout << "Invalid input" << endl;
}
}

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



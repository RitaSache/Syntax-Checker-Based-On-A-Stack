#include <iostream>
#include "GenStack.h"
#include "Syntax.h"
#include <fstream>

using namespace std;

int main(int argc, char **argv) {

int lineCounter = 0;
char current;
char opposite;

GenStack<char> curly(10);
GenStack<char> squared(10);
GenStack<char> regular(10);

if (argc > 1) {
	ifstream inputFile;
	inputFile.open(argv[1]);
	string line;
	while (getline(inputFile,line)) {
		lineCounter++;
		for (int i = 0; i < line.size(); i++) {
			if (line[i] == '(') {
				regular.push(line[i]);
				current = '(';
				opposite = ')';
			}
			if (line[i] == ')') {
				if(regular.isEmpty()) {
					cout << "Line " << lineCounter << ": extra )" << endl;
				}
				else if(current != '(') {
					cout << "Line " << lineCounter << ": expected " << opposite << " and found )" << endl;
				}
				else {
					regular.pop();
				}

			}
			if (line[i] == '{') {
				curly.push(line[i]);
				current = '{';
				opposite = '}';
			}
			if (line[i] == '}') {
				if (curly.isEmpty()) {
					cout << "Line " << lineCounter << ": extra }" << endl;
				}
				else if(current != '{') {
					cout << "Line " << lineCounter << ": expected " << opposite << " and found }" << endl;
				}
				else {
					curly.pop();
				}
			}
			if (line[i] == '[') {
				squared.push(line[i]);
				current = '[';
				opposite = ']';
			}
			if (line[i] == ']') {
				if(squared.isEmpty()) {
					cout << "Line " << lineCounter << ": extra ]" << endl;	
				}
				else if(current != '[') {
					cout << "Line " << lineCounter << ": expected " << opposite << " and found ]" << endl;
				}
				else {
					squared.pop();
				}
			}
			
		}
	}
	inputFile.close();
	if(!regular.isEmpty()) {
		cout << "Reached the end of the file, missing )" << endl;
	}
	if(!curly.isEmpty()) {
		cout << "Reached the end of the file, missing }" << endl; 
	}
	if(!squared.isEmpty()) {
		cout << "Reached the end of the file, missing ]" << endl;
	}
}
	

	for (int i = 0; i < regular.top; i++) { 
			cout << regular.myArray[i];
		}
	cout << endl;
	return 0;
}
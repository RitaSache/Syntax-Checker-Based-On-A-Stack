#include <iostream>
#include "GenStack.h"
#include "Syntax.h"
#include <fstream>

using namespace std;

int main(int argc, char **argv) {

int lineCounter = 0;
char opposite;
Syntax c;
GenStack<char> syntax(10);

if (argc > 1) {
	ifstream inputFile;
	inputFile.open(argv[1]);
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
	if(!syntax.isEmpty()) {
		opposite = c.opposite(syntax.peek());
		cout << "Reached the end of the file, missing " << opposite << endl;
	}
}
	

	for (int i = 0; i < syntax.top; i++) { 
			cout << syntax.myArray[i];
		}
	cout << endl;
	return 0;
}
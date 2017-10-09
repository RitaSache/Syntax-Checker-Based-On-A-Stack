#include "Syntax.h"
using namespace std;

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
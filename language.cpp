#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>       /* sqrt */
#include <stdlib.h>
#include <string.h>
/*
	A language made by henry wildermuth, both interpreter and written in files.
*/


static const double pi = 3.1415926536;
static const double e = 2.7182818285;

int pow(int a, int b) {
	if (b < 1)
		return 0;
	if (b ==1 )
		return a;
	return pow(a*a, b-1);
}

void notEnoughItems() {
	std::cout << "The stack does not have enough items." << std::endl;
}

void swap(std::vector<double> & stack) {
	int temp= stack[stack.size()-1];
	stack[stack.size()-1] = stack[stack.size()-2];
	stack[stack.size()-2] = temp;
}

void dup(std::vector<double> & stack) {
	stack.push_back(stack.back());
}

void drop(std::vector<double> & stack) {
	stack.erase(stack.begin() + stack.size() -1);
}

void reset(std::vector<double> & stack) {
	stack.clear();
}

void rot(std::vector<double> & stack) {
	stack.push_back(stack[stack.size()-3]);
	stack.erase(stack.begin() + stack.size() -4);
}

void add(std::vector<double> & stack) {
	stack[stack.size()-1] = stack[stack.size()-2] + stack[stack.size()-1];
	stack.erase(stack.begin() + stack.size()-2);
}

void sub(std::vector<double> & stack) {
	stack[stack.size()-1] = stack[stack.size()-2] - stack[stack.size()-1];
	stack.erase(stack.begin() + stack.size()-2);
}

void mult(std::vector<double> & stack) {
	stack[stack.size()-1] = stack[stack.size()-2] * stack[stack.size()-1];
	stack.erase(stack.begin() + stack.size()-2);
}

void div(std::vector<double> & stack) {
	stack[stack.size()-1] = stack[stack.size()-2] / stack[stack.size()-1];
	stack.erase(stack.begin() + stack.size()-2);
}

void exp(std::vector<double> & stack) {
	stack[stack.size()-1] = pow(stack[stack.size()-2] , stack[stack.size()-1] );
	stack.erase(stack.begin() + stack.size()-2);
}

void print(std::vector<double> & stack) {
	std::cout << stack.back() << std::endl;
}

void sqrt(std::vector<double> & stack) {
	stack.back() = sqrt(stack.back());
}

void printStack(std::vector<double> & stack) {
	std::cout << "{";
	for (int i = 0; i < stack.size(); i++) {
		if (i != 0 ) std::cout << ", ";
		std::cout << stack[i];
	}
	std::cout << "}" << std::endl;
}

int main(int argc, char *argv[]) {
	if (argc > 2) {
		std::cout << "Usage: " << std::endl;
		std::cout << "\t" << argv[0] << " (for interpreter)" << std::endl;
		std::cout << "\t" << argv[0] << " <filename>" << std::endl;
		return 1;
	}

	std::vector<double> stack;
	std::ifstream file;

	char * joe = (char * ) malloc(1024);

	bool using_cin = (argc == 2) ? false : true;

	if (!using_cin) {
		file.open(argv[1]);
	} else {
		std::cout << "Language v0.0.1 Prompt" << std::endl;
	}

	while (true) {
		if (using_cin) {
			std::cin >> joe;
		} else {
			file >> joe;
		}
		if (!strcmp(joe,  "swap")) {
			if (stack.size() > 1)
				swap(stack);
			else
				notEnoughItems();
		}
		else if (!strcmp(joe,  "dup")) {
			if (stack.size() > 1)
				dup(stack);
			else
				notEnoughItems();
		}
		else if (!strcmp(joe,  "rot")) {
			if (stack.size() > 1)
				rot(stack);
			else
				notEnoughItems();
		}
		else if (!strcmp(joe,  "add") || !strcmp(joe,  "+")) {
			if (stack.size() > 1)
				add(stack);
			else
				notEnoughItems();
		}
		else if (!strcmp(joe,  "sub") || !strcmp(joe,  "-")) {
			if (stack.size() > 1)
				sub(stack);
			else
				notEnoughItems();
		}
		else if (!strcmp(joe,  "mult") || !strcmp(joe,  "*")) {
			if (stack.size() > 1)
				mult(stack);
			else
				notEnoughItems();
		}
		else if (!strcmp(joe,  "div") || !strcmp(joe,  "/")) {
			if (stack.size() > 1)
				div(stack);
			else
				notEnoughItems();
		}
		else if (!strcmp(joe,  "exp") || !strcmp(joe,  "^") || !strcmp(joe,  "pow")){
			if (stack.size() > 1)
				exp(stack);
			else
				notEnoughItems();
		}
		else if (!strcmp(joe,  "print"))
			if (stack.size() > 0)
				print(stack);
			else
				notEnoughItems();
		else if (!strcmp(joe,  "printStack"))
			printStack(stack);
		else if (!strcmp(joe,  "reset"))
			reset(stack);
		else if (!strcmp(joe,  "drop")) {
			if (stack.size() > 0)
				drop(stack);
			else
				notEnoughItems();
		}
		else if (!strcmp(joe,  "sqrt")) {
			if (stack.size() > 0)
				sqrt(stack);
			else
				notEnoughItems();
		}
		else if (!strcmp(joe, "/*")) {
			do {
				if (using_cin) {
					std::cin >> joe;
				} else {
					file >> joe;
				}
			} while (strcmp(joe, "*/"));
		}
		else if (!strcmp(joe, "//")) {
			do {
				if (using_cin) {
					std::cin >> joe;
				} else {
					file >> joe;
				}
			} while (strcmp(joe, "*/"));
		}
		else if (!strcmp(joe, "#")) {
			do {
				if (using_cin) {
					std::cin >> joe;
				} else {
					file >> joe;
				}
			} while (strcmp(joe, "*/"));
		}
		else if (!strcmp(joe, "end") || !strcmp(joe, "quit") || !strcmp(joe, "exit") || !strcmp(joe, "q"))
			break;
		else if (!strcmp(joe, "pi"))
			stack.push_back(pi);
		else if (!strcmp(joe, "e"))
			stack.push_back(e);
		else
			stack.push_back(atof(joe));
	}
	if (!using_cin) {
		file.close();
	}
	return 0;
}

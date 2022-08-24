#ifndef UTIL_HPP
#define UTIL_HPP

#include <sstream>
#include <string>
#include <iostream>

using namespace std;

class Util {
private:
public:
	Util();
	~Util();

	void tokenizar(string text, int **matriz);

};

Util::Util() {}
Util::~Util() {}

/**
 * @brief
 *
 * utilizado pela funcao readFile
 */
void Util::tokenizar(string text, int **matriz) {
	char del = ',';

	stringstream sstream(text);
	string token;

	while (getline(sstream, token, del)) {
		cout << token << " ";
	}
	cout << endl;
}

#endif
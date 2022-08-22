#include "util.hpp"

Util::Util() {}
Util::~Util() {}

/**
 * @brief
 *
 * utilizado pela funcao readFile
 */
void Util::tokenizar(string text) {
	char del = ',';

	stringstream sstream(text);
	string token;

	while (getline(sstream, token, del)) {
		cout <<token <<endl;
	}
}

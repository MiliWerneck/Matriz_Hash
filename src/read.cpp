#include "read.hpp"

Read::Read() {}
Read::~Read() {}

/**
 * @brief realiza a leitura de um arquivo e faz a sua impressao
 *
 * @param file nome do arquivo a ser aberto
 *
 */
void Read::readFile(string path) {
	path.insert(0, "files/");

	ifstream myfile("files/matriz.txt");
	string line;

	Util u;

	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			u.tokenizar(line);
			// cout << line << endl;
		}
		myfile.close();
	} else cout << "Nao foi possivel abrir o arquivo" << endl;
}
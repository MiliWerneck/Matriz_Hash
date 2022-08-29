#ifndef READ_HPP
#define READ_HPP

#include "util.hpp"

#include <fstream>

class Read {
private:
public:
	Read();
	~Read();
	void readFile(int **matriz);
};

Read::Read() {}
Read::~Read() {}

/**
 * @brief realiza a leitura de um arquivo e faz a sua impressao
 *
 * @param file nome do arquivo a ser aberto
 *
 */
void Read::readFile(int **matriz) {

	ifstream myfile("src/files/matriz.txt");
	string line;

	Util u;

	int contLinha = 0;

	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			u.tokenizar(line, matriz, contLinha++);
		}
		myfile.close();
	} else cout << "Nao foi possivel abrir o arquivo" << endl;
}

#endif
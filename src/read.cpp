#include "read.hpp"

Read::Read() {}
Read::~Read() {}

/**
 * @brief realiza a leitura de um arquivo e salva em um mapeamento com vetores
 *
 * @param file nome do arquivo a ser aberto
 */

void Read::readFile(string file) {
	file.insert(0, "files/").append(".csv");

	ifstream myfile(file); //abrir arquivo
	string line;

	Util u;

	if (myfile.is_open()) {
		while (getline(myfile, line)){

		}
			// u.tokenizar(line, valores, ++contLinha);
	} else cout << "nao foi possivel abrir o arquivo" << endl;
}

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

	void tokenizar(string text, int **matriz, int linha);
	void quadranteMatriz(int **matriz, int **quadrante, int l1, int c1, int l2, int c2);
	void transposta(int **matriz, int **matrizT, int linha, int coluna);
	void imprimeMatriz(int **matriz, int linha, int coluna);
};

Util::Util() {}
Util::~Util() {}

/**
 * @brief
 *
 * utilizado pela funcao readFile
 */
void Util::tokenizar(string text, int **matriz, int linha) {
	char del = ',';
	int coluna = 0;
	stringstream sstream(text);
	string token;

	while (getline(sstream, token, del)) {
		matriz[linha][coluna++] = stoi(token);
	}
	// cout << endl;
}

void Util::quadranteMatriz(int **matriz, int **quadrante, int l1, int c1, int l2, int c2) {
	int x = 0;
	int y = 0;

	for (int i = l1; i < l2; i++) {
		y = 0;
		for (int j = c1;j < c2; j++) {
			quadrante[x][y] = matriz[i][j];
			y++;
		}
		x++;
	}
}

void Util::transposta(int **matriz, int **matrizT, int linha, int coluna) {
	for (int i = 0; i < linha; i++) {
		for (int j = 0;j < coluna; j++) {
			matrizT[j][i] = matriz[i][j];
		}
	}

}

void Util::imprimeMatriz(int **matriz, int linha, int coluna) {
	for (int i = 0; i < linha; i++) {
		for (int j = 0;j < coluna; j++) {
			cout << matriz[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

#endif
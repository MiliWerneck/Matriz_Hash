#ifndef UTIL_HPP
#define UTIL_HPP

#include <sstream>
#include <string>
#include <iostream>
#include<vector>
#include <map>

using namespace std;

typedef struct dimen dimen;
struct dimen {
	int l1;
	int l2;
	int c1;
	int c2;
};

class Util {
private:
	map<string, vector<vector<int>>> mapa2;
	map<string, vector<vector<int>>> ::iterator itr;
public:
	Util();
	~Util();

	void tokenizar(string text, int **matriz, int linha);
	void quadranteMatriz(int **matriz, int **quadrante, dimen *d);
	void transposta(int **matriz, int **matrizT, int linha, int coluna);
	void multiplicaMatriz(int **matriz, int **matrizT, int **matrizResultado, int l1, int c1, int c2);
	void imprimeMatriz(int **matriz, int linha, int coluna);
	void imprimeTransfMatriz(vector<vector<int>> m2);
	void transformaMatriz(int **matriz, int linha, int coluna);
	void buscarChave(string chave);
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
}

void Util::transposta(int **matriz, int **matrizT, int linha, int coluna) {
	for (int i = 0; i < linha; i++) {
		for (int j = 0;j < coluna; j++) {
			matrizT[j][i] = matriz[i][j];
		}
	}

}

void Util::quadranteMatriz(int **matriz, int **quadrante, dimen *d) {
	int x = 0;
	int y = 0;

	for (int i = d->l1; i < d->l2; i++) {
		y = 0;
		for (int j = d->c1;j < d->c2; j++) {
			quadrante[x][y] = matriz[i][j];
			y++;
		}
		x++;
	}
}

void Util::multiplicaMatriz(int **matriz, int **matrizT, int **matrizResultado, int l1, int c1, int c2) {
	int soma;

	for (int i = 0; i < l1; i++) {
		for (int j = 0; j < c2;j++) {
			soma = 0;

			for (int k = 0;k < c1; k++) {
				soma += matriz[i][k] * matrizT[k][j];
				// contador++;
			}
			matrizResultado[i][j] = soma;
		}
	}
	// cout << contador << endl;
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

void Util::imprimeTransfMatriz(vector<vector<int>> m2) {
	for (auto linha : m2) { // auto pega o tipo automaticamente
		for (auto var : linha) {
			cout << var << "\t";
		}
		cout << endl;
	}
}

void Util::transformaMatriz(int **matriz, int linha, int coluna) {
	vector<vector<int>> matrizvetor(linha, vector<int>(coluna, 0));
	for (int i = 0; i < linha; i++) {
		for (int j = 0; j < coluna; j++) {
			matrizvetor.at(i).at(j) = matriz[i][j];
		}
	}
	this->mapa2.insert({ "chave",matrizvetor });
	// imprimeTransfMatriz(&matrizvetor);
}

void Util::buscarChave(string chave) {
	this->itr = this->mapa2.find(chave);
	if (this->itr != this->mapa2.end()) {
		imprimeTransfMatriz(this->itr->second);
	} else
		cout << "Não encontrada!!!" << endl;
}

#endif
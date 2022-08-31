#include "read.hpp"
#include <map>
#include "HashFechada.h"
#include <vector>

#define MAX 1000

int **inicializa_matriz(int linha, int coluna) {
	int **matriz = (int **)malloc(sizeof(int *) * linha);
	for (int i = 0; i < linha; i++) {
		matriz[i] = (int *)malloc(sizeof(int) * coluna);
	}
	return matriz;
}

int main() {

	// 29, 26, 37, 40
	// 45, 34, 55, 89
	// 56, 12, 32, 45

	vector<vector<int>> matrizvetor(3, vector<int>(4, 0)); //3 = linha, 4 = coluna
	srand(53);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			matrizvetor.at(i).at(j) = rand() % 100;
		}
	}
	// matrizvetor.at(0).at(0) = 29;
	// matrizvetor.at(0).at(1) = 26;
	// matrizvetor.at(0).at(2) = 37;
	// matrizvetor.at(0).at(3) = 40;

	// matrizvetor.at(1).at(0) = 45;
	// matrizvetor.at(1).at(1) = 34;
	// matrizvetor.at(1).at(2) = 55;
	// matrizvetor.at(1).at(3) = 89;

	// matrizvetor.at(2).at(0) = 56;
	// matrizvetor.at(2).at(1) = 12;
	// matrizvetor.at(2).at(2) = 32;
	// matrizvetor.at(2).at(3) = 45;

	// for (auto linha : matrizvetor) { // auto pega o tipo automaticamente
	// 	for (auto var : linha) {
	// 		cout << var << "\t";
	// 	}
	// 	cout << endl;
	// }

	// for (int var : v) {
	// 	cout << var << endl;
	// }
	map<string, vector<vector<int>>> mapa;
	map<string, vector<vector<int>>>::iterator itr;

	vector<int> v2;
	v2.push_back(23);
	v2.push_back(25);
	v2.push_back(23);
	v2.push_back(29);

	mapa.insert({ "testes",matrizvetor });

	// mapa.insert({ "teste2",24 }); //Nunca repete chave

	for (itr = mapa.begin(); itr != mapa.end(); ++itr) {
		cout << itr->first << endl;
		for (auto linha : itr->second) { // auto pega o tipo automaticamente
			for (auto var : linha) {
				cout << var << "\t";
			}
			cout << endl;
		}
	}

	// itr = mapa.find("teste4");
	// if (itr != mapa.end())
	// 	cout << itr->first << "-" << itr->second << endl;
	// else
	// 	cout << "Não encontrado!" << endl;
	return 0;

	dimen dim;
	dim.l1 = 2;
	dim.l2 = 6;
	dim.c1 = 4;
	dim.c2 = 10;

	int **matriz;
	int **quadranteMatriz;
	int **matrizT;
	int **matrizResultado;
	int linha;
	int coluna;
	matriz = inicializa_matriz(MAX, MAX);

	if (dim.l2 > dim.l1 && dim.c2 > dim.c1) {
		linha = (dim.l2 - dim.l1);
		coluna = (dim.c2 - dim.c1);
		quadranteMatriz = inicializa_matriz(linha, coluna);
		matrizT = inicializa_matriz(coluna, linha);
		matrizResultado = inicializa_matriz(linha, linha);
	} else {
		cout << "Final não pode ser menor que inicial!!!" << endl;
	}

	Read r;
	r.readFile(matriz);

	Util u;

	u.quadranteMatriz(matriz, quadranteMatriz, &dim);

	// u.imprimeMatriz(matriz, MAX, MAX);
	u.transposta(quadranteMatriz, matrizT, linha, coluna);
	cout << endl;
	// u.imprimeMatriz(quadranteMatriz, linha, coluna);
	// u.imprimeMatriz(matrizT, coluna, linha);

	for (int i = 0; i < 1; i++) {
		u.multiplicaMatriz(quadranteMatriz, matrizT, matrizResultado, linha, coluna, coluna, linha);

	}

	// u.imprimeMatriz(matrizResultado, linha, linha);

	return EXIT_SUCCESS;
}
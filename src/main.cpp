#include "read.hpp"

#define MAX 10

int **inicializa_matriz(int linha, int coluna) {
	int **matriz = (int **)malloc(sizeof(int *) * linha);
	for (int i = 0; i < coluna; i++) {
		matriz[i] = (int *)malloc(sizeof(int) * coluna);
	}
	return matriz;
}

int main() {
	int **matriz;
	int **quadranteMatriz;
	int **matrizT;
	int l1 = 0;
	int c1 = 0;
	int l2 = 4;
	int c2 = 5;
	int linha;
	int coluna;

	matriz = inicializa_matriz(MAX, MAX);

	if (l2 > l1 && c2 > c1) {
		linha = (l2 - l1);
		coluna = (c2 - c1);
		quadranteMatriz = inicializa_matriz(linha, coluna);
		matrizT = inicializa_matriz(coluna, linha);
		cout << linha << coluna << endl;
		for (int i = 0; i < coluna; i++) {
			for (int j = 0;j < linha;j++) {
				quadranteMatriz[j][i] = 0;
			}
		}
		return 0;
	} else {
		cout << "Final não pode ser menor que inicial!!!" << endl;
	}

	Read r;
	r.readFile(matriz);

	Util u;

	u.quadranteMatriz(matriz, quadranteMatriz, l1, c1, l2, c2);

	u.imprimeMatriz(matriz, MAX, MAX);
	u.transposta(quadranteMatriz, matrizT, linha, coluna);
	cout << endl;
	u.imprimeMatriz(quadranteMatriz, linha, coluna);
	u.imprimeMatriz(matrizT, coluna, linha);

	return EXIT_SUCCESS;
}
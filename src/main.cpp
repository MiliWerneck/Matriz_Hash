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

int Menu() {
	int op;
	system("clear");
	cout << "0 para sair" << endl;
	cout << "1 informar coordenada: (x1, y1, x2, y2)" << endl;
	cin >> op;
	return op;
}

int main() {
	dimen dim;
	Read r;
	Util u;

	int op = -1;
	int **matriz;
	matriz = inicializa_matriz(MAX, MAX);
	r.readFile(matriz);

	do {
		op = Menu();
		if (op == 0) {
			return 0;
		} else if (op == 1) {
			dim.l1 = 2;
			dim.l2 = 5;
			dim.c1 = 4;
			dim.c2 = 8;

			int **quadranteMatriz;
			int **matrizT;
			int **matrizResultado;
			int linha;
			int coluna;

			if (dim.l2 > dim.l1 && dim.c2 > dim.c1) {
				linha = (dim.l2 - dim.l1);
				coluna = (dim.c2 - dim.c1);
				quadranteMatriz = inicializa_matriz(linha, coluna);
				matrizT = inicializa_matriz(coluna, linha);
				matrizResultado = inicializa_matriz(linha, linha);
			} else {
				cout << "Final não pode ser menor que inicial!!!" << endl;
			}


			u.quadranteMatriz(matriz, quadranteMatriz, &dim);
			u.transposta(quadranteMatriz, matrizT, linha, coluna);
			u.multiplicaMatriz(quadranteMatriz, matrizT, matrizResultado, linha, coluna, linha);

			u.imprimeMatriz(matrizResultado, linha, linha);
			u.transformaMatriz(matrizResultado, linha, linha);
			u.buscarChave("chave");
		} else {
			cout << "Opção Inválida!!" << endl;
		}
		system("read -p \"\nPressione enter para continuar...\" continue");

	} while (op != 0);
	return EXIT_SUCCESS;
}
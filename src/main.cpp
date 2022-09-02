#include "read.hpp"
#include <map>
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
	cout << " ============== MENU DE OPÇÕES =============" << endl2;
	cout << "[0] SAIR" << endl;
	cout << "[1] INFORME COORDENADAS: (x1, y1, x2, y2)" << endl2;
	cout << " ===========================================" << endl2;
	cin >> op;
	return op;
}

int main() {
	dimen dim;
	Read r;
	Util u;

	int op = -1;
	int linha;
	int coluna;
	string chave;

	int **matriz;
	int **quadranteMatriz;
	int **matrizT;
	int **matrizResultado;

	matriz = inicializa_matriz(MAX, MAX);
	r.readFile(matriz);

	do {
		op = Menu();
		if (op == 0) {
			return 0;
		} else if (op == 1) {
			cin >> dim.l1;
			cin >> dim.c1;
			cin >> dim.l2;
			cin >> dim.c2;

			if (dim.l2 > dim.l1 && dim.c2 > dim.c1) {
				chave
					.assign(to_string(dim.l1)).append(",")
					.append(to_string(dim.c1)).append(",")
					.append(to_string(dim.l2)).append(",")
					.append(to_string(dim.c2));

				if (!u.buscarChave(chave)) {
					linha = (dim.l2 - dim.l1);
					coluna = (dim.c2 - dim.c1);

					quadranteMatriz = inicializa_matriz(linha, coluna);
					matrizT = inicializa_matriz(coluna, linha);
					matrizResultado = inicializa_matriz(linha, linha);

					u.quadranteMatriz(matriz, quadranteMatriz, &dim);
					u.transposta(quadranteMatriz, matrizT, linha, coluna);
					u.multiplicaMatriz(quadranteMatriz, matrizT, matrizResultado, linha, coluna, linha);
					// u.imprimeMatriz(matrizResultado, linha, linha);
					u.transformaMatriz(matrizResultado, chave, linha, linha);
				}
			} else {
				cout << "Final não pode ser menor que inicial!!!" << endl;
			}
		} else {
			cout << "Opção Inválida!!" << endl;
		}
		system("read -p \"\nPressione enter para continuar...\" continue");

	} while (op != 0);
	return EXIT_SUCCESS;
}
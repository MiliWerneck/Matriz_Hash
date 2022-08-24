#include "read.hpp"

#define MAX 10

void inicializa_matriz(int **matriz) {
	matriz = (int **)malloc(sizeof(int *) * MAX);
	for (int i = 0; i < MAX; i++) {
		matriz[i] = (int *)malloc(sizeof(int) * MAX);
	}
}

int main() {
	int **matriz;

	inicializa_matriz(matriz);

	Read r;
	r.readFile(matriz);

	return EXIT_SUCCESS;
}
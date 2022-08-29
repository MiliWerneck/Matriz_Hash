#ifndef HASH_FECHADA_H
#define HASH_FECHADA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define hashF(v, M) (v % M)

typedef struct dataF dataF;
typedef struct hashF hashF;

struct dataF {
	int chave;
	bool dataF;
	int *lista;
	int posicao;
};

struct hashF {
	dataF *tabela;
	int M;
	int colide;
};

void InsereValorF(hashF *hf, int *vetor);
void InicializaF(hashF *hf, int M);
void InsereF(hashF *hf, int chave, int valor);
int RetornaColisoesF(hashF *hf);
void ImprimeF(hashF *hf);

void InsereValorF(hashF *hf, int *vetor) {
	for (int n = 0; n < 30; n++) {
		InsereF(hf, n * 10, vetor[n]);
	}
}

void InicializaF(hashF *hf, int M) {
	hf->tabela = (dataF *)malloc(M * sizeof(dataF));

	for (int i = 0; i < M; i++) {
		hf->tabela[i].chave = -1;
		hf->tabela[i].dataF = false;
		hf->tabela[i].lista = (int *)malloc(M * sizeof(int));
		hf->tabela[i].posicao = 0;
		for (int j = 0; j < M; j++) {
			hf->tabela[i].lista[j] = -1;
		}
	}

	hf->M = M;
	hf->colide = 0;
}

void InsereF(hashF *hf, int chave, int valor) {
	int id = hashF(chave, hf->M);
	int i = hf->tabela[id].posicao;

	if (!hf->tabela[id].dataF) {
		hf->tabela[id].dataF = true;
		hf->tabela[id].lista[i] = valor;
	} else {
		do {
			hf->colide++;
			hf->tabela[id].posicao++;
			i = hf->tabela[id].posicao;
			if (hf->tabela[id].lista[i] == -1) {
				hf->tabela[id].lista[i] = valor;
				break;
			}
		} while (hf->tabela[id].lista[i] == -1);
	}

	hf->tabela[id].chave = chave;
}

void ImprimeF(hashF *hf) {
	for (int i = 0; i < hf->M; i++) {
		printf("%d -> ", hf->tabela[i].chave);
		for (int j = 0; j < hf->M; j++) {
			if (hf->tabela[i].lista[j] != -1)
				printf("%d ", hf->tabela[i].lista[j]);
			else
				break;
		}
		printf("\n");
	}
}

int RetornaColisoesF(hashF *hf) {
	return hf->colide;
}

#endif
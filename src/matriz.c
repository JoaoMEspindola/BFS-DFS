#include "matriz.h"

int** geraMatriz(int *n){
	int **auxMatriz;
	FILE *file;
	char cAux[50]; // Ler o Arquivo
	char *pt; // Ler o Arquivo
	int tamanho, linha, coluna;
	bool aux;

	file = fopen("input.txt", "r");
	
	if (file == NULL){
		printf("Arquivo não encontrado");
	}
	else{
		fscanf(file, "%d", &tamanho);
		*n = tamanho;
		
		auxMatriz = malloc (sizeof(int*)*tamanho);

		for (int i = 0; i < tamanho; i++){
			auxMatriz[i] = malloc (sizeof(int)*tamanho);
		}

		for (int i = 0; i < tamanho; i++){
			for (int j = 0; j < tamanho; j++){
				auxMatriz[i][j] = 0;
			}
		}

		while( fscanf(file, "%50s", cAux) == 1){
			pt = strtok(cAux, ",");
			aux = false;
			while(pt){
				if(aux == false){
					linha = atoi(pt);
					pt = strtok(NULL, ","); 
					aux = true;
				}
				else{
					coluna = atoi(pt);
					pt = strtok(NULL, ","); 
				}
			}
			auxMatriz[linha][coluna] = 2;
		}
	}
	
	fclose(file);

	return auxMatriz;
}

void imprimeMatriz(int **matriz, int n){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (matriz[i][j] == 2)
				printf("#\t");
			else
				printf("%d\t", matriz[i][j]);
		}
		printf("\n");
	}
}

void limpaMatriz(int **matriz, int n){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (matriz[i][j] == 1)
				matriz[i][j] = 0;
		}
	}
}


#include <stdio.h>

void main() {

	//ler arq
	FILE *arq;
	
	char Linha[100];
	char *result;
	int i;

	// Abre um arquivo TEXTO para LEITURA
	arq = fopen("ArqTeste.txt", "rt");
	if (arq == NULL) {// Se houve erro na abertura
		printf("Problemas na abertura do arquivo\n");
		return;
	}
	i = 1;
	// Ler cada linha do arquivo
	while (!feof(arq)){ 	
		result = fgets(Linha, 100, arq); 
		if (result) 
		printf("Linha %d : %s",i,Linha);
		i++;
	}
	fclose(arq);

	
}

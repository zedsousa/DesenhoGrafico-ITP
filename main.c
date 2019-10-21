#include "desenho.h"
#include "circulo.h"
#include "quadrado.h"
#include "ponto.h"

#include <stdio.h>

int main() {

	//ler arq
	FILE *arq;
	
	char Linha[100];
	char *result;
	int i;

  	clrscr();

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

	//criar img
	char lixo, c = 'A';
	Desenho d = criaDesenho();
	while (c != 'S') {
		printf("\nDigite o que deseja fazer: \n");
		printf("C - inserir circulo\n");
		printf("Q - inserir quadrado\n");
		printf("P - inserir ponto\n");
		printf("A - calcular área total\n");
		printf("S - sair do programa\n");
		printf("OLA MUNDO!\n");
		scanf("%c", &c);
		if (c == 'C') {
			int raio, x, y;
			printf("Digite o raio: \n");
			scanf("%d", &raio);
			printf("Digite o centro na forma x y: \n");
			scanf("%d %d", &x, &y);

			Ponto p = definePonto(x, y);
			Circulo c = defineCirculo(raio, p);
			insereCirculo(&d, c);
		}
		else if (c == 'Q') {
			int lado, x, y;
			printf("Digite o lado: \n");
			scanf("%d", &lado);
			printf("Digite o topo esquerdo na forma x y: \n");
			scanf("%d %d", &x, &y);

			Ponto p = definePonto(x, y);
			Quadrado q = defineQuadrado(lado, p);
			insereQuadrado(&d, q);
		}
		else if (c == 'P') {
			int x, y;
			printf("Digite o ponto na forma x y: \n");
			scanf("%d %d", &x, &y);

			Ponto p = definePonto(x, y);
			inserePonto(&d, p);
			
		}
		else if (c == 'A') {
			float area = areaTotal(d);
			int n = numeroFormas(d);
			printf("Existem %d formas no desenho ocupando %f de área\n",n, area);
		}
		scanf("%c", &lixo);
	}
	return 0;
}

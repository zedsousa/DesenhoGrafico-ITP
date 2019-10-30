#include <stdio.h>

#include <stdlib.h>

void le_arquivo();
void gera_ppm();
void main() {
	le_arquivo();
	gera_ppm();

}

void le_arquivo(){

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
void gera_ppm(){
	
    const int largura = 100, altura = 100;
    int i, j;

	static unsigned char branco[3];
        branco[0] = 255;  /* red */
        branco[1] = 255;  /* green */
        branco[2] = 255;  /* blue */
	static unsigned char preto[3];
        preto[0] = 0;  /* red */
        preto[1] = 0;  /* green */
        preto[2] = 0;  /* blue */	
    
    FILE *fp = fopen("image.ppm", "wb");
    
    
    fprintf(fp, "P6\n%d %d\n255\n", largura, altura);
    
    for (j = 0; j < altura; ++j)
    {
        for (i = 0; i < largura; ++i)
        {
			if(i==j){
				//Substituir por fprintf
				fwrite(preto, 1, 3, fp);
			}else{
				fwrite(branco, 1, 3, fp);
			}
            }
    }
	fclose(fp);//Salva o arquivo
    


}

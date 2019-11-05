#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structs.h"
#include "default.h"

void le_arquivo();
void gera_ppm();
void outputOptions(FILE *arq);


void main() {
	
	le_arquivo();
}

void le_arquivo(){
	//ler arq
	FILE *arq;
	// Abre um arquivo TEXTO para LEITURA
	arq = fopen("ArqTeste.txt", "rt");
	if (arq == NULL) {// Se houve erro na abertura
		printf("Problemas na abertura do arquivo\n");
		return;
	}
	outputOptions(arq);
	fclose(arq);
}


void gera_ppm(image I, clear C, char *filename){
//void gera_ppm(image I, char *filename,int w,int h,color (*C)[w]);
    int width = I.x;
	int height = I.y;
    int i, j;	
    
    FILE *fp = fopen(filename, "wb");
    
    
    fprintf(fp, "P3\n%d %d\n255\n", width, height);
    
    for (j = 0; j < height; ++j)
    {
        for (i = 0; i < width; ++i)
        {
			
			fprintf( fp, "%d %d %d\n", C.Color.r, C.Color.g, C.Color.b);
			
            }
    }
	fclose(fp);//Salva o arquivo
}
void outputOptions(FILE *arq){
	char nome[10];
	image Image;
	clear Clear;
	char filename[30];
	color *MatrizAux;
    	int i,heightMatrizAux,widthMatrizAux;
	
	while (!feof(arq)){
		fscanf(arq,"%s",nome);
		if(strcmp(nome,"image")==0){
			    fscanf(arq,"%d %d \n",&Image.x,&Image.y);
			    widthMatrizAux=Image.x;//esta variavel serve pra poder liberar a memória fora deste IF
			    heightMatrizAux=Image.y;

			    //alocação dinâmica da matrizAux
			    MatrizAux = (color **) calloc (Image.x, sizeof(color *));	
			    if (MatrizAux == NULL) {
				printf ("** Erro: Memoria Insuficiente **");
				return (NULL);
			    }
			    for ( i = 0; i < Image.x; i++ ) {
				MatrizAux[i] = (color*) calloc (Image.y, sizeof(color));
			    }
		}
		if(strcmp(nome,"fill")==0){
			point Point;
			fscanf(arq,"%d %d \n",&Point.x,&Point.y);
			//fill(Point);
		}
		if(strcmp(nome,"line")==0){
			point Points[2];
			fscanf(arq,"%d %d %d %d\n",&Points[0].x,&Points[0].y,&Points[1].x,&Points[1].y);
            		makeLine(Points[0],Points[1],widthMatrizAux,heightMatrizAux,C);
		}
		if(strcmp(nome,"color")==0){
			color Color;
			fscanf(arq,"%d %d %d\n",&Color.r,&Color.g,&Color.b);
			//color(Color);
		}
		if(strcmp(nome,"clear")==0){
			
			fscanf(arq,"%d %d %d\n",&Clear.Color.r,&Clear.Color.g,&Clear.Color.b);
			//clear(Clear,widthMatrizAux,heightMatrizAux,MatrizAux);
		}
		if(strcmp(nome,"circle")==0){
			point Point;
			int radius;
			fscanf(arq,"%d %d %d\n",&Point.x,&Point.y,&radius);
			//circle(Point,radius);
		}
		if(strcmp(nome,"polygon")==0){
			int i,j,lengthPoints;
			fscanf(arq,"%d",&lengthPoints);
			point Points[lengthPoints];			
			for(i=0;i<(2*lengthPoints);i++){
				for(j=0;j<lengthPoints;j++){
					if(i%2==0){
						fscanf(arq,"%d %d",&Points[j].x,&Points[j].y);
						if(i==((2*lengthPoints)-2)) fscanf(arq,"%d %d\n",&Points[j].x,&Points[j].y);
					}					
				}
			}
		    	makePolygon(lengthPoints,P,widthMatrizAux,heightMatrizAux,C);
		}
		if(strcmp(nome,"rect")==0){
            		point P;
			int heigth,width;
			fscanf(arq,"%d %d %d %d\n",&P.x,&P.y,&heigth,&width);
			//rect(P,heigth,width);
		}
		if(strcmp(nome,"save")==0){
			fscanf(arq,"%s\n",filename);
			//save(FILe *Arq);

		    //libera a matriz da memória
		    for (i=0; i<widthMatrizAux; i++) 
			free (MatrizAux[i]);  
		    free (MatrizAux);  
		}
	}gera_ppm(Image, Clear, filename);
}

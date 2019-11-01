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
	while (!feof(arq)){
		fscanf(arq,"%s",nome);
		if(strcmp(nome,"image")==0){
			
			fscanf(arq,"%d %d \n",&Image.x,&Image.y);
			
			
		}
		if(strcmp(nome,"fill")==0){
			point Point;
			fscanf(arq,"%d %d \n",&Point.x,&Point.y);
			//fill(Point);
		}
		if(strcmp(nome,"line")==0){
			point Points[2];
			fscanf(arq,"%d %d %d %d\n",&Points[0].x,&Points[0].y,&Points[1].x,&Points[1].y);
			//line(Points);
		}
		if(strcmp(nome,"color")==0){
			color Color;
			fscanf(arq,"%d %d %d\n",&Color.r,&Color.g,&Color.b);
			//color(Color);
		}
		if(strcmp(nome,"clear")==0){
			
			fscanf(arq,"%d %d %d\n",&Clear.Color.r,&Clear.Color.g,&Clear.Color.b);
			//clear(Clear);
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
			//makePolygon(lengthPoints,Points);
		}
		if(strcmp(nome,"save")==0){
			fscanf(arq,"%s\n",filename);
			//Arq = img.ppm
			//save(FILe *Arq);
		}
	}gera_ppm(Image, Clear, filename);
}

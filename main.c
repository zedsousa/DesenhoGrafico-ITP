#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
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



void outputOptions(FILE *arq){
	char name[10];
	image Image;
	clear Clear;
	char filename[30];
	color **MatrixAux;
	color aux;
	color fill;
  int i,heightMatrixAux=0,widthMatrixAux=0;
	
	while (!feof(arq)){
		fscanf(arq,"%s",name);
		if(strcmp(name,"image")==0){
			fscanf(arq,"%d %d \n",&Image.x,&Image.y);
			widthMatrixAux=Image.x;//esta variavel serve pra poder liberar a memória fora deste IF
			heightMatrixAux=Image.y;    
			MatrixAux=makeImage(widthMatrixAux, heightMatrixAux);
		}
		if(strcmp(name,"fill")==0){
			point Point;
			fscanf(arq,"%d %d %d %d %d \n",&Point.x,&Point.y, &fill.r, &fill.g, &fill.b);
			color oldColor = MatrixAux[Point.x][Point.y];
			fillForm(Point.x,Point.y, oldColor, fill, widthMatrixAux, heightMatrixAux, MatrixAux);
		}
		if(strcmp(name,"line")==0){
			point Points[2];
			fscanf(arq,"%d %d %d %d\n",&Points[0].x,&Points[0].y,&Points[1].x,&Points[1].y);
      makeLine(Points[0],Points[1],MatrixAux);	
		}
		if(strcmp(name,"color")==0){
			fscanf(arq,"%d %d %d\n",&aux.r,&aux.g,&aux.b);
		}
		if(strcmp(name,"clear")==0){
			fscanf(arq,"%d %d %d\n",&Clear.Color.r,&Clear.Color.g,&Clear.Color.b);
			cleanImage(Clear,widthMatrixAux,heightMatrixAux,MatrixAux);
		}
		if(strcmp(name,"circle")==0){
			point Point;
			int radius;
			fscanf(arq,"%d %d %d\n",&Point.x,&Point.y,&radius);
			makeCircle(Point.x,Point.y,radius,aux,MatrixAux);
		}
		if(strcmp(name,"polygon")==0){
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
		  makePolygon(lengthPoints,Points,widthMatrixAux,heightMatrixAux,MatrixAux);
		}
		if(strcmp(name,"rect")==0){
      point P;
			int heigth,width;
			fscanf(arq,"%d %d %d %d\n",&P.x,&P.y,&heigth,&width);
			makeRect(P,heigth,width, MatrixAux);
		}
		if(strcmp(name,"save")==0){
			fscanf(arq,"%s\n",filename);
			saveImage(widthMatrixAux,heightMatrixAux, filename,MatrixAux);
		}
	}
	//libera a matriz da memória
		    for (i=0; i<widthMatrixAux; i++) 
				free (MatrixAux[i]);  
		    free (MatrixAux);  
}

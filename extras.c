#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "structs.h"

color bilinearInterpolation(int x,int y,color **OriginalMatrix){
	color resultColor;
	int aux=0;
	//vertical and horizontal interpolation
	//diagonal interpolation
}

void negative(int width,int height,color **OriginalMatrix){
    int i,j,aux;
    color **NegativeMatrix;
    char filename[20];
	strcpy(filename,"negativeImage.ppm");

	//dinamic alocation for matrix NegativeMatrix
	NegativeMatrix = (color **) calloc (width, sizeof(color *));
	if (NegativeMatrix == NULL) {
		printf ("** Erro: Memoria Insuficiente **");
	}
	for ( i = 0; i < width; i++ ) {
		NegativeMatrix[i] = (color*) calloc (height, sizeof(color));
	}

	//invert RGB values for each pixel
    for(i=0;i<width;i++){
        for(j=0;j<height;j++){
            aux = OriginalMatrix[i][j].r;
            NegativeMatrix[i][j].r=(255-aux);
            aux = OriginalMatrix[i][j].g;
            NegativeMatrix[i][j].b=(255-aux);
            aux = OriginalMatrix[i][j].b;
            NegativeMatrix[i][j].b=(255-aux);
        }
    }
	//negative image's ppm file
    gera_ppm(width,height,filename,NegativeMatrix);

	//free NegativeMatrix's memory 
		    for (i=0; i<width; i++) 
				free (NegativeMatrix[i]);  
		    free (NegativeMatrix); 
}

void threshold(int limit,int height,int width,color **OriginalMatrix){
	int i,j,average;
	color **ThresholdImage;
	char filename[20];
	strcpy(filename,"thresholdImage.ppm");
	//dinamic alocation for matrix ThresholdImage
	ThresholdImage = (color **) calloc (width, sizeof(color *));
	if (ThresholdImage == NULL) {
		printf ("** Erro: Memoria Insuficiente **");
	}
	for ( i = 0; i < width; i++ ) {
		ThresholdImage[i] = (color*) calloc (height, sizeof(color));
	}

	for(i=0;i<width;i++){
		for(j=0;j<height;j++){
			average = (OriginalMatrix[i][j].r+OriginalMatrix[i][j].g+OriginalMatrix[i][j].b)/3;
			if(average>=limit){
				ThresholdImage[i][j].r=255;
				ThresholdImage[i][j].g=255;
				ThresholdImage[i][j].b=255;
			}else{
				ThresholdImage[i][j].r=0;
				ThresholdImage[i][j].g=0;
				ThresholdImage[i][j].b=0;
			}
		}
	}

	//negative image's ppm file
    gera_ppm(width,height,filename,ThresholdImage);

	//free ThresholdImage's memory 
		    for (i=0; i<width; i++) 
				free (ThresholdImage[i]);  
		    free (ThresholdImage);
}

void expand(int percentage,color **OriginalMatrix);
void reduce(int percentage,color **OriginalMatrix);
void turn(int angle,int height,int width,color **OriginalMatrix){
	int i,j,newX,newY;
	color **RotatedImage;
	//aloca

	for(i=0;i<width;i++){
		for(j=0;j<height;j++){
			newX = (i*cos(angle))-(j*sin(angle));
			newY = (i*sen(angle))+(j*cos(angle));
		}
	}	

	//libera
}
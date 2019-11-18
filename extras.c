#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "structs.h"

color bilinearInterpolation(int x,int y,color **OriginalMatrix){
	color resultColor; int aux;
	//considering vertical, horizontal and diagonal interpolation
	aux = (OriginalMatrix[x][y-1].r+OriginalMatrix[x-1][y].r+OriginalMatrix[x][y+1].r+OriginalMatrix[x+1][y].r+OriginalMatrix[x-1][y-1].r+OriginalMatrix[x-1][y+1].r+OriginalMatrix[x+1][y-1].r+OriginalMatrix[x+1][y].r+OriginalMatrix[x+1][y+1].r)/8;
	resultColor.r = aux;
	aux = (OriginalMatrix[x][y-1].g+OriginalMatrix[x-1][y].g+OriginalMatrix[x][y+1].g+OriginalMatrix[x+1][y].g+OriginalMatrix[x-1][y-1].g+OriginalMatrix[x-1][y+1].g+OriginalMatrix[x+1][y-1].g+OriginalMatrix[x+1][y].g+OriginalMatrix[x+1][y+1].g)/8;
	resultColor.g = aux;
	aux = (OriginalMatrix[x][y-1].b+OriginalMatrix[x-1][y].b+OriginalMatrix[x][y+1].b+OriginalMatrix[x+1][y].b+OriginalMatrix[x-1][y-1].b+OriginalMatrix[x-1][y+1].b+OriginalMatrix[x+1][y-1].b+OriginalMatrix[x+1][y].b+OriginalMatrix[x+1][y+1].b)/8;
	resultColor.b = aux;
	
	return resultColor;
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

void expand(int percentage,int width,int height,color **OriginalMatrix){
	int i,j;
	color **ExpandedImage;
	char filename[20];
	strcpy(filename,"expandedImage.ppm");

	//dinamic alocation for matrix ExpandedImage
	width = width*percentage;
	ExpandedImage = (color **) calloc (width, sizeof(color *));
	if (ExpandedImage == NULL) {
		printf ("** Erro: Memoria Insuficiente **");
	}
	for ( i = 0; i < width; i++ ) {
		height = height*percentage;
		ExpandedImage[i] = (color*) calloc (height, sizeof(color));
	}
	/* (adapted) function below made by AndersonSMed
	source: https://github.com/AndersonSMed/Aplicador-de-filtros-em-imagens-PPM/blob/master/funcoes.c
	*/
	void ampliar(int width,int height,color ***OriginalMatrix,color ***ExpandedImage, int zoom){
		int i, j, k, l;

		width2 = width * zoom;
		height2 = height * zoom;
		
		for(i = 0, k = 0; i < width && k < width2; k ++){
			if(k % zoom == 0 && k != 0){
				i++;
			}
				for(j = 0, l = 0; j < height && l < height2;  l++){
					if(l % zoom == 0 && l != 0){
						j++;
					}
					ExpandedImage[k][l].r = OriginalMatrix[i][j].r;
					ExpandedImage[k][l].g = OriginalMatrix[i][j].b;
					ExpandedImage[k][l].b = OriginalMatrix[i][j].g;
				}
		}
	}

	//expanded image's ppm file
    gera_ppm(width,height,filename,ExpandedImage);

	//free ExpandedImage's memory 
		    for (i=0; i<width; i++) 
				free (ExpandedImage[i]);  
		    free (ExpandedImage);
}
void reduce(int percentage,int width,int height,color **OriginalMatrix){
	int i,j,k,l,width2,height2;
	color **ReducedImage;
	char filename[20];
	strcpy(filename,"reducedImage.ppm");
	width2 = width*percentage;
	height2 = height*percentage;

	//dinamic alocation for matrix ReducedImage
	ReducedImage = (color **) calloc (width2, sizeof(color *));
	if (ReducedImage == NULL) {
		printf ("** Erro: Memoria Insuficiente **");
	}
	for ( i = 0; i < width; i++ ) {
		ReducedImage[i] = (color*) calloc (height2,sizeof(color));
	}

	for(i=0,k=1;i<width2,k<(width+1);i++,k+2){
		for(j=0,l=1;j<height2,l<=(height+1);j++,l+2){
			ReducedImage[i][j] = bilinearInterpolation(k,l,OriginalMatrix);
		}
	}

	//reduced image's ppm file
    gera_ppm(width,height,filename,ReducedImage);

	//free ReducedImage's memory 
		    for (i=0; i<width; i++) 
				free (ReducedImage[i]);  
		    free (ReducedImage);
}
void turn(int angle,int height,int width,color Color,color **OriginalMatrix){
	int x,y,newX,newY;
	color **RotatedImage;
	char filename[20];
	strcpy(filename,"rotatedImage.ppm");
	//dinamic alocation for matrix RotatedImage
	RotatedImage = (color **) calloc (width, sizeof(color *));
	if (RotatedImage == NULL) {
		printf ("** Erro: Memoria Insuficiente **");
	}
	for ( x = 0; x < width; x++ ) {
		RotatedImage[x] = (color*) calloc (height, sizeof(color));
	}

	/*(adapted) those for below was made by eLowar
	  source: http://eab.abime.net/showthread.php?t=29492
	*/
	for(int x = 0; x < width; x++) {
		for(int y = 0; y < height; y++) {
			int hwidth = width / 2;
			int hheight = height / 2;
			
			int xt = x - hwidth;
			int yt = y - hheight;
			
			double sinma = sin(-angle);
			double cosma = cos(-angle);
			
			int xs = (int)round((cosma * xt - sinma * yt) + hwidth);
			int ys = (int)round((sinma * xt + cosma * yt) + hheight);

			if(xs >= 0 && xs < width && ys >= 0 && ys < height) {
				setPixel(xs,ys,Color,OriginalMatrix,width,height);
			}
		}
	}

	//negative image's ppm file
    gera_ppm(width,height,filename,RotatedImage);

	//free ThresholdImage's memory 
		    for (x=0; x<width; x++) 
				free (RotatedImage[x]);  
		    free (RotatedImage);
}
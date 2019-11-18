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

	//dinamic alocation for matrix ReducedImage
	width = width*(1+(percentage/100));
	ExpandedImage = (color **) calloc (width, sizeof(color *));
	if (ExpandedImage == NULL) {
		printf ("** Erro: Memoria Insuficiente **");
	}
	for ( i = 0; i < width; i++ ) {
		height = height*(1+(percentage/100));
		ExpandedImage[i] = (color*) calloc (height, sizeof(color));
	}

	//function

	//reduced image's ppm file
    gera_ppm(width,height,filename,ExpandedImage);

	//free ReducedImage's memory 
		    for (i=0; i<width; i++) 
				free (ExpandedImage[i]);  
		    free (ExpandedImage);
}
void reduce(int percentage,int width,int height,color **OriginalMatrix){
	int i,j;
	color **ReducedImage;
	char filename[20];
	strcpy(filename,"reducedImage.ppm");

	//dinamic alocation for matrix ReducedImage
	ReducedImage = (color **) calloc ((width*percentage), sizeof(color *));
	if (ReducedImage == NULL) {
		printf ("** Erro: Memoria Insuficiente **");
	}
	for ( i = 0; i < width; i++ ) {
		ReducedImage[i] = (color*) calloc (height*percentage, sizeof(color));
	}

	//function

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
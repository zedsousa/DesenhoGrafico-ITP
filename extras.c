#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "default.h"
#include "structs.h"
#include "extras.h"

void negative(int width,int height,color **OriginalMatrix){
    int i,j,aux=0;
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
            NegativeMatrix[i][j].g=(255-aux);
            aux = OriginalMatrix[i][j].b;
            NegativeMatrix[i][j].b=(255-aux);
        }
    }
	//negative image's ppm file
    saveImage(width,height,filename,NegativeMatrix);

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
    saveImage(width,height,filename,ThresholdImage);

	//free ThresholdImage's memory 
		    for (i=0; i<width; i++) 
				free (ThresholdImage[i]);  
		    free (ThresholdImage);
}

void expand(int percentage,int width,int height,color **OriginalMatrix){
	int i,j,k,l,width2,height2;
	color **ExpandedImage;
	char filename[20];
	strcpy(filename,"expandedImage.ppm");

	//dinamic alocation for matrix ExpandedImage
	width2 = width + (width * percentage/100);
	height2 = height + (height * percentage/100);
	ExpandedImage = (color **) calloc (width2, sizeof(color *));
	if (ExpandedImage == NULL) {
		printf ("** Erro: Memoria Insuficiente **");
	}
	for ( i = 0; i < width2; i++ ) {
		ExpandedImage[i] = (color*) calloc (height2, sizeof(color));
	}
	/* (adapted) for function below made by AndersonSMed
	source: https://github.com/AndersonSMed/Aplicador-de-filtros-em-imagens-PPM/blob/master/funcoes.c
	*/
	for(i = 0, k = 0; i < width && k < width2; k++){
		if(k % percentage  == 0 && k != 0){
			i++;
		}
		for(j = 0, l = 0; j < height && l < height2;  l++){
			if(l % percentage  == 0 && l != 0){
				j++;
			}
			ExpandedImage[k][l].r = OriginalMatrix[i][j].r;
			ExpandedImage[k][l].g = OriginalMatrix[i][j].g;
			ExpandedImage[k][l].b = OriginalMatrix[i][j].b;
		}
	}
	
	//expanded image's ppm file
    saveImage(width,height,filename,ExpandedImage);

	//free ExpandedImage's memory 
		    for (i=0; i<width2; i++) 
				free (ExpandedImage[i]);  
		    free (ExpandedImage);
}

void reduce(int width,int height,color **OriginalMatrix){
	int i,j,k,l,width2,height2;
	color **ReducedImage;
	char filename[20];
	strcpy(filename,"reducedImage.ppm");
	width2 = width/2;
	height2 = height/2;
		
	//dinamic alocation for matrix ReducedImage
	ReducedImage = (color **) calloc (width2, sizeof(color *));
	if (ReducedImage == NULL) {
		printf ("** Erro: Memoria Insuficiente **");
	}
	for ( i = 0; i < width2; i++ ) {
		ReducedImage[i] = (color*) calloc (height2,sizeof(color));
	}

	for(i = 0, k = 1; i < width2 && k < width; i++, k += 2){
		for(j = 0, l = 1; j < height2 && l < height; j++, l += 2){
			ReducedImage[i][j].r = (OriginalMatrix[k - 1][l - 1].r + OriginalMatrix[k - 1][l].r + OriginalMatrix[k][l - 1].r + OriginalMatrix[k][l].r) / 4;
			ReducedImage[i][j].g = (OriginalMatrix[k - 1][l - 1].g + OriginalMatrix[k - 1][l].g + OriginalMatrix[k][l - 1].g + OriginalMatrix[k][l].g) / 4;
			ReducedImage[i][j].b = (OriginalMatrix[k - 1][l - 1].b + OriginalMatrix[k - 1][l].b + OriginalMatrix[k][l - 1].b + OriginalMatrix[k][l].b) / 4;
		}
	}

	//reduced image's ppm file
    saveImage(width2,height2,filename,ReducedImage);

	//free ReducedImage's memory 
		    for (i=0; i<width2; i++) 
				free (ReducedImage[i]);  
		    free (ReducedImage);
}
void turn(int angle,int height,int width,color Color,color **OriginalMatrix){
	int i,j,newX,newY;
	color **RotatedImage;
	char filename[20];
	int angle1;
	strcpy(filename,"rotatedImage.ppm");
	//dinamic alocation for matrix RotatedImage
	RotatedImage = (color **) calloc (width, sizeof(color *));
	if (RotatedImage == NULL) {
		printf ("** Erro: Memoria Insuficiente **");
	}
	for ( i = 0; i < width; i++ ) {
		RotatedImage[i] = (color*) calloc (height, sizeof(color));
	}
	for(int x=0;x<width;x++){
		for(int y=0;y<height;y++){
			int hwidth = width / 2;
			int hheight = height / 2;
			
			int xt = x - hwidth;
			int yt = y - hheight;
			
			double sinma = sin(-angle);
			double cosma = cos(-angle);
			
			int xs = (int)round((cosma * xt - sinma * yt) + hwidth);
			int ys = (int)round((sinma * xt + cosma * yt) + hheight);
			int k = xs,l=ys;
			if(xs >= 0 && xs < width && ys >= 0 && ys < height) {
				RotatedImage[i][j].r = (OriginalMatrix[k - 1][l - 1].r + OriginalMatrix[k - 1][l].r + OriginalMatrix[k][l - 1].r + OriginalMatrix[k][l].r) / 4;
				RotatedImage[i][j].r = (OriginalMatrix[k - 1][l - 1].g + OriginalMatrix[k - 1][l].g + OriginalMatrix[k][l - 1].g + OriginalMatrix[k][l].g) / 4;
				RotatedImage[i][j].r = (OriginalMatrix[k - 1][l - 1].b + OriginalMatrix[k - 1][l].b + OriginalMatrix[k][l - 1].b + OriginalMatrix[k][l].b) / 4;
			}
		}
	}
	//RotatedImage's ppm file
    saveImage(width,height,filename,RotatedImage);

	//free RotatedImage's memory 
		    for (i=0; i<width; i++) 
				free (RotatedImage[i]);  
		    free (RotatedImage);
}

void makePolygon3D(int n,point *P,int w,int h,color** C,color c){
      point auxP1,auxP2, P2;
    int i,j,aux;
    aux=0;//esse aux vai percorrer o vetor P (tipo point)
    
    do{
        auxP1=P[aux];
        auxP2=P[aux+1];

        makeLine(auxP1,auxP2,C,w,h,c);
        aux++;

        if(aux==(n-1)){//se o aux chegar ao penúltimo valor do vetor
            auxP1=P[0];
            auxP2=P[n-1];
            makeLine(auxP1,auxP2,C,w,h,c);
            break;
        }
    }while(aux!=(n-1));
    
    for(i=0;i<n;i++){
        auxP1=P[i];
        auxP2.x=auxP1.x+10;
        auxP2.y=auxP1.y-10;
        P[i].x+=10;
        P[i].y-=10;
        makeLine(auxP1,auxP2,C,w,h,c);
    }

    aux=0;//esse aux vai percorrer o vetor P (tipo point)
    
    do{
        auxP1=P[aux];
        auxP2=P[aux+1];

        makeLine(auxP1,auxP2,C,w,h,c);
        aux++;

        if(aux==(n-1)){//se o aux chegar ao penúltimo valor do vetor
            auxP1=P[0];
            auxP2=P[n-1];
            makeLine(auxP1,auxP2,C,w,h,c);
            break;
        }
    }while(aux!=(n-1));


}
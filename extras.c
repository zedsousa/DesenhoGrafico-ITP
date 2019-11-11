#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

void negativo(int w,int h,color **C){
    int i,j,aux;
    color **C2;
    char filename[20];
	strcpy(filename,"negativo.ppm");

	//alocação dinâmica da matriz C2
	C2 = (color **) calloc (w, sizeof(color *));
	if (C2 == NULL) {
		printf ("** Erro: Memoria Insuficiente **");
	}
	for ( i = 0; i < w; i++ ) {
		C2[i] = (color*) calloc (h, sizeof(color));
	}

	//inverte os valores RGB de cada pixel
    for(i=0;i<w;i++){
        for(j=0;j<h;j++){
            aux = C[i][j].r;
            C2[i][j].r=(255-aux);
            aux = C[i][j].g;
            C2[i][j].b=(255-aux);
            aux = C[i][j].b;
            C2[i][j].b=(255-aux);
        }
    }
	//gera uma img ppm negativa da img original
    gera_ppm(w,h,filename,C2);

	//libera a matriz da memória
		    for (i=0; i<w; i++) 
				free (C2[i]);  
		    free (C2); 
}

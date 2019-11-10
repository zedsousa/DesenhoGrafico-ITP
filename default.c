#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "default.h"

void cleanImage(clear Clear,int x,int y,color **C){
    int i,j;
    for( i=0;i<x;i++){
        
        for( j=0;j<y;j++){
                C[i][j].r=Clear.Color.r;
                C[i][j].g=Clear.Color.g;
                C[i][j].b=Clear.Color.b;       
        }
    }
}

void setPixel(int x,int y,color Color,color **C){
    C[y][x].r=Color.r;
    C[y][x].g=Color.g;
    C[y][x].b=Color.b;

}

//(adapted) function line made by rosettacode.org
void makeLine(point a,point b,color** C) {
    int x0, y0,x1, y1;
    x0=a.x;y0=a.y;x1=b.x;y1=b.y;
    int dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
    int dy = abs(y1-y0), sy = y0<y1 ? 1 : -1; 
    int err = (dx>dy ? dx : -dy)/2, e2;
    
 
    for(;;){ 
        
        color Color;
        Color.r = 0;
        Color.g = 0;
        Color.b = 0;
      
        setPixel(x0,y0,Color,C);
        
        if (x0==x1 && y0==y1) break;
        e2 = err;
        if (e2 >-dx) { 
            err -= dy; 
            x0 += sx; 
        }
        if (e2 < dy) { 
            err += dx; 
            y0 += sy; 
        }
    }
}

void makePolygon(int n,point *P,int w,int h,color** C){
    point auxP1,auxP2;
    int i,j,aux;
    aux=0;//esse aux vai percorrer o vetor P (tipo point)
    
    do{
        auxP1=P[aux];
        auxP2=P[aux+1];

        makeLine(auxP1,auxP2,C);
        aux++;

        if(aux==(n-1)){//se o aux chegar ao penúltimo valor do vetor
            auxP1=P[0];
            auxP2=P[n-1];
            makeLine(auxP1,auxP2,C);
            break;
        }
    }while(aux!=(n-1));
}

void makeRect(point a,int width,int height, color** C){
    int i;
    point Points[4];

    Points[0] = a;
    Points[1].x = a.x+width;
    Points[1].y = a.y;
    Points[2].x = a.x+width;
    Points[2].y = a.y+height;
    Points[3].x = a.x;
    Points[3].y = a.y+height;
    for(i=0;i<4;i++){
        if (i!=3)
            makeLine(Points[i],Points[i+1],C);
        else
            makeLine(Points[3],Points[0],C);
    }
}



color **makeImage(int width, int height){
    color **MatrizAux;
    int i;
    MatrizAux = (color **) calloc (width, sizeof(color *));
	if (MatrizAux == NULL) {
	    printf ("** Erro: Memoria Insuficiente **");
	}
	for ( i = 0; i < width; i++ ) {
	    MatrizAux[i] = (color*) calloc (height, sizeof(color));
	}
    return(MatrizAux);
}

void saveImage(int x,int y, char *filename,color **c){
    int width = x;
	int height = y;
    int i, j;	
    
    FILE *fp = fopen(filename, "wb");
    
    
    fprintf(fp, "P3\n%d %d\n255\n", width, height);
    
    for (j = 0; j < width; ++j)
    {
        for (i = 0; i < height; ++i)
        {
			fprintf( fp, "%d %d %d\n", c[j][i].r, c[j][i].g, c[j][i].b);
            }
    }
	fclose(fp);//Salva o arquivo
    
}
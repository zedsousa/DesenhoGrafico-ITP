#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>
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

void setPixel(int x,int y,color Color,color **C,int w,int h){
    if((x>=0&&x<h)&&(y>=0&&y<w)){
        C[y][x].r=Color.r;
        C[y][x].g=Color.g;
        C[y][x].b=Color.b;
    }
}

//(adapted) function line made by rosettacode.org
void makeLine(point a,point b,color** C,int w,int h) {
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
      
        setPixel(x0,y0,Color,C,w,h);
        
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

        makeLine(auxP1,auxP2,C,w,h);
        aux++;

        if(aux==(n-1)){//se o aux chegar ao penúltimo valor do vetor
            auxP1=P[0];
            auxP2=P[n-1];
            makeLine(auxP1,auxP2,C,w,h);
            break;
        }
    }while(aux!=(n-1));
}


void makeCircle(int x,int y,int r,color c,color **C,int w,int h){
	int i,newX,newY;
    for(i=0;i<=360;i++){
        newX = (r*cos(i)) + x;
        newY = (r*sin(i)) + y;
        setPixel(newX,newY,c,C,w,h);
    }
}


void makeRect(point a,int width,int height, color** C,int w,int h){
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
            makeLine(Points[i],Points[i+1],C,w,h);
        else
            makeLine(Points[3],Points[0],C,w,h);
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
    
    for (j = 0; j < height; ++j)
    {
        for (i = 0; i < width; ++i)
        {
			fprintf( fp, "%d %d %d\n", c[i][j].r, c[i][j].g, c[i][j].b);
            }
    }
	fclose(fp);//Salva o arquivo
    
}


void fillForm(int x, int y,color oldColor, color newColor, int width, int height, color** C){

    if (x<0 || y<0 || x >= width || y >= height){
        return;
    }
    
   if(C[x][y].r != oldColor.r && C[x][y].g != oldColor.g && C[x][y].b != oldColor.b){
       return;
   }
    setPixel(x,y,newColor,C,width,height);
    if(x+1<height)fillForm(x+1,y, oldColor, newColor, width,height,C);
    if(y+1<width)fillForm(x,y+1, oldColor, newColor, width,height,C);
    if(x-1>=0)fillForm(x-1,y, oldColor, newColor, width,height,C);
    if(y-1>=0)fillForm(x,y-1, oldColor, newColor, width,height,C);
} 


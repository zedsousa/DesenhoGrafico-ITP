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

void setPixel(int x,int y,color Color,int w,int h,color **C){
    C[x][y].r=Color.r;
    C[x][y].g=Color.g;
    C[x][y].b=Color.b;

}

//(adapted) function line made by rosettacode.org
void makeLine(point a,point b,int w,int h,color** C) {
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
      
        setPixel(x0,y0,Color,w,h,C);
        
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

        makeLine(auxP1,auxP2,w,h,C);
        aux++;

        if(aux==(n-1)){//se o aux chegar ao penúltimo valor do vetor
            auxP1=P[0];
            auxP2=P[n-1];
            makeLine(auxP1,auxP2,w,h,C);
            break;
        }
    }while(aux!=(n-1));
}

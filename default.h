#ifndef DEFAULT_H
#define DEFAULT_H
#include "structs.h"

//default functions
//são funções considerando as opções do exemplo lá 
color **makeImage(int width, int height);
void cleanImage(clear Clear,int x,int y,color **C);
void colorImage(color C);
void setPixel(int x,int y,color Color,color** C);
void makeLine(point a,point b,color **C);
void makeCircle(point P,int radius);
void makePolygon(int n,point *P,int w,int h,color** C);
void makeRect(point p,int width,int height, color** C);
void fillForm(point P);
void saveImage(FILE *arq);

#endif

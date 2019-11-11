#ifndef DEFAULT_H
#define DEFAULT_H
#include "structs.h"

//default functions
//são funções considerando as opções do exemplo lá 
void makeImage(point P);
void cleanImage(clear Clear,int x,int y,color **C);
void colorImage(color C);
void setPixel(int x,int y,color Color,int w,int h,color** C);
void makeLine(point a,point b,int w,int h,color** C);
void makeCircle(int x,int y,int r,color c,color **C);
void makePolygon(int n,point *P,int w,int h,color** C);
void makeRect(point p,int height,int width,int w,int h,color** C);
void fillForm(point P);
void saveImage(FILE *arq);

#endif

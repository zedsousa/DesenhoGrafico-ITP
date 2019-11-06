#ifndef DEFAULT_H
#define DEFAULT_H
#include "structs.h"

//default functions
//são funções considerando as opções do exemplo lá 
void makeImage(point P);
void cleanImage(color C);
void colorImage(color C);
void setPixel(int x,int y,int w,int h,color (*C)[w],color Color);
void makeLine(point a,point b,int w,int h,color (*C)[w]);
void makeCircle(point P,int radius);
void makePolygon(int n,point *P,int w,int h,color (*C)[w]);
void makeRect(point p,int height,int width,int w,int h,color (*C)[w]);
void fillForm(point P);
void saveImage(FILE *arq);

#endif

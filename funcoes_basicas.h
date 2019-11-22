#ifndef FUNCOES_BASICAS_H
#define FUNCOES_BASICAS_H
#include "structs.h"

color **makeImage(int width, int height);
void cleanImage(clear Clear,int x,int y,color **C);
void colorImage(color C);
void setPixel(int x,int y,color Color,color** C,int w,int h);
void makeLine(point a,point b,color **C,int w,int h,color c);
void makeCircle(int x,int y,int r,color c,color **C,int w,int h);
void makePolygon(int n,point *P,int w,int h,color** C,color c);
void makeRect(point p,int width,int height, color** C,int w,int h,color c);
void fillForm(int x, int y,color oldColor, color newColor, int width, int height, color** C);
void saveImage(int x,int y, char *filename,color **c);

#endif

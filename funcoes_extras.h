#ifndef FUNCOES_EXTRAS_H
#define FUNCOES_EXTRAS_H
#include "structs.h"

void negative(int width,int height,color **OriginalMatrix);
void threshold(int limit,int height,int width,color **OriginalMatrix);
void reduce(int width,int height,color **OriginalMatrix);
void makePolygon3D(int n,point *P,int w,int h,color** C,color c);
#endif

#ifndef EXTRAS_H
#define EXTRAS_H
#include "structs.h"

//extra functions

void negative(int width,int height,color **OriginalMatrix);
void threshold(int limit,int height,int width,color **OriginalMatrix);
void expand(int percentage,int width,int height,color **OriginalMatrix);
void reduce(int width,int height,color **OriginalMatrix);
void turn(int angle,int height,int width,color Color,color **OriginalMatrix);
void makePolygon3D(int n,point *P,int w,int h,color** C,color c);
#endif

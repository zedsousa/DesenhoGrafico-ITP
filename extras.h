#ifndef EXTRAS_H
#define EXTRAS_H
#include "structs.h"

//extra functions
color bilinearInterpolation(int x,int y,color **OriginalMatrix);
void negative(int width,int height,color **OriginalMatrix);
void threshold(int limit,int height,int width,color **OriginalMatrix);
void expand(int percentage,color **OriginalMatrix,color Color);
void reduce(int percentage,color **OriginalMatrix,color Color);
void turn(int angle,int height,int width,color Color,color **OriginalMatrix);
#endif

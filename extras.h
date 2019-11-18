#ifndef EXTRAS_H
#define EXTRAS_H
#include "structs.h"

//extra functions
color bilinearInterpolation(int x,int y,color **OriginalMatrix);
void negative(int w,int h,color **OriginalMatrix);
void threshold(int limit,color **OriginalMatrix);
void expand(int percentage,color **OriginalMatrix);
void reduce(int percentage,color **OriginalMatrix);
void turn(int angle,color **OriginalMatrix);
#endif

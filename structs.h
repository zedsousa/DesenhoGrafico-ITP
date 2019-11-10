#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct color{
	int r;
	int g;
	int b;
}color;

typedef struct point{
   int x;
   int y;
}point;

typedef struct image{
    int x;
    int y;
} image;

typedef struct clear{
    color Color;
} clear;

typedef struct line{
    point P[2];
} line;

typedef struct polygon{
    int n; 
    point *P;
} polygon;

typedef struct rect{
    point P;
    int height;
    int width;
} rect;

typedef struct circle{
    point P;
    int radius;
} circle;

typedef struct fill{
    color Color; 
    int values[2];
    int area;
} fill;

typedef struct save{
    
} save;

#endif

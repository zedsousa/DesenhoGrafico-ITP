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
   color Color;
}point;

typedef struct image{
    point P;
} image;

typedef struct clear{
    color Color;
} clear;

typedef struct line{
    point P[2];
} line;

typedef struct polygon{
    int n; 
    point P[n]; 
} polygon;

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
    FILE arq;
} save;

#endif

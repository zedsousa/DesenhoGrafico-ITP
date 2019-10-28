#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct options{
    char name[8];
} options;

typedef struct image{
    char name[8];
    int values[2];
} image;

typedef struct clear{
    char name[8];
    int values[3];
} clear;

typedef struct color{
    char name[8];
    int values[3];
} color;

typedef struct line{
    char name[8];
    int values[4];
} line;

typedef struct polygon{
    char name[8];
    int n; 
    int values[2*n]; 
} polygon;

typedef struct circle{
    char name[8];
    int values[3];
} circle;

typedef struct fill{
    color Color; 
    char name[8];
    int values[2];
    int area;
} fill;

typedef struct save{
    FILE arq;
} save;

#endif

#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct options{
    char nome[8];
} options;

typedef struct image{
    char nome[8];
    int valores[2];
} image;

typedef struct clear{
    char nome[8];
    int valores[3];
} clear;

typedef struct color{
    char nome[8];
    int valores[3];
} color;

typedef struct line{
    char nome[8];
    int valores[4];
} line;

//polygon tem uma qtd N de pontos e seus respectivos pontos (x,y)
typedef struct polygon{
    char nome[8];
    int n; 
    int valores[2*n]; 
} polygon;

typedef struct circle{
    char nome[8];
    int valores[3];
} circle;

typedef struct fill{
    color cor; 
    char nome[8];
    int valores[2];
} fill;

typedef struct save{
    FILE arq;
} save;

#endif

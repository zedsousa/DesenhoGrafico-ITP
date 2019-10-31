#ifndef DEFAULT_H
#define DEFAULT_H
#include "structs.h"

//default functions
//são funções considerando as opções do exemplo lá 
void makeImage(point P);
int cleanImage(color C);
int colorImage(color C);
int makeLine(point *P); //point P[2]
int makeCircle(point P,int radius);
int makePolygon(int n,point *P); //point P[n]
int fillForm(point P);
int saveImage(FILE *arq);

#endif

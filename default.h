#ifndef DEFAULT_H
#define DEFAULT_H

//default functions
//são funções considerando as opções do exemplo lá 
void makeImage(int line,int column);
int cleanImage(int **m);
int colorImage(int r,int g,int b);
int makeLine(int x1,int y1,int x2,int y2);
int makeCircle(int x,int y,int radius);
int makePolygon(int n,int *a);
int fillForm(int x,int y);
int saveImage(FILE *arq);

#endif
#ifndef INPUT_H
#define INPUT_H
#include <stdio.h>
#include <structs.h>

//input functions
void insertOptions(options *opcoes);
void selectValues(char *line,int *arrayValues,int lengthArray);
void selectOption(char *linha,char *palavras);
void optionOutput(char *linha, char * palavra);
void readTxt(FILE *arq);

#endif

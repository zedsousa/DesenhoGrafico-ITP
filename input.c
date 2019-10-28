#include "input.h"
#include <stdio.h>
#include <string.h>
#include <structs.h>
#include <math.h>

void insertOptions(options *Options){
	strcat(Options[0].name, "image");
	strcat(Options[1].name, "clear");
	strcat(Options[2].name, "color");
	strcat(Options[3].name, "line");
	strcat(Options[4].name, "polygon");
	strcat(Options[5].name, "circle");
	strcat(Options[6].name, "fill");
	strcat(Options[7].name, "save");
}

void selectValues(char *line,int *arrayValues,int lengthArray){
	int i,j,count,aux,value;
	int lengthLine,exponent;
	lengthLine = strlen(line);
	exponent = 2;
	value = 0;
	count = 0; j=0;
	for(i=0;i<lengthLine;i++){
			if((int)line[i]>=48&&line[i]<=57){ //search for 0-9 characters in the string Line
				if((int)line[i-1]!=32&&line[i+1]!=32){ //search for blank spaces towards one character ex: polygon*2*120 235 143 254
					aux = (int)line[i]-48;
					aux = aux*(pow(10,exponent));
					value+=aux;
					aux=0;
					exponent--;
					count++;
				}
			}
			do{
				if(count==3){
					arrayValues[j]=value;
					value=0;
					count=0;
					j++;
				}
				if(j==lengthArray) break;
			}while(j<lengthArray);
	}
}

void selectOption(char *Line,options *Options,char *newWord){
	int i,j,k,n;
	int lengthOptions,lengthLine,countCharacter;
	countCharacter; 
	lengthOptions= strlen(Options);
	for(i=0;i<lengthOptions;i++){
		lengthLine = strlen(Line);
		k=0;
		n = strlen(Options[i].name);
		for(j=0;j<lengthLine;j++){
			if(Line[j]==Options[i].name[k])
				countCharacter++;
			k++;
			if(countCharacter>=n){
				printf("Valid option.\n");
				strncat(newWord,Line,countCharacter);
				break;
			}else{
				printf("Invalid option.\n");
			}
		}
	}
}

void optionOutput(char *line, char *word,int *arrayValues){
	switch (word){
		case "image":
			/* code */
			break;

		case "color":
			/* code */
			break;
		
		case "circle":
			/* code */
			break;

		case "polygon":
			/* code */
			break;
		
		case "line":
			/* code */
			break;

		case "fill":
			/* code */
			break;

		case "save":
			/* code */
			break;
		
		case "clear":
			/* code */
			break;
		
		default:
			break;
	}
}

void readTxt(FILE *arq){
	char Line[100];
	char *result;
	int i;
    arq = fopen("ArqTeste.txt", "rt");
	if (arq == NULL) {
		printf("File opening error\n");
		return;
	}
	i = 1;

	while (!feof(arq)){ 	
		result = fgets(Line, 100, arq); 
		if (result) 
		printf("Line %d : %s",i,Line);
		options Options[8];
		void insertOptions(Options);
		char newWord[8]; 
		int arrayValues[6];
		selectOption(Line,Options,newWord);
		selectValues(Line,arrayValues,6);
		//function optionOutput
		i++;
	}
	fclose(arq);
}

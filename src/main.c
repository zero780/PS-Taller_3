#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cifrado.h"

int main(int argc, char **argv){
	char entrada[T_LINEA];
	 if (argc < 5){
                return -1;
        }

	if((strcmp(argv[1],"-t")==0) && (strcmp(argv[2],"ciclico")==0) && (strcmp(argv[3],"-p")==0)){
		fgets(entrada,T_LINEA, stdin);
		reemplazar(entrada, T_LINEA);
		lowCase(entrada);
                cifrado_ciclico(entrada, atoi(argv[4]));
        }
	else if((strcmp(argv[1],"-t")==0) && (strcmp(argv[2],"autollave")==0) && (strcmp(argv[3],"-p")==0)){
		fgets(entrada,T_LINEA,stdin);
		reemplazar(entrada, T_LINEA);
		cifrado_autollave(entrada,argv[4]);
	}
	return 0;
}

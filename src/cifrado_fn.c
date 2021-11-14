#include <stdio.h>
#include <string.h>
#include <ctype.h>

void reemplazar(char *texto, int n){
        for(int i=0; i<n; i++){
                if(texto[i]=='\n'){
                        texto[i]='\0';
                }
        }
}

void lowCase(char *entrada){
	int tam = strlen(entrada);
	for (int i =0; i< tam; i++){
		entrada[i]=tolower(entrada[i]);
	}
}


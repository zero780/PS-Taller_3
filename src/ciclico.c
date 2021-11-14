#include <stdio.h>
#include <string.h>
#include "cifrado.h"

void cifrado_ciclico(char *entrada, int clave){
	char *tabla = "abcdefghijklmnopqrstuvwxyz";
	char cifradoF[T_LINEA]={0};
	char salidaStr[2];
        salidaStr[1]='\0';
	char letraStr[2];
        letraStr[1]='\0';
	for(int i =0; i<strlen(entrada); i++){
		letraStr[0]= entrada[i];
		if(entrada[i]==' '){
			salidaStr[0]=' ';
			strcat(cifradoF,salidaStr);
		}

		else{
			int posLetra = strcspn(tabla, letraStr);
			int modulo1 = clave;
			if(clave >=0){
				int restoTabla = strlen(tabla)-posLetra-1;
                        	if(clave >=  strlen(tabla)){
                                	modulo1 = clave % strlen(tabla);
                        	}
                        	if(modulo1 > restoTabla){
                                	modulo1-= restoTabla;
                                	salidaStr[0]=tabla[modulo1-1];
                        	}
                        	else{
                                	salidaStr[0]=tabla[posLetra+modulo1];
                        	}

				strcat(cifradoF,salidaStr);
			}
			//caso clave negativa
			else{
				modulo1 = clave*-1;
				int restoTabla = posLetra;
				if((modulo1) >=  strlen(tabla)){
                                        modulo1 = (clave*-1) % strlen(tabla);
                                }
                                if(modulo1 > restoTabla){
                                        modulo1-= restoTabla;
                                        salidaStr[0]=tabla[strlen(tabla)-modulo1];
                                }
                                else{
                                        salidaStr[0]=tabla[posLetra-modulo1];
                                }
                                strcat(cifradoF,salidaStr);
			}
		}
	}
	printf("%s\n",cifradoF);
}

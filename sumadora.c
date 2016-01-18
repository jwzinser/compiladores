// paquete para usar las expresiones regulares
#include <regex.h> 
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

// hacer dos bloques, uno para el numero y otro para los espacios en blanco y signos de mas      


int main(int argc, char *argv[]) 
{ 	
	char palabra[256];
	cin >> palabra;
	// inicializar el vector donde iran lo numeros que se van a sumar
	int numeros_a_sumar[1024] = {[0 ... 1023] = 0};
	int numero_suma=0;
	bool error=FALSE;

	int i=0;
	while(palabra[i]!='\0')
	{
		if(i==0 && palabra[i]!="^[0-9]+$")
		{
			error=TRUE;
		}

		if(palabra[i]=="^[0-9]+$")
		{
			// iniciar el while que guarda el numero 
			char numero[256];
			while(palabra[i]=="^[0-9]+$")
			{
				strcat( numero, palabra[i] );
				i++;
			}
			numeros_a_sumar[numero_suma]=numero; //falta convertirlo a integer, ahorita esta en char
			numero_suma++;
		}

		if(palabra[i]!="^[0-9]+$")
		{
			// iniciar el while que guarda los espacios 
			bool signo_mas=FALSE; // variable que indica si ya hubo un signo de mas o todavia no
			while(palabra[i]!="^[0-9]+$")
			{
				if(palabra[i]=='+')
				{
					if (signo_mas)
					{
						error=TRUE;
						break;
					}
					else
					{
						signo_mas=TRUE;
					}
					i++;
				}
				else
				{
					if(palabra[i]!=' ')
					{
						break;
					}
					i++;
				}


			}
		}

	}
	if(!error)
	{
		int resultado=0;
		for (i = 0; i < 1024; i++) 
		{
			resultado=+ numeros_a_sumar[i];
		}
		cout >> resultado;
	}
	else
	{
		printf("ERROR");

	}

}

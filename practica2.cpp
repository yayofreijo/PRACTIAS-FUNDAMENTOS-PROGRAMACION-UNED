/**************************************
* NOMBRE: #Alvaro#
* PRIMER APELLIDO: #Freijo#
* SEGUNDO APELLIDO: #Pineiro#
* DNI: #34282248#
* EMAIL: #afreijo5@alumno.uned.es#
***************************************/

#include <stdio.h>

int main() {
	int lado;                                                                     /* longitud del lado más externo del rombo */

/* Preguntar el lado maximo del rombo e imprimir el espacio entre la pregunta y el rombo */
	printf("¿Lado del rombo? ");
	scanf("%d", &lado);
	printf("\n");

/* Iniciamos el bucle del triangulo superior */
	if ((lado >= 1) && (lado <=20)) {
		for (int linea = 1; linea <= lado; linea++) {
			for (int blancos = 1; blancos <= (lado - linea); blancos++) {
				printf(" ");
			}
			for (int carac = 1; carac <= linea; carac++) {
				if(carac % 4 == 1) {
					printf("@");
				}
				if(carac % 4 == 2) {
					printf(".");
				}
				if(carac % 4 == 3) {
					printf("o");
				}
				if(carac % 4 == 0) {
					printf(".");
				}
			}	
			for (int carac = (linea - 1); carac >= 1; carac--) {
				if(carac % 4 == 1) {
					printf("@");
				}
				if(carac % 4 == 2) {
					printf(".");
				}
				if(carac % 4 == 3) {
					printf("o");
				}
				if(carac % 4 == 0) {
					printf(".");
				}
			}	
			printf("\n");
		}	
		for (int linea = 1; linea <= (lado - 1); linea++) {
			for (int blancos = 1; blancos <= linea; blancos++) {
				printf(" ");
			}
			for (int carac = 1; carac <= (lado - linea); carac++) {
				if(carac % 4 == 1) {
					printf("@");
				}	
				if(carac % 4 == 2) {
					printf(".");
				}	
				if(carac % 4 == 3) {
					printf("o");
				}	
				if(carac % 4 == 0) {
					printf(".");
				}
			}	
			for (int carac = (lado - linea) - 1; carac >= 1; carac--) {
				if(carac % 4 == 1) {
					printf("@");
				}	
				if(carac % 4 == 2) {
					printf(".");
				}	
				if(carac % 4 == 3) {
					printf("o");
				}	
				if(carac % 4 == 0) {
					printf(".");
				}
			}		
			printf("\n");
		}	
	}
}

/**************************************
* NOMBRE: #Alvaro#
* PRIMER APELLIDO: #Freijo#
* SEGUNDO APELLIDO: #Pineiro#
* DNI: #34282248#
* EMAIL: #afreijo5@alumno.uned.es#
***************************************/

/*******************************************************************************************
* Programa principal para gestionar la distribucion de farmacos mediante un dron: FarmaDron *
 *******************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "menu.h"

int main () {
	MENU menucompleto;
	menucompleto.MaximoAlmacenes = 0;

	printf("\n\nF      A      R      M      A      D       R       O       N\n");
	while(menucompleto.LetraMenu != 'S' || menucompleto.LetraMenu != 's') {
		menucompleto.ImprimirMenu();
		menucompleto.ElegirLetra();
		if(menucompleto.LetraMenu == 'S' || menucompleto.LetraMenu == 's') {
		  return 0;
	  	}
	}
}

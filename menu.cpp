/**************************************
* NOMBRE: #Alvaro#
* PRIMER APELLIDO: #Freijo#
* SEGUNDO APELLIDO: #Pineiro#
* DNI: #34282248#
* EMAIL: #afreijo5@alumno.uned.es#
***************************************/

/*******************************************************************************
* Implementacion del modulo Menu para la practica 5 basada en el dron FarmaDron *
 *******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "menu.h"

void MENU::IniciarHuecosAlta() {
	for(int k=1; k<=20; k++) {
		HuecoOcupadoAlta[k] = false;
	}
}

void MENU::IniciarHuecosFarmaco() {
	for(int k=1; k<=5; k++) {
		DatosPedido.HuecoOcupadoFarmacos[k] = false;
	}
}

void MENU::IniciarHuecosPedido() {
	for(int k=1; k<=100; k++) {
		HuecoOcupadoPedidos[k] = false;
	}
}

void MENU::IniciarHuecosAlmacen() {
	for (int k=1; k<=10; k++) {
		HuecoOcupadoAlmacen[k] = false;
	}
}

void MENU::ImprimirMenu() {
	printf("\n\n============================================================\n");
	printf("Gestion de FarmaDrones: Distribucion de Farmacos\n");
	printf("     Iniciar gestion                     (Pulsar I)\n");
	printf("     Alta almacen                        (Pulsar M)\n");
	printf("     Alta paciente almacen               (Pulsar A)\n");
	printf("     Ubicar pacientes                    (Pulsar U)\n");
	printf("     Nuevo pedido                        (Pulsar N)\n");
	printf("     Lista diaria de pedidos             (Pulsar L)\n");
	printf("     Programar rutas diarias del Dron    (Pulsar P)\n");
	printf("     Salir                               (Pulsar S)\n");
	printf("Teclear una opcion valida (A|U|N|L|C|S)");
	scanf("%s", &LetraMenu);
	printf("============================================================\n\n");
}

void MENU::ElegirLetra() {
	switch (LetraMenu) {
		case 'I':
		case 'i':
		printf("\n\nAqui iria la opcion Iniciar Gestion\n");
		break;
		case 'M':
		case 'm':
		AltaAlmacen();
		break;
		case 'A':
		case 'a':
		AltaNueva();
		break;
		case 'U':
		case 'u':
		UbicacionPacientes();
		break;
		case 'N':
		case 'n':
		NuevoPedido();
		break;
		case 'L':
		case 'l':
		ListaPedidos();
		break;
		case 'P':
		case 'p':
		printf("\n\nAqui iria la opcion Programar rutas diarias del Dron\n");
		break;
		case 'S':
		case 's':
		printf("\n\n                   A    D    I    O    S\n");
		break;
		default:
		printf("\n\nCaracter invalido para la opcion de Elegir letra del Menu\n");
	}
}



void MENU::AltaAlmacen(){
	int ind1=0;
	int ind2=0;
	int ind3=0;
	int ind4=0;

	bool HuecoEncontradoAlmacen = false;

	for (int k=0; k<=48; k++) {                             /* Bucle para convertir en nulo todos los huecos del vector de Direccion Almacen */
	Almacen.DireccionAlmacen[k] = '\0';
	}
	for (int k=0; k<=48; k++) {                             /* Bucle para convertir en nulo todos los huecos del vector de Direccion Almacen auxiliar */
	DireccionAlmacenAux[k] = '\0';
	}
	for (int k=0; k<=48; k++) {                             /* Bucle para convertir en nulo todos los huecos del vector de Municipio Almacen */
	Almacen.MunicipioAlmacen[k] = '\0';
	}
	for (int k=0; k<=48; k++) {                             /* Bucle para convertir en nulo todos los huecos del vector de Municipio Almacen auxiliar */
	MunicipioAlmacenAux[k] = '\0';
	}
	for (int k=0; k<=16; k++) {                             /* Bucle para convertir en nulo todos los huecos del vector de Provincia Almacen */
	Almacen.ProvinciaAlmacen[k] = '\0';
	}
	for (int k=0; k<=16; k++) {                             /* Bucle para convertir en nulo todos los huecos del vector de Provincia Almacen auxiliar */
	ProvinciaAlmacenAux[k] = '\0';
	}
	for (int k=0; k<=48; k++) {                             /* Bucle para convertir en nulo todos los huecos del vector de Descripcion Almacen */
	Almacen.DescripcionAlmacen[k] = '\0';
	}
	for (int k=0; k<=48; k++) {                             /* Bucle para convertir en nulo todos los huecos del vector de Descripcion Almacen auxiliar */
	DescripcionAlmacenAux[k] = '\0';
	}


	printf("\nAlta nuevo almacen:\n\n");
	printf("      Identificador almacen (cod. de almacen 1 a 10)? ");
	try {
		scanf("%d", &Almacen.IdentificadorAlmacen);
		if (Almacen.IdentificadorAlmacen <1 || Almacen.IdentificadorAlmacen >10) {
			throw error16;
		}
		for (int k=1; k<=10; k++) {
			if(HuecoOcupadoAlmacen[k] == true && Almacen.IdentificadorAlmacen == k) {
				throw error16;
			}
		}		
	}
	catch (ErroresPrograma error16) {
		printf("\n\nDato incorrecto para Identificador del almacen: dato fuera del rango permitido o ya en uso\n");
		return;
	}
	printf("      Direccion almacen (entre 1 y 48 caracteres)? ");
	try {
		fflush(stdin);
		gets(DireccionAlmacenAux);                                                     /* En vez de scanf para poder meter espacios en Direccion Almacen */
		DireccionAlmacenAux[strcspn(DireccionAlmacenAux, "\r\n")] = 0;                 /* Para eliminar el salto de linea del final de Direccion Almacen */
		for (int k=0; k<=48; k++) {
			if (DireccionAlmacenAux[k] != '\0') {
				if (!isprint(DireccionAlmacenAux[k]) && DireccionAlmacenAux[k] != '\0') {
					throw error17;
				}
			}
		}
		if(strlen(DireccionAlmacenAux) > 48) {
			throw error17;
		}
		while (DireccionAlmacenAux[ind1] != '\0' && ind1 <= 48) {
			Almacen.DireccionAlmacen[ind1] = DireccionAlmacenAux[ind1];
			ind1++;
		}
	}	
	catch (ErroresPrograma error17) {
		printf("\n\nCaracter invalido en 'Direccion Almacen' o superado el limite maximo de caracteres\n");
		return;
	}
	printf("      Municipio almacen (entre 1 y 48 caracteres)? ");
	try {
		fflush(stdin);
		gets(MunicipioAlmacenAux);                                                     /* En vez de scanf para poder meter espacios en Municipio Almacen */
		MunicipioAlmacenAux[strcspn(MunicipioAlmacenAux, "\r\n")] = 0;                 /* Para eliminar el salto de linea del final de Municipio Almacen */
		for (int k=0; k<=48; k++) {
			if (MunicipioAlmacenAux[k] != '\0') {
				if (!isalpha(MunicipioAlmacenAux[k]) && MunicipioAlmacenAux[k] != ' ' && MunicipioAlmacenAux[k] != '\0') {
					throw error18;
				}
			}
		}
		if(strlen(MunicipioAlmacenAux) > 48) {
			throw error18;
		}
		while (MunicipioAlmacenAux[ind2] != '\0' && ind2 <= 48) {
			Almacen.MunicipioAlmacen[ind2] = MunicipioAlmacenAux[ind2];
			ind2++;
		}
	}	
	catch (ErroresPrograma error18) {
		printf("\n\nCaracter invalido en 'Municipio almacen' o superado el limite maximo de caracteres\n");
		return;
	}
	printf("      Provincia almacen (entre 1 y 16 caracteres)? ");
	try {
		fflush(stdin);
		gets(ProvinciaAlmacenAux);                                                     /* En vez de scanf para poder meter espacios en Provincia Almacen */
		ProvinciaAlmacenAux[strcspn(ProvinciaAlmacenAux, "\r\n")] = 0;                 /* Para eliminar el salto de linea del final de Provincia Almacen */
		for (int k=0; k<=16; k++) {
			if (ProvinciaAlmacenAux[k] != '\0') {
				if (!isalpha(ProvinciaAlmacenAux[k]) && ProvinciaAlmacenAux[k] != ' ' && ProvinciaAlmacenAux[k] != '\0') {
					throw error19;
				}
			}
		}
		if(strlen(ProvinciaAlmacenAux) > 16) {
			throw error19;
		}
		while (ProvinciaAlmacenAux[ind3] != '\0' && ind3 <= 16) {
			Almacen.ProvinciaAlmacen[ind3] = ProvinciaAlmacenAux[ind3];
			ind3++;
		}
	}	
	catch (ErroresPrograma error19) {
		printf("\n\nCaracter invalido en 'Provincia almacen' o superado el limite maximo de caracteres\n");
		return;
	}
	printf("      Descripcion almacen (entre 1 y 16 caracteres)? ");
	try {
		fflush(stdin);
		gets(DescripcionAlmacenAux);                                                     /* En vez de scanf para poder meter espacios en Descripcion Almacen */
		DescripcionAlmacenAux[strcspn(DescripcionAlmacenAux, "\r\n")] = 0;                 /* Para eliminar el salto de linea del final de Descripcion Almacen */
		for (int k=0; k<=48; k++) {
			if (DescripcionAlmacenAux[k] != '\0') {
				if (!isalpha(DescripcionAlmacenAux[k]) && DescripcionAlmacenAux[k] != ' ' && DescripcionAlmacenAux[k] != '\0') {
					throw error20;
				}
			}
		}
		if(strlen(DescripcionAlmacenAux) > 48) {
			throw error20;
		}
		while (DescripcionAlmacenAux[ind4] != '\0' && ind4 <= 48) {
			Almacen.DescripcionAlmacen[ind4] = DescripcionAlmacenAux[ind4];
			ind4++;
		}
	}	
	catch (ErroresPrograma error20) {
		printf("\n\nCaracter invalido en 'Descripcion almacen' o superado el limite maximo de caracteres\n");
		return;
	}
	printf("\nDatos correctos (S/N)? ");
	scanf("%s", &almacencorrecto);
	try {
		if (almacencorrecto == 'S' || almacencorrecto == 's') {
			for (int k=1; k<=10 && (HuecoEncontradoAlmacen==false); k++) {
				if(HuecoOcupadoAlmacen[k] == false && Almacen.IdentificadorAlmacen == k) {
					HuecoEncontradoAlmacen = true;
					TotalAlmacenes[k] = Almacen;                   /* Aqui se meten los datos introducidos en Almacen en el vector TotalAlmacenes */
					HuecoOcupadoAlmacen[k] = true;
					MaximoAlmacenes++;
				}
			}
			if (MaximoAlmacenes == 10) {
				printf("\n\nMaximo de almacenes alcanzado\n");
			}
		}	
		else if (almacencorrecto == 'N' || almacencorrecto == 'n') {
			AltaAlmacen();
		}
		else {
			throw error21;
		}
	}
	catch (ErroresPrograma error21) {
		printf("\n\nCaracter invalido para Datos Correctos\n");
		return;
	}	
}




void MENU::AltaNueva () {
	TipoUbicacion FilaUbicaciones;                          /* Variable local para cada fila de la lista de ubicaciones */
	int w = 0;                                              /* Variable local para comprobar longitud de Identificador */
	bool HuecoEncontradoAlta, EncontradoAlmacen;

	HuecoEncontradoAlta = false;                       /* Variable para saber si existe un hueco libre en el vector de ubicaciones */
	EncontradoAlmacen = false;                         /* Variable para indicar si existe el almacen que se introduce en codigo almacen o no */

	for (int k=0; k<=20; k++) {                             /* Bucle para convertir en nulo todos los huecos del vector de Identificador */
	FilaUbicaciones.Identificador[k] = '\0';
	}
	for (int k=0; k<=20; k++) {                             /* Bucle para convertir en nulo todos los huecos del vector de Identificador auxiliar */
	IdentificadorAux[k] = '\0';
	}

	printf("\nAlta nuevo paciente\n\n");
	printf("      Codigo de almacen (entre 1 y 10)? ");
	try {
		scanf("%d", &FilaUbicaciones.AlmacenPaciente);
		if (FilaUbicaciones.AlmacenPaciente <1 || FilaUbicaciones.AlmacenPaciente >10) {
			throw error22;
		}
		for (int i=1; i<=10; i++) {
			if (TotalAlmacenes[i].IdentificadorAlmacen == FilaUbicaciones.AlmacenPaciente) {
				EncontradoAlmacen = true;
			}
		}
		if (EncontradoAlmacen == false) {
			throw error22;
		}
	}
	catch (ErroresPrograma error22) {
		printf("\n\nDato incorrecto para Codigo Almacen: fuera del rango o el almacen introducido no existe aun\n");
		return;
	}	
	printf("\nDatos paciente:\n\n");	
	printf("      Identificador (Entre 1 y 20 caracteres)? ");
	try {
		fflush(stdin);
		gets(IdentificadorAux);                                                  /* En vez de scanf para poder meter espacios en Identificador */
		IdentificadorAux[strcspn(IdentificadorAux, "\r\n")] = 0;                 /* Para eliminar el salto de linea del final de Identificador */
		for (int indice=0; indice<=20; indice++) {
			if (IdentificadorAux[indice] != '\0') {
				if (!isalpha(IdentificadorAux[indice]) && IdentificadorAux[indice] != ' ' && IdentificadorAux[indice] != '\0') {
					throw error1;
				}
			}
		}
		if(strlen(IdentificadorAux) > 20) {
			throw error1;
		}
		while (IdentificadorAux[w] != '\0' && w <= 20) {
			FilaUbicaciones.Identificador[w] = IdentificadorAux[w];
			w++;
		}
	}	
	catch (ErroresPrograma error1) {
		printf("\n\nCaracter invalido en 'Identificador' o superado el limite maximo de caracteres\n");
		return;
	}
	printf("      Distancia(hasta 10000 metros a plena carga)? ");
	try {
		scanf("%5d", &FilaUbicaciones.Distancia);
		if (FilaUbicaciones.Distancia <0 || FilaUbicaciones.Distancia >10000) {
			throw error2;
		}
	}
	catch (ErroresPrograma error2) {
		printf("\n\nDistancia incorrecta\n");
		return;
	}
	printf("      Angulo (entre 0 y 2000 pi/1000 radianes)? ");
	try {
		scanf("%4d", &FilaUbicaciones.Angulo);
		if (FilaUbicaciones.Angulo <0 || FilaUbicaciones.Angulo >2000) {
			throw error3;
		}
	}
	catch (ErroresPrograma error3) {
		printf("\n\nAngulo fuera del rango permitido\n");
		return;
	}	
	printf("\n");
	printf("Datos correctos (S/N)? ");
	try {
		scanf("%s", &i);
		if(i=='s' || i=='S') {
			for (int k=1; k<=20 && (HuecoEncontradoAlta == false); k++) {
				printf("%s", HuecoOcupadoAlta);
				if(HuecoOcupadoAlta[k] == false) {
				  	HuecoEncontradoAlta = true;
					FilaUbicaciones.Referencia = k;
					TotalAlmacenes[FilaUbicaciones.AlmacenPaciente].UbicacionesAlmacen[k] = FilaUbicaciones;                   /* Aqui se meten los datos introducidos en FilaUbicaciones en el vector TablaUbicaciones */
					HuecoOcupadoAlta[k] = true;
					MaximoPacientes++;
				}
			}
			if (MaximoPacientes == 20) {
				printf("\n\nAlcanzado el maximo de pacientes\n");
				return;
			}
		}		
		else if(i=='N' || i=='n') {
			AltaNueva ();
		}
		else {
			throw error4;
		}
	}
	catch (ErroresPrograma error4) {
		printf("\n\nCaracter invalido para la opcion 'Datos Correctos'\n");
		return;
	}
	printf("Otro paciente en el mismo almacen (S/N)? ");
	try {
		scanf("%s", &j);
		if(j=='S' || j=='s') {
			AltaNueva();
		}
		else if (j=='N' || j=='n') {
			return;
		}
		else {
			throw error5;
		}
	}	
	catch (ErroresPrograma error5) {
		printf("\n\nCaracter invalido para 'Otro paciente'\n");
		return;
	}
}

void MENU::UbicacionPacientes () {
	int codigoubicacion;
	
	printf("\nLista de pacientes y su ubicacion:\n");
	printf("\n      Codigo almacen? ");
	try {
		scanf("%d", &codigoubicacion);
		if (codigoubicacion <1 || codigoubicacion >10) {
			throw error24;
		}
	}
	catch (ErroresPrograma error24) {
		printf("\n\nDato incorrecto para codigo almacen\n");
		return;
	}
	for (int k=1; k<=10; k++) {
		if (codigoubicacion == TotalAlmacenes[k].IdentificadorAlmacen) {
			printf("\n      Ref.  ");
			printf("Identificador           ");
			printf("Distancia      ");
			printf("Angulo         \n");
			for(int i=1; i<=20; i++) {
				if(HuecoOcupadoAlta[i] == true) {
					printf("      %-6d%-24s%-15d%-15d\n", TotalAlmacenes[k].UbicacionesAlmacen[i].Referencia,TotalAlmacenes[k].UbicacionesAlmacen[i].Identificador, TotalAlmacenes[k].UbicacionesAlmacen[i].Distancia, TotalAlmacenes[k].UbicacionesAlmacen[i].Angulo);
				}
			}
			return;
		}
		else {
			printf("\n\nDato incorrecto para codigo almacen: o no tiene pacientes asignados, o no esta creado aun\n");
			return;
		}
	}	
}

void MENU::NuevoPedido() {
	bool codigocorrecto = false;

	DatosPedido.PesoTotalEnvio = 0;

	IniciarHuecosFarmaco();

	for (int indice=0; indice<=5; indice++) {                                           /* Bucle para convertir en nulo todos los huecos del vector Farmaco */
		for (int k=0; k<=20; k++) {
			DatosPedido.DatosFarmaco[indice].Farmaco[k] = '\0';
		}
	}

	printf("\n\nNuevo Pedido:\n\n");
	printf("      Codigo almacen? ");
	try {
		scanf("%d", &DatosPedido.AlmacenPedido);
		if (DatosPedido.AlmacenPedido <1 || DatosPedido.AlmacenPedido >10) {
			throw error25;
		}
		for (int k=1; k<=10; k++) {
			if (DatosPedido.AlmacenPedido == TotalAlmacenes[k].IdentificadorAlmacen) {
				codigocorrecto = true;
			}
		}
		if (codigocorrecto == false) {
			throw error25;
		}
	}
	catch (ErroresPrograma error25) {
		printf("\n\nDato incorrecto para codigo almacen: o fuera de rango, o el almacen no existe aun\n");
		return;
	}	
	printf("      Ref. Paciente (entre 1 y 20? ");
	try {
		scanf("%d", &DatosPedido.RefPedido);
		if(DatosPedido.RefPedido <1 || DatosPedido.RefPedido >20) {
			throw error6;
		}
	}
	catch (ErroresPrograma error6) {
		printf("\n\nReferencia incorrecta\n");
		return;
	}
	printf("      Numero de envios? ");
	try {
		scanf("%d", &DatosPedido.NumeroEnvios);
		if (DatosPedido.NumeroEnvios <1 || DatosPedido.NumeroEnvios >100) {
			throw error26;
		}
	}	
	catch (ErroresPrograma error26) {
		printf("\n\nNumero de envios fuera del rango permitido\n");
		return;
	}
	if (DatosPedido.NumeroEnvios == 1) {
		printf("      Dia del envio? ");
		try {
			scanf("%d", &DatosPedido.Fecha.Dia);
			printf("      Mes del envio? ");
			scanf("%d", &DatosPedido.Fecha.Mes);
			printf("      Año del envio? ");
			scanf("%d", &DatosPedido.Fecha.Anho);
			switch (DatosPedido.Fecha.Mes) {
				case 2:
				if (DatosPedido.Fecha.Anho % 4 == 0 && DatosPedido.Fecha.Anho % 100 != 0 || DatosPedido.Fecha.Anho % 400 == 0) { 
					if (DatosPedido.Fecha.Dia <1 || DatosPedido.Fecha.Dia >29) {
						throw error7;
					}
				}	
				else {
					if (DatosPedido.Fecha.Dia <1 || DatosPedido.Fecha.Dia >28) {
						throw error7;
					}
				}
				break;	
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12:
				if (DatosPedido.Fecha.Dia <1 || DatosPedido.Fecha.Dia >31) {
					throw error7;
				}
				break;
				case 4:
				case 6:
				case 9:
				case 11:
				if (DatosPedido.Fecha.Dia <1 || DatosPedido.Fecha.Dia >30) {
					throw error7;
				}
				break;
				default:
				throw error7;
			}
			if (DatosPedido.Fecha.Anho < 1600 || DatosPedido.Fecha.Anho >3000) {
				throw error7;
			}
		}
		catch (ErroresPrograma error7) {
			printf("\n\nFormato de fecha incorrecta\n");
			return;
		}
		pedirmasfarmacos = false;
		NuevoFarmaco();
	}	
	else if (DatosPedido.NumeroEnvios >1) {
		printf("      Numero de dias entre cada envio (Entre 1 y 15 dias)? ");
		try {
			scanf("%d", &DatosPedido.DiasEntreEnvio);
			if (DatosPedido.DiasEntreEnvio <1 || DatosPedido.DiasEntreEnvio >15) {
				throw error14;
			}
		}
		catch (ErroresPrograma error14) {
			printf("Parametros fuera del rango para la opcion 'Numero de dias entre cada envio'");
			return;
		}
		printf("      Dia del primer envio? ");
		try {
			scanf("%d", &DatosPedido.Fecha.Dia);
			printf("      Mes del primer envio? ");
			scanf("%d", &DatosPedido.Fecha.Mes);
			printf("      Año del primer envio? ");
			scanf("%d", &DatosPedido.Fecha.Anho);

			switch (DatosPedido.Fecha.Mes) {
				case 2:
				if (DatosPedido.Fecha.Anho % 4 == 0 && DatosPedido.Fecha.Anho % 100 != 0 || DatosPedido.Fecha.Anho % 400 == 0) { 
					if (DatosPedido.Fecha.Dia <1 || DatosPedido.Fecha.Dia >29) {
						throw error7;
					}
				}	
				else {
					if (DatosPedido.Fecha.Dia <1 || DatosPedido.Fecha.Dia >28) {
						throw error7;
					}
				}
				break;	
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12:
				if (DatosPedido.Fecha.Dia <1 || DatosPedido.Fecha.Dia >31) {
					throw error7;
				}
				break;
				case 4:
				case 6:
				case 9:
				case 11:
				if (DatosPedido.Fecha.Dia <1 || DatosPedido.Fecha.Dia >30) {
					throw error7;
				}
				break;
				default:
				throw error7;
			}
			if (DatosPedido.Fecha.Anho < 1600 || DatosPedido.Fecha.Anho >3000) {
				throw error7;
			}
		}
		catch (ErroresPrograma error7) {
			printf("\n\nFormato de fecha incorrecta\n");
			return;
		}
		pedirmasfarmacos = false;
		NuevoFarmaco();
	}
	else {
		printf("\n\nCaracter invalido para 'Numero de envios'\n");
		return;
	}	
}

void MENU::NuevoFarmaco() {
	int q=0;                                                                     /* Variable local para comprobar longitud de Identificador */

	HuecoEncontradoFarmaco = false;
	HuecoEncontradoPedido = false;
	
	if (pedirmasfarmacos == false) {
		printf("\n      Nombre farmaco (Entre 1 y 20 caracteres)? ");
		try {
			fflush(stdin);
			gets(FarmacoAux);                                                    /* En vez de scanf para poder meter espacios en Farmaco */
			FarmacoAux[strcspn(FarmacoAux, "\r\n")] = 0;                         /* Para eliminar el salto de linea del final de Farmaco */
			for (int k=0; k<=20; k++) {
				if (FarmacoAux[k] != '\0') {
					if (!isalpha(FarmacoAux[k]) && FarmacoAux[k] != ' ' && FarmacoAux[k] != '\0') {
						throw error8;
					}
				}
			}
			if(strlen(FarmacoAux) > 20) {
				throw error8;
			}
			while (FarmacoAux[q] != '\0' && q <= 20) {
				DatosPedido.DatosFarmaco[1].Farmaco[q] = FarmacoAux[q];
				q++;
			}
		}	
		catch (ErroresPrograma error8) {
			printf("\n\nCaracter invalido en 'Nombre farmaco' o superado el limite maximo de caracteres\n");
			return;
		}	
		printf("      Peso farmaco (Menor de 3000 gramos)? ");
		try {
			scanf("%d", &DatosPedido.DatosFarmaco[1].PesoFarmaco);
			if (DatosPedido.DatosFarmaco[1].PesoFarmaco <=0 || DatosPedido.DatosFarmaco[1].PesoFarmaco >3000) {
				throw error9;
			}
		}
		catch (ErroresPrograma error9) {
			printf("\n\nPeso del farmaco fuera del rango permitido\n");
			return;
		}	
		printf("      Unidades de farmaco? ");
		try {
			scanf("%d", &DatosPedido.DatosFarmaco[1].NumeroFarmacos);
			DatosPedido.DatosFarmaco[1].PesoTotalFarmacos = DatosPedido.DatosFarmaco[1].PesoFarmaco * DatosPedido.DatosFarmaco[1].NumeroFarmacos;
			DatosPedido.HuecoOcupadoFarmacos[1] = true;
			DatosPedido.PesoTotalEnvio = DatosPedido.DatosFarmaco[1].PesoTotalFarmacos + DatosPedido.PesoTotalEnvio;
			if (DatosPedido.PesoTotalEnvio <0 || DatosPedido.PesoTotalEnvio >3000) {
				throw error13;
			}
		}
		catch (ErroresPrograma error13) {
			printf("\n\nSuperado el maximo de peso permitido\n");
			return;
		}		
		printf("\n      Otro farmaco (S/N)? ");
		scanf("%s", &otrofarmaco);
		if (otrofarmaco == 'S' || otrofarmaco == 's') {
			pedirmasfarmacos = true;
			NuevoFarmaco();
			return;
		}
		else if(otrofarmaco == 'N' || otrofarmaco == 'n') {
			for(int k=1; k<=100 && HuecoEncontradoPedido==false; k++) {
				if(HuecoOcupadoPedidos[k] == false) {
					HuecoEncontradoPedido = true;
					TotalAlmacenes[DatosPedido.AlmacenPedido].ListaPedidosAlmacen[k] = DatosPedido;                     /* Aqui guardamos los datos de DatosPedido en el vector ListaTotalPedidos en cada almacen */
					HuecoOcupadoPedidos[k] = true;
					switch(DatosPedido.Fecha.Mes) {
						case 1:
						case 3:
						case 5:
						case 7:
						case 8:
						case 10:
						case 12:
						DiasMesEnvio = 31;
						break;
						case 2:
						if (DatosPedido.Fecha.Anho % 4 == 0 && DatosPedido.Fecha.Anho % 100 != 0 || DatosPedido.Fecha.Anho % 400 == 0) {
							DiasMesEnvio = 29;
						}
						else {
							DiasMesEnvio = 28;
						}	
						break;
						default:
						DiasMesEnvio = 30;
					}
					for (int indice=1; indice< DatosPedido.NumeroEnvios; indice++) {
						if (DiasMesEnvio/(DatosPedido.Fecha.Dia + DatosPedido.DiasEntreEnvio) >=1) {
							try {
								DatosPedido.Fecha.Dia = DatosPedido.Fecha.Dia + DatosPedido.DiasEntreEnvio;
								if(k+indice <=100) { 
									TotalAlmacenes[DatosPedido.AlmacenPedido].ListaPedidosAlmacen[k+indice] = DatosPedido;        /* Aqui guardamos los nuevos datos de dia, mes y año de DatosPedido en el vector ListaTotalPedidos de cada almacen*/
									HuecoOcupadoPedidos[k+indice] = true;
								}
								else if (k+indice >100) {
									throw error15;
								}
							}
							catch (ErroresPrograma error15) {
								printf ("\n\nMaximo de pedidos alcanzado\n");
								return;
							}		
						}	
						else if (DiasMesEnvio/(DatosPedido.Fecha.Dia + DatosPedido.DiasEntreEnvio) <1) {
							try {
								DatosPedido.Fecha.Dia = (DatosPedido.Fecha.Dia + DatosPedido.DiasEntreEnvio) % DiasMesEnvio;
								if (k+indice <=100) {
									if ((DatosPedido.Fecha.Mes+1) <=12) {
										DatosPedido.Fecha.Mes = DatosPedido.Fecha.Mes +1;
										TotalAlmacenes[DatosPedido.AlmacenPedido].ListaPedidosAlmacen[k+indice] = DatosPedido;         /* Aqui guardamos los nuevos datos de dia, mes y año de DatosPedido en el vector ListaTotalPedidos de cada almacen */
										HuecoOcupadoPedidos[k+indice] = true;
									}
									else if ((DatosPedido.Fecha.Mes+1) >12) {
										DatosPedido.Fecha.Mes = (DatosPedido.Fecha.Mes +1) % 12;
										DatosPedido.Fecha.Anho = DatosPedido.Fecha.Anho+1;
										TotalAlmacenes[DatosPedido.AlmacenPedido].ListaPedidosAlmacen[k+indice] = DatosPedido;         /* Aqui guardamos los nuevos datos de dia, mes y año de DatosPedido en el vector ListaTotalPedidos de cada almacen */
										HuecoOcupadoPedidos[k+indice] = true;
									}
								}
								else if (k+indice >100) {
									throw error15;
								}
							}
							catch (ErroresPrograma error15) {
								printf("\n\nMaximo de pedidos alcanzado\n");
								return;
							}		
						}
					}
				}
			}
			printf("      Otro pedido (S/N)? ");
			scanf("%s", &otropedido);
			if(otropedido == 'S' || otropedido == 's') {
				NuevoPedido();
				return;
			}
			else if(otropedido == 'N' || otropedido == 'n') {
				return;
			}
			else {
				printf ("\n\nCaracter invalido para la opcion 'Otro pedido'\n");
				return;
			}
		}
		else {
			printf("\n\nCaracter invalido para la opcion 'Otro farmaco'\n");
			return;
		}
	}
	else if	(pedirmasfarmacos == true) {
		for (int k=2; k<=5 && (HuecoEncontradoFarmaco==false); k++) {
			if(DatosPedido.HuecoOcupadoFarmacos[k] == false) {
				HuecoEncontradoFarmaco = true;
				printf("      Nombre farmaco (Entre 1 y 20 caracteres)? ");
				try {
					fflush(stdin);
					gets(FarmacoAux);                                                  /* En vez de scanf para poder meter espacios en Farmaco */
					FarmacoAux[strcspn(FarmacoAux, "\r\n")] = 0;                 /* Para eliminar el salto de linea del final de Farmaco */
					for (int k=0; k<=20; k++) {
						if (FarmacoAux[k] != '\0') {
							if (!isalpha(FarmacoAux[k]) && FarmacoAux[k] != ' ' && FarmacoAux[k] != '\0') {
								throw error10;
							}
						}
					}
					if(strlen(FarmacoAux) > 20) {
						throw error10;
					}
					while (FarmacoAux[q] != '\0' && q <= 20) {
						DatosPedido.DatosFarmaco[k].Farmaco[q] = FarmacoAux[q];
						q++;
					}
				}	
				catch (ErroresPrograma error10) {
					printf("\n\nCaracter invalido en 'Nombre farmaco' o superado el limite maximo de caracteres\n");
					return;
				}
				printf("      Peso farmaco (Menor de 3000 gramos)? ");
				try {
					scanf("%d", &DatosPedido.DatosFarmaco[k].PesoFarmaco);
					if (DatosPedido.DatosFarmaco[k].PesoFarmaco <=0 || DatosPedido.DatosFarmaco[k].PesoFarmaco >3000) {
						throw error11;
					}
				}
				catch (ErroresPrograma error11) {
					printf("\n\nPeso del farmaco fuera del rango permitido\n");
					return;
				}
				printf("      Unidades de farmaco? ");
				try {
					scanf("%d", &DatosPedido.DatosFarmaco[k].NumeroFarmacos);
					DatosPedido.DatosFarmaco[k].PesoTotalFarmacos = DatosPedido.DatosFarmaco[k].PesoFarmaco * DatosPedido.DatosFarmaco[k].NumeroFarmacos;
					DatosPedido.PesoTotalEnvio = DatosPedido.DatosFarmaco[k].PesoTotalFarmacos + DatosPedido.PesoTotalEnvio;
					if (DatosPedido.PesoTotalEnvio <0 || DatosPedido.PesoTotalEnvio >3000) {
						throw error12;
					}
					else {
						DatosPedido.HuecoOcupadoFarmacos[k] = true;
						MaximoFarmacos++;
					}	
				}
				catch (ErroresPrograma error12) {
					printf("\n\nSuperado el maximo de peso permitido\n");
					return;
				}	
				printf("      Otro farmaco (S/N)? ");
				scanf("%s", &otrofarmaco);
				if (otrofarmaco == 'S' || otrofarmaco == 's') {
					pedirmasfarmacos = true;
					NuevoFarmaco();
					return;
				}
				else if(otrofarmaco == 'N' || otrofarmaco == 'n') {
					for(int k=1; k<=100 && HuecoEncontradoPedido==false; k++) {
						if(HuecoOcupadoPedidos[k] == false) {
							HuecoEncontradoPedido = true;
							TotalAlmacenes[DatosPedido.AlmacenPedido].ListaPedidosAlmacen[k] = DatosPedido;              /* Aqui guardamos los nuevos datos de DatosPedido en el vector ListaTotalPedidos en cada almacen */
							HuecoOcupadoPedidos[k] = true;
							switch(DatosPedido.Fecha.Mes) {
								case 1:
								case 3:
								case 5:
								case 7:
								case 8:
								case 10:
								case 12:
								DiasMesEnvio = 31;
								break;
								case 2:
								if (DatosPedido.Fecha.Anho % 4 == 0 && DatosPedido.Fecha.Anho % 100 != 0 || DatosPedido.Fecha.Anho % 400 == 0) {
									DiasMesEnvio = 29;
								}
								else {
									DiasMesEnvio = 28;
								}	
								break;
								default:
								DiasMesEnvio = 30;
							}
							for (int indice=1; indice< DatosPedido.NumeroEnvios; indice++) {
								if (DiasMesEnvio/(DatosPedido.Fecha.Dia + DatosPedido.DiasEntreEnvio) >=1) {
									try {
										DatosPedido.Fecha.Dia = DatosPedido.Fecha.Dia + DatosPedido.DiasEntreEnvio;
										if(k+indice <=100) { 
											TotalAlmacenes[DatosPedido.AlmacenPedido].ListaPedidosAlmacen[k+indice] = DatosPedido;             /* Aqui guardamos los nuevos datos de dia, mes y año de DatosPedido en el vector ListaTotalPedidos */
											HuecoOcupadoPedidos[k+indice] = true;
										}
										else if (k+indice >100) {
											throw error15;
										}
									}
									catch (ErroresPrograma error15) {
										printf ("\n\nMaximo de pedidos alcanzado\n");
										return;
									}		
								}	
								else if (DiasMesEnvio/(DatosPedido.Fecha.Dia + DatosPedido.DiasEntreEnvio) <1) {
									try {
										DatosPedido.Fecha.Dia = (DatosPedido.Fecha.Dia + DatosPedido.DiasEntreEnvio) % DiasMesEnvio;
										if (k+indice <=100) {
											if ((DatosPedido.Fecha.Mes+1) <=12) {
												DatosPedido.Fecha.Mes = DatosPedido.Fecha.Mes +1;
												TotalAlmacenes[DatosPedido.AlmacenPedido].ListaPedidosAlmacen[k+indice] = DatosPedido;         /* Aqui guardamos los nuevos datos de dia, mes y año de DatosPedido en el vector ListaTotalPedidos */
												HuecoOcupadoPedidos[k+indice] = true;
											}
											else if ((DatosPedido.Fecha.Mes+1) >12) {
												DatosPedido.Fecha.Mes = (DatosPedido.Fecha.Mes +1) % 12;
												DatosPedido.Fecha.Anho = DatosPedido.Fecha.Anho+1;
												TotalAlmacenes[DatosPedido.AlmacenPedido].ListaPedidosAlmacen[k+indice] = DatosPedido;         /* Aqui guardamos los nuevos datos de dia, mes y año de DatosPedido en el vector ListaTotalPedidos */
												HuecoOcupadoPedidos[k+indice] = true;
											}
										}
										else if (k+indice >100) {
											throw error15;
										}
									}
									catch (ErroresPrograma error15) {
										printf("\n\nMaximo de pedidos alcanzado\n");
										return;
									}		
								}
							}
						}
					}
					printf("      Otro pedido (S/N)? ");
					scanf("%s", &otropedido);
					if(otropedido == 'S' || otropedido == 's') {
						NuevoPedido();
						return;
					}
					else if(otropedido == 'N' || otropedido == 'n') {
						return;
						
					}
					else {
						printf ("\n\nCaracter invalido para la opcion 'Otro pedido'\n");
						return;
					}
				}
				else {
					printf("\n\nCaracter invalido para la opcion 'Otro farmaco'\n");
					return;
				}
			}
		}
		if (MaximoFarmacos == 5) {
			printf("\n\nAlcanzado el numero maximo de farmacos permitido por pedido\n");
			return;
		}
	}
}


void MENU::ListaPedidos() {
	int codigolista;
	bool codigocorrectolista = false;
	
	printf("\n\nLista diaria de pedidos\n\n");
	printf("Codigo almacen? ");
	try {
		scanf("%d", &codigolista);
		if (codigolista <1 || codigolista >10) {
			throw error27;
		}
		for (int k=1; k<=10; k++) {
			if (codigolista == TotalAlmacenes[k].IdentificadorAlmacen) {
				codigocorrectolista = true;
			}
		}
		if (codigocorrectolista == false) {
			throw error27;
		}
	}
	catch (ErroresPrograma error27) {
		printf ("Dato incorrecto para codigo almacen: o valor fuera del rango permitido o el almacen indicado aun no existe");
		return;
	}	
	printf("\n      Dia? ");
	try {
		scanf("%d", &FechaLista.Dia);
		printf("      Mes? ");
		scanf("%d", &FechaLista.Mes);
		printf("      Año? ");
		scanf("%d", &FechaLista.Anho);
		switch (FechaLista.Mes) {
			case 2:
			if (FechaLista.Anho % 4 == 0 && FechaLista.Anho % 100 != 0 || FechaLista.Anho % 400 == 0) { 
				if (FechaLista.Dia <1 || FechaLista.Dia >29) {
					throw error28;
				}
			}	
			else {
				if (FechaLista.Dia <1 || FechaLista.Dia >28) {
					throw error28;
				}
			}
			break;	
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
			if (FechaLista.Dia <1 || FechaLista.Dia >31) {
				throw error28;
			}
			break;
			case 4:
			case 6:
			case 9:
			case 11:
			if (FechaLista.Dia <1 || FechaLista.Dia >30) {
				throw error28;
			}
			break;
			default:
			throw error28;
		}
		if (FechaLista.Anho < 1600 || FechaLista.Anho >3000) {
			throw error28;
		}
	}
	catch (ErroresPrograma error28) {
		printf("\n\nFormato de fecha incorrecta\n");
		return;
	}
	for (int indice=1; indice<=10; indice++) {
		if (codigolista == TotalAlmacenes[indice].IdentificadorAlmacen) {
			printf("Pedido Almacen - %s", TotalAlmacenes[indice].DescripcionAlmacen);
			for (int k=1; k<=100; k++) {
				if (FechaLista.Dia == TotalAlmacenes[indice].ListaPedidosAlmacen[k].Fecha.Dia && FechaLista.Mes == TotalAlmacenes[indice].ListaPedidosAlmacen[k].Fecha.Mes && FechaLista.Anho == TotalAlmacenes[indice].ListaPedidosAlmacen[k].Fecha.Anho) {
					printf("\n\n      Pedido %d", k);
					for (int i=1; i<=20; i++) {
						if (TotalAlmacenes[indice].ListaPedidosAlmacen[k].RefPedido == TotalAlmacenes[indice].UbicacionesAlmacen[i].Referencia) {
							printf("\nUbicacion pedido ==> Distancia: %d y Angulo: %d", TotalAlmacenes[k].UbicacionesAlmacen[i].Distancia, TotalAlmacenes[k].UbicacionesAlmacen[i].Angulo);
							for (int j=1; j<=5; j++) {
								if (TotalAlmacenes[indice].ListaPedidosAlmacen[k].HuecoOcupadoFarmacos[j] == true) {
									printf("\n%-2dUnidades        ", TotalAlmacenes[indice].ListaPedidosAlmacen[k].DatosFarmaco[j].NumeroFarmacos);
									printf("%-20s", TotalAlmacenes[indice].ListaPedidosAlmacen[k].DatosFarmaco[j].Farmaco);
									printf("Peso: %4d gramos\n", TotalAlmacenes[indice].ListaPedidosAlmacen[k].DatosFarmaco[j].PesoTotalFarmacos);
								}
							}
							printf("                  Peso total del envio");
							printf("%10d gramos\n\n", TotalAlmacenes[indice].ListaPedidosAlmacen[k].PesoTotalEnvio);
						}
					}
				}		
			}
		}	
	}	
}

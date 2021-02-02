/**************************************
* NOMBRE: #Alvaro#
* PRIMER APELLIDO: #Freijo#
* SEGUNDO APELLIDO: #Pineiro#
* DNI: #34282248#
* EMAIL: #afreijo5@alumno.uned.es#
***************************************/

/********************************************************************************
* Programa para gestionar la distribucion de farmacos mediante un dron: FarmaDron *
 ********************************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef char TipoIdentificador[21];                                    /* Tipo vector de caracteres con el maximo de caracteres permitidos en identificador y farmaco*/

typedef char TipoIdentificadorAux[];                                   /* Tipo vector de caracteres abierto auxiliar */

typedef struct TipoUbicacion {                                         /* Tipo struct con los datos que forman cada ubicacion */
	int Referencia;
	TipoIdentificador Identificador;
	int Distancia;
	int Angulo;
};

typedef struct TipoFecha {                                             /* Tipo struct de los datos que forman una fecha */
	int Dia;
	int Mes;
	int Anho;
};

typedef struct TipoFarmaco {                                           /* Tipo struct con los datos que pertenecen a cada fármaco dentro de un pedido */
	TipoIdentificador Farmaco;
	int PesoFarmaco;
	int NumeroFarmacos;
	int PesoTotalFarmacos;

};

typedef TipoFarmaco ListaFarmacos[6];                                  /* Tipo vector con el numero maximo de farmacos por pedido, que son 5 */

typedef bool EstadoHuecoFarmacos[6];                                   /* Tipo vector bool para saber si los huecos del tipo vector ListaFarmacos estan vacios o no */

typedef struct TipoPedido {                                            /* Tipo struct con los datos que forman cada pedido */
	int RefPedido;
	int NumeroEnvios;
	TipoFecha Fecha;
	ListaFarmacos DatosFarmaco;
	EstadoHuecoFarmacos HuecoOcupadoFarmacos;
	int PesoTotalEnvio;
	int DiasEntreEnvio;
};

typedef TipoPedido ListadoPedidos[101];                                /* Tipo vector con el maximo de pedidos posibles, que son 100 */

typedef TipoUbicacion TipoUbicacionesTotal[21];                        /* Tipo vector con el maximo de ubicaciones posibles, que son 20 */

typedef bool EstadoHuecoAlta[21];                                      /* Tipo vector bool para saber el estado de los huecos que forman el vector de ubicaciones */

typedef bool EstadoHuecoPedidos[101];                                  /* Tipo vector bool para saber el estado de los huecos que forman el vector de pedidos posibles */

typedef enum ErroresPrograma {ErrorPrograma};                          /* Tipo enumerado con los posibles errores de los programas */



/* TAD DE LA OPCION ALTA NUEVA DEL MENU PRINCIPAL */

/* Interfaz del Tipo Abstracto de Datos AltaNueva */
typedef struct MENU {
	TipoIdentificadorAux IdentificadorAux, FarmacoAux;
	TipoUbicacionesTotal TablaUbicaciones;            /* Variable para almacenar todas las ubicaciones totales */
	EstadoHuecoAlta HuecoOcupadoAlta;
	EstadoHuecoPedidos HuecoOcupadoPedidos;
	TipoPedido DatosPedido;                           /* Variable para un solo pedido */
	char LetraMenu, i, j, otropedido, otrofarmaco;
	ListadoPedidos ListaTotalPedidos;                 /* Variable para todos los pedidos */
	bool pedirmasfarmacos, HuecoEncontradoFarmaco, HuecoEncontradoPedido, HuecoEncontradoIdentificador, HuecoCalendario;
	TipoFecha FechaLista;
	ErroresPrograma error1, error2, error3, error4, error5, error6, error7, error8, error9, error10, error11, error12, error13, error14, error15;
	int IncrementoDias, MesCalendario, AnhoCalendario, a, y, m, diaZeller, d, diasMes, MaximoPacientes, MaximoFarmacos, DiasMesEnvio;

	/* Procedimiento convertir todos los huecos del vector que vamos a utilizar en Alta Nueva vacios en "falso" dentro de un bool */
	void IniciarHuecosAlta();

	/* Procedimiento convertir todos los huecos del vector que vamos a utilizar en Nuevo Farmaco vacios en "falso" dentro de un bool */
	void IniciarHuecosFarmaco();

	/* Procedimiento convertir todos los huecos del vector que vamos a utilizar en Nuevo Pedido vacios en "falso" dentro de un bool */
	void IniciarHuecosPedido();

	/* Menu Principal */
	void ImprimirMenu();

	/* Switch para seleccionar el menu */
	void ElegirLetra();

	/* Menu Alta Nueva */
	void AltaNueva();

	/* Menu UbicacionPacientes */
	void UbicacionPacientes();

	/* Menu Nuevo Pedido */
	void NuevoPedido();

	/* Opcion Nuevo Farmaco */
	void NuevoFarmaco();

	/* Opcion Listar Pedidos */
	void ListaPedidos();

	/* Funcion para calcular los dias que tiene cada mes */
	int CalcularDiasMes();

	/* Funcion para aplicar la ecuacion de Zeller */
	int Zeller();

	/* Opcion Calendario mensual de pedidos */
	void CalendarioMes();
};


/* Implementacion del Tipo Abstracto de Datos AltaNueva */

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

void MENU::ImprimirMenu() {
	printf("\n\n============================================================\n");
	printf("FarmaDron: Distribucion de Farmacos con Dron\n");
	printf("     Alta nuevo paciente                 (Pulsar A)\n");
	printf("     Ubicar pacientes                    (Pulsar U)\n");
	printf("     Nuevo pedido                        (Pulsar N)\n");
	printf("     Lista diaria de pedidos             (Pulsar L)\n");
	printf("     Calendario mensual de pedidos       (Pulsar C)\n");
	printf("     Salir                               (Pulsar S)\n");
	printf("Teclear una opcion valida (A|U|N|L|C|S)");
	scanf("%s", &LetraMenu);
	printf("============================================================\n\n");
}

void MENU::ElegirLetra() {
	switch (LetraMenu) {
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
		case 'C':
		case 'c':
		CalendarioMes();
		break;
		case 'S':
		case 's':
		printf("\n\n                   A    D    I    O    S\n");
		break;
		default:
		printf("\n\nCaracter invalido para la opcion de Elegir letra del menuL\n");
	}
}

void MENU::AltaNueva () {
	TipoUbicacion FilaUbicaciones;                          /* Variable local para cada fila de la lista de ubicaciones */
	int w = 0;                                              /* Variable local para comprobar longitud de Identificador */
	bool HuecoEncontradoAlta;                               /* Variable para saber si existe un hueco libre en el vector de ubicaciones */
	HuecoEncontradoAlta = false;

	for (int k=0; k<=20; k++) {                             /* Bucle para convertir en nulo todos los huecos del vector de Identificador */
	FilaUbicaciones.Identificador[k] = '\0';
	}
	for (int k=0; k<=20; k++) {                             /* Bucle para convertir en nulo todos los huecos del vector de Identificador auxiliar */
	IdentificadorAux[k] = '\0';
	}

	printf("\nAlta nuevo paciente\n\n");
	printf("      Identificador (Entre 1 y 20 caracteres)? ");
	try {
		fflush(stdin);
		gets(IdentificadorAux);                                                  /* En vez de scanf para poder meter espacios en Identificador */
		IdentificadorAux[strcspn(IdentificadorAux, "\r\n")] = 0;                 /* Para eliminar el salto de linea del final de Identificador */
		for (int k=0; k<=20; k++) {
			if (IdentificadorAux[k] != '\0') {
				if (!isalpha(IdentificadorAux[k]) && IdentificadorAux[k] != ' ' && IdentificadorAux[k] != '\0') {
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
			for (int k=1; k<=20 && (HuecoEncontradoAlta==false); k++) {
				if(HuecoOcupadoAlta[k] == false) {
				  	HuecoEncontradoAlta = true;
					FilaUbicaciones.Referencia = k;
					TablaUbicaciones[k] = FilaUbicaciones;                   /* Aqui se meten los datos introducidos en FilaUbicaciones en el vector TablaUbicaciones */
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
	printf("Otro paciente (S/N)? ");
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
  printf("\nLista de pacientes y su ubicacion:\n");
  printf("Ref.  ");
  printf("Identificador           ");
  printf("Distancia      ");
  printf("Angulo         \n");
  for(int i=1; i<=20; i++){
    if(HuecoOcupadoAlta[i] == true){
    	printf("%-6d%-24s%-15d%-15d\n", TablaUbicaciones[i].Referencia,TablaUbicaciones[i].Identificador, TablaUbicaciones[i].Distancia, TablaUbicaciones[i].Angulo);
    }
  }
}

void MENU::NuevoPedido() {
	DatosPedido.PesoTotalEnvio = 0;

	IniciarHuecosFarmaco();

	for (int indice=0; indice<=5; indice++) {                                           /* Bucle para convertir en nulo todos los huecos del vector Farmaco */
		for (int k=0; k<=20; k++) {
			DatosPedido.DatosFarmaco[indice].Farmaco[k] = '\0';
		}
	}

	printf("\n\nNuevo Pedido:\n");
	printf("Ref. Paciente (entre 1 y 20? ");
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
	printf("Numero de envios? ");
	scanf("%d", &DatosPedido.NumeroEnvios);
	if (DatosPedido.NumeroEnvios == 1) {
		printf("Dia del envio? ");
		try {
			scanf("%d", &DatosPedido.Fecha.Dia);
			printf("Mes del envio? ");
			scanf("%d", &DatosPedido.Fecha.Mes);
			printf("Año del envio? ");
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
		printf("Numero de dias entre cada envio (Entre 1 y 15 dias)? ");
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
		printf("Dia del primer envio? ");
		try {
			scanf("%d", &DatosPedido.Fecha.Dia);
			printf("Mes del primer envio? ");
			scanf("%d", &DatosPedido.Fecha.Mes);
			printf("Año del primer envio? ");
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
		printf("Nombre farmaco (Entre 1 y 20 caracteres)? ");
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
		printf("Peso farmaco (Menor de 3000 gramos)? ");
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
		printf("Unidades de farmaco? ");
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
		printf("Otro farmaco (S/N)? ");
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
					ListaTotalPedidos[k] = DatosPedido;                     /* Aqui guardamos los datos de DatosPedido en el vector ListaTotalPedidos */
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
									ListaTotalPedidos[k+indice] = DatosPedido;        /* Aqui guardamos los nuevos datos de dia, mes y año de DatosPedido en el vector ListaTotalPedidos */
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
										ListaTotalPedidos[k+indice] = DatosPedido;         /* Aqui guardamos los nuevos datos de dia, mes y año de DatosPedido en el vector ListaTotalPedidos */
										HuecoOcupadoPedidos[k+indice] = true;
									}
									else if ((DatosPedido.Fecha.Mes+1) >12) {
										DatosPedido.Fecha.Mes = (DatosPedido.Fecha.Mes +1) % 12;
										DatosPedido.Fecha.Anho = DatosPedido.Fecha.Anho+1;
										ListaTotalPedidos[k+indice] = DatosPedido;         /* Aqui guardamos los nuevos datos de dia, mes y año de DatosPedido en el vector ListaTotalPedidos */
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
			printf("Otro pedido (S/N)? ");
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
				printf("Nombre farmaco (Entre 1 y 20 caracteres)? ");
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
				printf("Peso farmaco (Menor de 3000 gramos)? ");
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
				printf("Unidades de farmaco? ");
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
				printf("Otro farmaco (S/N)? ");
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
							ListaTotalPedidos[k] = DatosPedido;              /* Aqui guardamos los nuevos datos de DatosPedido en el vector ListaTotalPedidos */
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
											ListaTotalPedidos[k+indice] = DatosPedido;             /* Aqui guardamos los nuevos datos de dia, mes y año de DatosPedido en el vector ListaTotalPedidos */
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
												ListaTotalPedidos[k+indice] = DatosPedido;         /* Aqui guardamos los nuevos datos de dia, mes y año de DatosPedido en el vector ListaTotalPedidos */
												HuecoOcupadoPedidos[k+indice] = true;
											}
											else if ((DatosPedido.Fecha.Mes+1) >12) {
												DatosPedido.Fecha.Mes = (DatosPedido.Fecha.Mes +1) % 12;
												DatosPedido.Fecha.Anho = DatosPedido.Fecha.Anho+1;
												ListaTotalPedidos[k+indice] = DatosPedido;         /* Aqui guardamos los nuevos datos de dia, mes y año de DatosPedido en el vector ListaTotalPedidos */
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
					printf("Otro pedido (S/N)? ");
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
	printf("\n\nLista diaria de pedidos\n");
	printf("Dia? ");
	scanf("%d", &FechaLista.Dia);
	printf("Mes? ");
	scanf("%d", &FechaLista.Mes);
	printf("Año? ");
	scanf("%d", &FechaLista.Anho);
	for(int k=1; k<=100; k++) {
		if(FechaLista.Dia == ListaTotalPedidos[k].Fecha.Dia && FechaLista.Mes == ListaTotalPedidos[k].Fecha.Mes && FechaLista.Anho == ListaTotalPedidos[k].Fecha.Anho) {
			printf("\n\n      Pedido %d", k);
			for(int i=1; i<=20; i++) {
				if(ListaTotalPedidos[k].RefPedido == TablaUbicaciones[i].Referencia) {
					printf("\nUbicacion pedido ==> Distancia: %d y Angulo: %d", TablaUbicaciones[i].Distancia, TablaUbicaciones[i].Angulo);
					for(int j=1; j<=5; j++) {
						if(ListaTotalPedidos[k].HuecoOcupadoFarmacos[j] == true) {
							printf("\n%-2dUnidades        ", ListaTotalPedidos[k].DatosFarmaco[j].NumeroFarmacos);
							printf("%-20s", ListaTotalPedidos[k].DatosFarmaco[j].Farmaco);
							printf("Peso: %4d gramos\n", ListaTotalPedidos[k].DatosFarmaco[j].PesoTotalFarmacos);
						}
					}
					printf("                  Peso total del envio");
					printf("%10d gramos\n\n", ListaTotalPedidos[k].PesoTotalEnvio);
				}
			}
		}		
	}
}

int MENU::CalcularDiasMes() {
	switch(MesCalendario) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
		return 31;
		break;
		case 2:
		if (AnhoCalendario % 4 == 0 && AnhoCalendario % 100 != 0 || AnhoCalendario % 400 == 0) {
			return 29;
		}
		else {
			return 28;
		}	
		break;
		default:
		return 30;
	}
}

int MENU::Zeller() {
	diaZeller = 1;
	a = (14 - MesCalendario)/12;
	y = AnhoCalendario - a;
	m = MesCalendario + 12 * a - 2;
	d = (diaZeller + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7; 
  	return d;
}

void MENU::CalendarioMes() {
	const int OrigenAnho=1601;

	printf("Calendario mensual de pedidos:\n");
	printf("Seleccion Mes? ");
	scanf("%d", &MesCalendario);
	printf("Seleccion Año? ");
	scanf("%d", &AnhoCalendario);
	printf("\n");
	printf("Pedidos del mes o vuelos del Dron\n\n");

	diasMes = CalcularDiasMes();
	IncrementoDias = Zeller();

	switch (MesCalendario) {
		case 1:
		printf("ENERO                        ");
		break;
		case 2:
		printf("FEBRERO                      ");
		break;
		case 3:
		printf("MARZO                        ");
		break;
		case 4:
		printf("ABRIL                        ");
		break;
		case 5:
		printf("MAYO                         ");
		break;
		case 6:
		printf("JUNIO                        ");
		break;
		case 7:
		printf("JULIO                        ");
		break;
		case 8:
		printf("AGOSTO                       ");
		break;
		case 9:
		printf("SEPTIEMBRE                   ");
		break;
		case 10:
		printf("OCTUBRE                      ");
		break;
		case 11:
		printf("NOVIEMBRE                    ");
		break;
		case 12:
		printf("DICIEMBRE                    ");
		break;
	}
	printf("%d", AnhoCalendario);
	printf("\n=================================\n");
	printf("LU   MA   MI   JU   VI | SA   DO \n");
	printf("=================================\n");

	for(int k=1; k<IncrementoDias; k++) {
		printf("     ");
	}
	for(int dia=1; dia <= diasMes; dia++) {
		HuecoCalendario = false;
		for(int k=1; k<=100; k++) {
			if(dia == ListaTotalPedidos[k].Fecha.Dia &&	MesCalendario == ListaTotalPedidos[k].Fecha.Mes && AnhoCalendario == ListaTotalPedidos[k].Fecha.Anho) {
				HuecoCalendario = true;
			}	
		}
		if (HuecoCalendario == true) {
			printf("%-5d", dia);
		}	
		else {
			printf("--   ");
		}
		IncrementoDias++;
		if((IncrementoDias-1) % 7 == 0) {
			printf("\n");
		}	
	}	
}


/* PROGRAMA PRINCIPAL */
int main () {
	MENU menucompleto;
	menucompleto.MaximoPacientes = 0;
	menucompleto.MaximoFarmacos = 1;

	menucompleto.IniciarHuecosAlta();
	menucompleto.IniciarHuecosFarmaco();
	menucompleto.IniciarHuecosPedido();
	printf("\n\nF      A      R      M      A      D       R       O       N\n");
	while(menucompleto.LetraMenu != 'S' || menucompleto.LetraMenu != 's') {
		menucompleto.ImprimirMenu();
		menucompleto.ElegirLetra();
		if(menucompleto.LetraMenu == 'S' || menucompleto.LetraMenu == 's') {
		  return 0;
	  	}
	}
}

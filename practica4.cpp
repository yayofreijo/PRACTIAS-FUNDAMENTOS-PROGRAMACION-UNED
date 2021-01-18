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
#include <ctype.h>

typedef char TipoIdentificador[21];

typedef struct TipoUbicacion {
	int Referencia;
	TipoIdentificador Identificador;
	int Distancia;
	int Angulo;
};

typedef struct TipoFecha {
	int Dia;
	int Mes;
	int Anho;
};

typedef struct TipoFarmaco {
	TipoIdentificador Farmaco;
	int PesoFarmaco;
	int NumeroFarmacos;
	int PesoTotalFarmacos;

};

typedef TipoFarmaco ListaFarmacos[6];

typedef bool EstadoHuecoFarmacos[6];

typedef struct TipoPedido {
	int RefPedido;
	int NumeroEnvios;
	TipoFecha Fecha;
	ListaFarmacos DatosFarmaco;
	EstadoHuecoFarmacos HuecoOcupadoFarmacos;
};

typedef TipoPedido ListadoPedidos[101];

typedef TipoUbicacion TipoUbicacionesTotal[21];

typedef bool EstadoHuecoAlta[21];

typedef bool EstadoHuecoPedidos[11];

typedef enum TipoDia {                                                      /* Nuevo tipo de datos con los dias de la semana */
	Lunes, Martes, Miercoles, Jueves, Viernes, Sabado, Domingo
};

/* TAD DE LA OPCION ALTA NUEVA DEL MENU PRINCIPAL */

/* Interfaz del tipo abstracto AltaNueva */
typedef struct MENU {
	TipoUbicacionesTotal TablaUbicaciones;
	TipoDia diasemana;
	EstadoHuecoAlta HuecoOcupadoAlta;
	EstadoHuecoPedidos HuecoOcupadoPedidos;
	TipoPedido DatosPedido; /* Variable para un solo pedido */
	char LetraMenu, i, j, otropedido, otrofarmaco;
	ListadoPedidos ListaTotalPedidos; /* Variable para todos los pedidos */
	bool pedirmasfarmacos, HuecoEncontradoFarmaco, HuecoEncontradoPedido, HuecoCalendario;
	TipoFecha FechaLista;
	int PesoTotalEnvio, IncrementoDias, MesCalendario, AnhoCalendario, a, y, m, diaZeller, d, diasMes;

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
	void ListaPacientes();

	/* Funcion para calcular los dias que tiene cada mes */
	int CalcularDiasMes();

	/* Funcion para aplicar la ecuacion de Zeller */
	int Zeller();

	/* Opcion Calendario mensual de pedidos */
	void CalendarioMes();
};

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
		ListaPacientes();
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
		printf("\nCARACTER INVALIDO\n");
	}
}

/*
void AltaNueva (TipoIdentificador Identificador, TipoDistancia Distancia, TipoAngulo Angulo, char &LetraMenu) {  */
void MENU::AltaNueva () {
	TipoUbicacion FilaUbicaciones;
	bool HuecoEncontradoAlta;
	HuecoEncontradoAlta = false;

	printf("\n\nAlta nuevo paciente\n\n");
	printf("      Identificador (Entre 1 y 20 caracteres)? ");
	scanf("%s", &FilaUbicaciones.Identificador);
	printf("      Distancia(hasta 10000 metros a plena carga)? ");
	scanf("%d", &FilaUbicaciones.Distancia);
	printf("      Angulo (entre 0 y 2000 pi/1000 radianes)? ");
	scanf("%d", &FilaUbicaciones.Angulo);
	printf("\n");
	printf("Datos correctos (S/N)? ");
	scanf("%s", &i);
	if(i=='s' || i=='S') {
		for (int k=1; k<=20 && (HuecoEncontradoAlta==false); k++) {
			if(HuecoOcupadoAlta[k] == false) {
			  	HuecoEncontradoAlta = true;
				FilaUbicaciones.Referencia = k;
				TablaUbicaciones[k] = FilaUbicaciones;
				HuecoOcupadoAlta[k] = true;
			}
		}
	}
	else if(i=='N' || i=='n') {
		AltaNueva ();
	}
	else {
		printf("\n\nCARACTER INVALIDO\n\n");
		AltaNueva ();
	}
	printf("Otro paciente (S/N)? ");
	scanf("%s", &j);
	if(j=='S' || j=='s') {
		AltaNueva();
	}
	else if (j=='N' || j=='n') {
		return;
	}
	else {
		printf("\n\nCARACTER INVALIDO\n\n");
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
	IniciarHuecosFarmaco();
	printf("\n\nNuevo Pedido:\n");
	printf("Ref. Paciente (entre 1 y 20? ");
	scanf("%d", &DatosPedido.RefPedido);
	printf("Numero de envios? ");
	scanf("%d", &DatosPedido.NumeroEnvios);
	printf("Dia del envio? ");
	scanf("%d", &DatosPedido.Fecha.Dia);
	printf("Mes del envio? ");
	scanf("%d", &DatosPedido.Fecha.Mes);
	printf("Año del envio? ");
	scanf("%d", &DatosPedido.Fecha.Anho);
	pedirmasfarmacos = false;
	NuevoFarmaco();
}

void MENU::NuevoFarmaco() {
	HuecoEncontradoFarmaco = false;
	HuecoEncontradoPedido = false;

	if (pedirmasfarmacos == false) {
		printf("Nombre farmaco (Entre 1 y 20 caracteres)? ");
		scanf("%s", &DatosPedido.DatosFarmaco[1].Farmaco);
		printf("Peso farmaco (Menor de 3000 gramos)? ");
		scanf("%d", &DatosPedido.DatosFarmaco[1].PesoFarmaco);
		printf("Unidades de farmaco? ");
		scanf("%d", &DatosPedido.DatosFarmaco[1].NumeroFarmacos);
		DatosPedido.DatosFarmaco[1].PesoTotalFarmacos = DatosPedido.DatosFarmaco[1].PesoFarmaco * DatosPedido.DatosFarmaco[1].NumeroFarmacos;
		DatosPedido.HuecoOcupadoFarmacos[1] = true;
		printf("Otro farmaco (S/N)? ");
		scanf("%s", &otrofarmaco);
		if (otrofarmaco == 'S' || otrofarmaco == 's') {
			pedirmasfarmacos = true;
			NuevoFarmaco();
		}
		else if(otrofarmaco == 'N' || otrofarmaco == 'n') {
			for(int k=1; k<=100 && HuecoEncontradoPedido==false; k++) {
				if(HuecoOcupadoPedidos[k] == false) {
					HuecoEncontradoPedido = true;
					ListaTotalPedidos[k] = DatosPedido;
					HuecoOcupadoPedidos[k] = true;
				}
			}
			printf("Otro pedido (S/N)? ");
			scanf("%s", &otropedido);
			if(otropedido == 'S' || otropedido == 's') {
				NuevoPedido();
			}
			else if(otropedido == 'N' || otropedido == 'n') {
				return;
				return;
			}
			else {
				printf ("CARACTER INVALIDO");
				return;
			}
		}
		else {
			printf("CARACTER NO VALIDO");
			return;
		}
	}
	else if	(pedirmasfarmacos == true) {
		for (int k=2; k<=5 && (HuecoEncontradoFarmaco==false); k++) {
			if(DatosPedido.HuecoOcupadoFarmacos[k] == false) {
				HuecoEncontradoFarmaco = true;
				printf("Nombre farmaco (Entre 1 y 20 caracteres)? ");
				scanf("%s", &DatosPedido.DatosFarmaco[k].Farmaco);
				printf("Peso farmaco (Menor de 3000 gramos)? ");
				scanf("%d", &DatosPedido.DatosFarmaco[k].PesoFarmaco);
				printf("Unidades de farmaco? ");
				scanf("%d", &DatosPedido.DatosFarmaco[k].NumeroFarmacos);
				DatosPedido.DatosFarmaco[k].PesoTotalFarmacos = DatosPedido.DatosFarmaco[k].PesoFarmaco * DatosPedido.DatosFarmaco[k].NumeroFarmacos;
				DatosPedido.HuecoOcupadoFarmacos[k] = true;
				printf("Otro farmaco (S/N)? ");
				scanf("%s", &otrofarmaco);
				if (otrofarmaco == 'S' || otrofarmaco == 's') {
					pedirmasfarmacos = true;
					NuevoFarmaco();
				}
				else if(otrofarmaco == 'N' || otrofarmaco == 'n') {
					for(int k=1; k<=100 && HuecoEncontradoPedido==false; k++) {
						if(HuecoOcupadoPedidos[k] == false) {
							HuecoEncontradoPedido = true;
							ListaTotalPedidos[k] = DatosPedido;
							HuecoOcupadoPedidos[k] = true;
						}
					}
					printf("Otro pedido (S/N)? ");
					scanf("%s", &otropedido);
					if(otropedido == 'S' || otropedido == 's') {
						NuevoPedido();
					}
					else if(otropedido == 'N' || otropedido == 'n') {
					return;
					}
					else {
						printf ("CARACTER INVALIDO");
						return;
					}
				}
				else {
					printf("CARACTER INVALIDO");
				}
			}
		}
	}
}

void MENU::ListaPacientes() {
	PesoTotalEnvio = 0;
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
							PesoTotalEnvio = ListaTotalPedidos[k].DatosFarmaco[j].PesoTotalFarmacos + PesoTotalEnvio;
						}
					}
					printf("                  Peso total del envio");
					printf("%10d gramos\n\n", PesoTotalEnvio);
					PesoTotalEnvio = 0;
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
		for(int k=1; k<=100; k++) {
			if(dia == ListaTotalPedidos[k].Fecha.Dia &&	MesCalendario == ListaTotalPedidos[k].Fecha.Mes && AnhoCalendario == ListaTotalPedidos[k].Fecha.Anho) {
				printf("%-5d", dia);
				HuecoCalendario = true
			}
			else {
				HuecoCalendario = false
		}
		if(HuecoCalendario = false) {	
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

	menucompleto.IniciarHuecosAlta();
	menucompleto.IniciarHuecosFarmaco();
	menucompleto.IniciarHuecosPedido();
	while(menucompleto.LetraMenu != 'S' || menucompleto.LetraMenu != 's') {
		menucompleto.ImprimirMenu();
		menucompleto.ElegirLetra();
		if(menucompleto.LetraMenu == 'S' || menucompleto.LetraMenu == 's') {
		  return 0;
	  	}
	}
}

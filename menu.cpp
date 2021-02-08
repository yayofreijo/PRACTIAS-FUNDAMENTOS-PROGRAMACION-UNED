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
#include <math.h>
#include "menu.h"

void MENU::IniciarHuecosAlta() {
	for(int k=1; k<=20; k++) {
		Almacen.HuecoOcupadoAlta[k] = false;
	}	
}

void MENU::IniciarHuecosFarmaco() {
	for(int k=1; k<=5; k++) {
		DatosPedido.HuecoOcupadoFarmacos[k] = false;
	}
}

void MENU::IniciarHuecosPedido() {
	for(int k=1; k<=100; k++) {
		Almacen.HuecoOcupadoPedidos[k] = false;
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
		IniciarGestion();
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
		ProgramarRutas();
		break;
		case 'S':
		case 's':
		printf("\n\n                   A    D    I    O    S\n");
		break;
		default:
		printf("\n\nCaracter invalido para la opcion de Elegir letra del Menu\n");
		return;
	}
}


void MENU::IniciarGestion() {

	/* ALMACENES */
	/* Guardado de datos del primer almacen */
	HuecoOcupadoAlmacen[1] = true;
	TotalAlmacenes[1].IdentificadorAlmacen = 1;
	strcpy (TotalAlmacenes[1].DireccionAlmacen, "Rua da Saude");
	strcpy (TotalAlmacenes[1].MunicipioAlmacen, "Lugo");
	strcpy (TotalAlmacenes[1].ProvinciaAlmacen, "Lugo");
	strcpy (TotalAlmacenes[1].DescripcionAlmacen, "Abella");
	TotalAlmacenes[1].MaximoPacientes = 0;
	MaximoAlmacenes = 1;

	/* Guardado de datos del segundo almacen */
	HuecoOcupadoAlmacen[2] = true;
	TotalAlmacenes[2].IdentificadorAlmacen = 2;
	strcpy (TotalAlmacenes[2].DireccionAlmacen, "Rua da Pedra");
	strcpy (TotalAlmacenes[2].MunicipioAlmacen, "Outeiro de Rei");
	strcpy (TotalAlmacenes[2].ProvinciaAlmacen, "Lugo");
	strcpy (TotalAlmacenes[2].DescripcionAlmacen, "Outeiro");
	TotalAlmacenes[2].MaximoPacientes = 0;
	MaximoAlmacenes = 2;

	/* Guardado de datos del segundo almacen */
	HuecoOcupadoAlmacen[3] = true;
	TotalAlmacenes[3].IdentificadorAlmacen = 3;
	strcpy (TotalAlmacenes[3].DireccionAlmacen, "Avenida de Madrid");
	strcpy (TotalAlmacenes[3].MunicipioAlmacen, "Lugo");
	strcpy (TotalAlmacenes[3].ProvinciaAlmacen, "Lugo");
	strcpy (TotalAlmacenes[3].DescripcionAlmacen, "Aguas Ferreas");
	TotalAlmacenes[3].MaximoPacientes = 0;
	MaximoAlmacenes = 3;

	/* Guardado de datos del segundo almacen */
	HuecoOcupadoAlmacen[4] = true;
	TotalAlmacenes[4].IdentificadorAlmacen = 4;
	strcpy (TotalAlmacenes[4].DireccionAlmacen, "Avenida de Rihanna");
	strcpy (TotalAlmacenes[4].MunicipioAlmacen, "Lugo");
	strcpy (TotalAlmacenes[4].ProvinciaAlmacen, "Lugo");
	strcpy (TotalAlmacenes[4].DescripcionAlmacen, "As Gandaras");
	TotalAlmacenes[4].MaximoPacientes = 0;
	MaximoAlmacenes = 4;

	/* Guardado de datos del segundo almacen */
	HuecoOcupadoAlmacen[5] = true;
	TotalAlmacenes[5].IdentificadorAlmacen = 5;
	strcpy (TotalAlmacenes[5].DireccionAlmacen, "Praza Maior");
	strcpy (TotalAlmacenes[5].MunicipioAlmacen, "Guntin");
	strcpy (TotalAlmacenes[5].ProvinciaAlmacen, "Lugo");
	strcpy (TotalAlmacenes[5].DescripcionAlmacen, "Guntin");
	TotalAlmacenes[5].MaximoPacientes = 0;
	MaximoAlmacenes = 5;


	/* PACIENTES */
	/*Guardado de datos del primer paciente */
	TotalAlmacenes[1].HuecoOcupadoAlta[1] = true;
	TotalAlmacenes[1].UbicacionesAlmacen[1].AlmacenPaciente = 1;
	TotalAlmacenes[1].UbicacionesAlmacen[1].Referencia = 1;
	strcpy (TotalAlmacenes[1].UbicacionesAlmacen[1].Identificador, "Manuel Lagos");
	TotalAlmacenes[1].UbicacionesAlmacen[1].Distancia = 1230;
	TotalAlmacenes[1].UbicacionesAlmacen[1].Angulo = 345;
	TotalAlmacenes[1].MaximoPacientes = 1;

	/*Guardado de datos del segundo paciente */
	TotalAlmacenes[1].HuecoOcupadoAlta[2] = true;
	TotalAlmacenes[1].UbicacionesAlmacen[2].AlmacenPaciente = 1;
	TotalAlmacenes[1].UbicacionesAlmacen[2].Referencia = 2;
	strcpy (TotalAlmacenes[1].UbicacionesAlmacen[2].Identificador, "Alvaro Freijo");
	TotalAlmacenes[1].UbicacionesAlmacen[2].Distancia = 235;
	TotalAlmacenes[1].UbicacionesAlmacen[2].Angulo = 30;
	TotalAlmacenes[1].MaximoPacientes = 2;

	/*Guardado de datos del tercer paciente */
	TotalAlmacenes[1].HuecoOcupadoAlta[3] = true;
	TotalAlmacenes[1].UbicacionesAlmacen[3].AlmacenPaciente = 1;
	TotalAlmacenes[1].UbicacionesAlmacen[3].Referencia = 3;
	strcpy (TotalAlmacenes[1].UbicacionesAlmacen[3].Identificador, "Manolo Perez");
	TotalAlmacenes[1].UbicacionesAlmacen[3].Distancia = 9045;
	TotalAlmacenes[1].UbicacionesAlmacen[3].Angulo = 121;
	TotalAlmacenes[1].MaximoPacientes = 3;

	/*Guardado de datos del cuarto paciente */
	TotalAlmacenes[2].HuecoOcupadoAlta[1] = true;
	TotalAlmacenes[2].UbicacionesAlmacen[1].AlmacenPaciente = 2;
	TotalAlmacenes[2].UbicacionesAlmacen[1].Referencia = 1;
	strcpy (TotalAlmacenes[2].UbicacionesAlmacen[1].Identificador, "Delfina Jacinta");
	TotalAlmacenes[2].UbicacionesAlmacen[1].Distancia = 1050;
	TotalAlmacenes[2].UbicacionesAlmacen[1].Angulo = 1200;
	TotalAlmacenes[2].MaximoPacientes = 1;

	/*Guardado de datos del quinto paciente */
	TotalAlmacenes[3].HuecoOcupadoAlta[1] = true;
	TotalAlmacenes[3].UbicacionesAlmacen[1].AlmacenPaciente = 3;
	TotalAlmacenes[3].UbicacionesAlmacen[1].Referencia = 1;
	strcpy (TotalAlmacenes[3].UbicacionesAlmacen[1].Identificador, "Rigodon Lopez");
	TotalAlmacenes[3].UbicacionesAlmacen[1].Distancia = 7650;
	TotalAlmacenes[3].UbicacionesAlmacen[1].Angulo = 34;
	TotalAlmacenes[3].MaximoPacientes = 1;

	/*Guardado de datos del sexto paciente */
	TotalAlmacenes[3].HuecoOcupadoAlta[2] = true;
	TotalAlmacenes[3].UbicacionesAlmacen[2].AlmacenPaciente = 3;
	TotalAlmacenes[3].UbicacionesAlmacen[2].Referencia = 2;
	strcpy (TotalAlmacenes[3].UbicacionesAlmacen[2].Identificador, "Pepe Perez");
	TotalAlmacenes[3].UbicacionesAlmacen[2].Distancia = 10;
	TotalAlmacenes[3].UbicacionesAlmacen[2].Angulo = 1950;
	TotalAlmacenes[3].MaximoPacientes = 2;

	/*Guardado de datos del septimo paciente */
	TotalAlmacenes[3].HuecoOcupadoAlta[3] = true;
	TotalAlmacenes[3].UbicacionesAlmacen[3].AlmacenPaciente = 3;
	TotalAlmacenes[3].UbicacionesAlmacen[3].Referencia = 3;
	strcpy (TotalAlmacenes[3].UbicacionesAlmacen[3].Identificador, "Ariana Grande");
	TotalAlmacenes[3].UbicacionesAlmacen[3].Distancia = 4500;
	TotalAlmacenes[3].UbicacionesAlmacen[3].Angulo = 890;
	TotalAlmacenes[3].MaximoPacientes = 3;

	/*Guardado de datos del octavo paciente */
	TotalAlmacenes[3].HuecoOcupadoAlta[4] = true;
	TotalAlmacenes[3].UbicacionesAlmacen[4].AlmacenPaciente = 3;
	TotalAlmacenes[3].UbicacionesAlmacen[4].Referencia = 4;
	strcpy (TotalAlmacenes[3].UbicacionesAlmacen[4].Identificador, "Jennifer Lopez");
	TotalAlmacenes[3].UbicacionesAlmacen[4].Distancia = 230;
	TotalAlmacenes[3].UbicacionesAlmacen[4].Angulo = 5;
	TotalAlmacenes[3].MaximoPacientes = 4;

	/*Guardado de datos del noveno paciente */
	TotalAlmacenes[3].HuecoOcupadoAlta[5] = true;
	TotalAlmacenes[3].UbicacionesAlmacen[5].AlmacenPaciente = 3;
	TotalAlmacenes[3].UbicacionesAlmacen[5].Referencia = 5;
	strcpy (TotalAlmacenes[3].UbicacionesAlmacen[5].Identificador, "Monica Racamonde");
	TotalAlmacenes[3].UbicacionesAlmacen[5].Distancia = 3492;
	TotalAlmacenes[3].UbicacionesAlmacen[5].Angulo = 1492;
	TotalAlmacenes[3].MaximoPacientes = 5;

	/*Guardado de datos del decimo paciente */
	TotalAlmacenes[4].HuecoOcupadoAlta[1] = true;
	TotalAlmacenes[4].UbicacionesAlmacen[1].AlmacenPaciente = 4;
	TotalAlmacenes[4].UbicacionesAlmacen[1].Referencia = 1;
	strcpy (TotalAlmacenes[4].UbicacionesAlmacen[1].Identificador, "Yolanda Diaz");
	TotalAlmacenes[4].UbicacionesAlmacen[1].Distancia = 5060;
	TotalAlmacenes[4].UbicacionesAlmacen[1].Angulo = 300;
	TotalAlmacenes[4].MaximoPacientes = 1;


	/* PEDIDOS */
	/* Guardado de datos del primer pedido */
	TotalAlmacenes[1].ListaPedidosAlmacen[1].AlmacenPedido = 1;
	TotalAlmacenes[1].ListaPedidosAlmacen[1].RefPedido = 1;
	TotalAlmacenes[1].ListaPedidosAlmacen[1].NumeroEnvios = 1;
	TotalAlmacenes[1].ListaPedidosAlmacen[1].Fecha.Dia = 1;
	TotalAlmacenes[1].ListaPedidosAlmacen[1].Fecha.Mes = 1;
	TotalAlmacenes[1].ListaPedidosAlmacen[1].Fecha.Anho = 2021;
	strcpy (TotalAlmacenes[1].ListaPedidosAlmacen[1].DatosFarmaco[1].Farmaco, "Paracetamol");
	TotalAlmacenes[1].ListaPedidosAlmacen[1].HuecoOcupadoFarmacos[1] = true;
	TotalAlmacenes[1].ListaPedidosAlmacen[1].DatosFarmaco[1].PesoFarmaco = 100;
	TotalAlmacenes[1].ListaPedidosAlmacen[1].DatosFarmaco[1].NumeroFarmacos = 5;
	TotalAlmacenes[1].ListaPedidosAlmacen[1].DatosFarmaco[1].PesoTotalFarmacos = 500;
	strcpy (TotalAlmacenes[1].ListaPedidosAlmacen[1].DatosFarmaco[2].Farmaco, "Pantoprazol");
	TotalAlmacenes[1].ListaPedidosAlmacen[1].HuecoOcupadoFarmacos[2] = true;
	TotalAlmacenes[1].ListaPedidosAlmacen[1].DatosFarmaco[2].PesoFarmaco = 50;
	TotalAlmacenes[1].ListaPedidosAlmacen[1].DatosFarmaco[2].NumeroFarmacos = 5;
	TotalAlmacenes[1].ListaPedidosAlmacen[1].DatosFarmaco[2].PesoTotalFarmacos = 250;
	TotalAlmacenes[1].ListaPedidosAlmacen[1].PesoTotalEnvio = 750;
	TotalAlmacenes[1].HuecoOcupadoPedidos[1] = true;

	/* Guardado de datos del segundo pedido */
	TotalAlmacenes[1].ListaPedidosAlmacen[2].AlmacenPedido = 1;
	TotalAlmacenes[1].ListaPedidosAlmacen[2].RefPedido = 1;
	TotalAlmacenes[1].ListaPedidosAlmacen[2].NumeroEnvios = 1;
	TotalAlmacenes[1].ListaPedidosAlmacen[2].Fecha.Dia = 8;
	TotalAlmacenes[1].ListaPedidosAlmacen[2].Fecha.Mes = 1;
	TotalAlmacenes[1].ListaPedidosAlmacen[2].Fecha.Anho = 2021;
	strcpy (TotalAlmacenes[1].ListaPedidosAlmacen[2].DatosFarmaco[1].Farmaco, "Paracetamol");
	TotalAlmacenes[1].ListaPedidosAlmacen[2].HuecoOcupadoFarmacos[1] = true;
	TotalAlmacenes[1].ListaPedidosAlmacen[2].DatosFarmaco[1].PesoFarmaco = 100;
	TotalAlmacenes[1].ListaPedidosAlmacen[2].DatosFarmaco[1].NumeroFarmacos = 6;
	TotalAlmacenes[1].ListaPedidosAlmacen[2].DatosFarmaco[1].PesoTotalFarmacos = 600;
	strcpy (TotalAlmacenes[1].ListaPedidosAlmacen[2].DatosFarmaco[2].Farmaco, "Pantoprazol");
	TotalAlmacenes[1].ListaPedidosAlmacen[2].HuecoOcupadoFarmacos[2] = true;
	TotalAlmacenes[1].ListaPedidosAlmacen[2].DatosFarmaco[2].PesoFarmaco = 50;
	TotalAlmacenes[1].ListaPedidosAlmacen[2].DatosFarmaco[2].NumeroFarmacos = 10;
	TotalAlmacenes[1].ListaPedidosAlmacen[2].DatosFarmaco[2].PesoTotalFarmacos = 500;
	strcpy (TotalAlmacenes[1].ListaPedidosAlmacen[2].DatosFarmaco[3].Farmaco, "Dexametasona");
	TotalAlmacenes[1].ListaPedidosAlmacen[2].HuecoOcupadoFarmacos[3] = true;
	TotalAlmacenes[1].ListaPedidosAlmacen[2].DatosFarmaco[3].PesoFarmaco = 50;
	TotalAlmacenes[1].ListaPedidosAlmacen[2].DatosFarmaco[3].NumeroFarmacos = 5;
	TotalAlmacenes[1].ListaPedidosAlmacen[2].DatosFarmaco[3].PesoTotalFarmacos = 250;
	TotalAlmacenes[1].ListaPedidosAlmacen[2].PesoTotalEnvio = 1350;
	TotalAlmacenes[1].HuecoOcupadoPedidos[2] = true;

	/* Guardado de datos del tercer pedido */
	TotalAlmacenes[1].ListaPedidosAlmacen[3].AlmacenPedido = 1;
	TotalAlmacenes[1].ListaPedidosAlmacen[3].RefPedido = 1;
	TotalAlmacenes[1].ListaPedidosAlmacen[3].NumeroEnvios = 1;
	TotalAlmacenes[1].ListaPedidosAlmacen[3].Fecha.Dia = 15;
	TotalAlmacenes[1].ListaPedidosAlmacen[3].Fecha.Mes = 1;
	TotalAlmacenes[1].ListaPedidosAlmacen[3].Fecha.Anho = 2021;
	strcpy (TotalAlmacenes[1].ListaPedidosAlmacen[3].DatosFarmaco[1].Farmaco, "Dexketoprofeno");
	TotalAlmacenes[1].ListaPedidosAlmacen[3].HuecoOcupadoFarmacos[1] = true;
	TotalAlmacenes[1].ListaPedidosAlmacen[3].DatosFarmaco[1].PesoFarmaco = 100;
	TotalAlmacenes[1].ListaPedidosAlmacen[3].DatosFarmaco[1].NumeroFarmacos = 10;
	TotalAlmacenes[1].ListaPedidosAlmacen[3].DatosFarmaco[1].PesoTotalFarmacos = 1000;
	strcpy (TotalAlmacenes[1].ListaPedidosAlmacen[3].DatosFarmaco[2].Farmaco, "Pantoprazol");
	TotalAlmacenes[1].ListaPedidosAlmacen[3].HuecoOcupadoFarmacos[2] = true;
	TotalAlmacenes[1].ListaPedidosAlmacen[3].DatosFarmaco[2].PesoFarmaco = 50;
	TotalAlmacenes[1].ListaPedidosAlmacen[3].DatosFarmaco[2].NumeroFarmacos = 5;
	TotalAlmacenes[1].ListaPedidosAlmacen[3].DatosFarmaco[2].PesoTotalFarmacos = 250;
	TotalAlmacenes[1].ListaPedidosAlmacen[3].PesoTotalEnvio = 1250;
	TotalAlmacenes[1].HuecoOcupadoPedidos[3] = true;

	/* Guardado de datos del cuarto pedido */
	TotalAlmacenes[1].ListaPedidosAlmacen[4].AlmacenPedido = 1;
	TotalAlmacenes[1].ListaPedidosAlmacen[4].RefPedido = 1;
	TotalAlmacenes[1].ListaPedidosAlmacen[4].NumeroEnvios = 1;
	TotalAlmacenes[1].ListaPedidosAlmacen[4].Fecha.Dia = 22;
	TotalAlmacenes[1].ListaPedidosAlmacen[4].Fecha.Mes = 1;
	TotalAlmacenes[1].ListaPedidosAlmacen[4].Fecha.Anho = 2021;
	strcpy (TotalAlmacenes[1].ListaPedidosAlmacen[4].DatosFarmaco[1].Farmaco, "Ibuprofeno");
	TotalAlmacenes[1].ListaPedidosAlmacen[4].HuecoOcupadoFarmacos[1] = true;
	TotalAlmacenes[1].ListaPedidosAlmacen[4].DatosFarmaco[1].PesoFarmaco = 20;
	TotalAlmacenes[1].ListaPedidosAlmacen[4].DatosFarmaco[1].NumeroFarmacos = 5;
	TotalAlmacenes[1].ListaPedidosAlmacen[4].DatosFarmaco[1].PesoTotalFarmacos = 100;
	TotalAlmacenes[1].ListaPedidosAlmacen[4].PesoTotalEnvio = 100;
	TotalAlmacenes[1].HuecoOcupadoPedidos[4] = true;

	/* Guardado de datos del quinto pedido */
	TotalAlmacenes[2].ListaPedidosAlmacen[1].AlmacenPedido = 2;
	TotalAlmacenes[2].ListaPedidosAlmacen[1].RefPedido = 1;
	TotalAlmacenes[2].ListaPedidosAlmacen[1].NumeroEnvios = 1;
	TotalAlmacenes[2].ListaPedidosAlmacen[1].Fecha.Dia = 1;
	TotalAlmacenes[2].ListaPedidosAlmacen[1].Fecha.Mes = 1;
	TotalAlmacenes[2].ListaPedidosAlmacen[1].Fecha.Anho = 2021;
	strcpy (TotalAlmacenes[2].ListaPedidosAlmacen[1].DatosFarmaco[1].Farmaco, "Metilprednisolona");
	TotalAlmacenes[2].ListaPedidosAlmacen[1].HuecoOcupadoFarmacos[1] = true;
	TotalAlmacenes[2].ListaPedidosAlmacen[1].DatosFarmaco[1].PesoFarmaco = 40;
	TotalAlmacenes[2].ListaPedidosAlmacen[1].DatosFarmaco[1].NumeroFarmacos = 10;
	TotalAlmacenes[2].ListaPedidosAlmacen[1].DatosFarmaco[1].PesoTotalFarmacos = 400;
	strcpy (TotalAlmacenes[2].ListaPedidosAlmacen[1].DatosFarmaco[2].Farmaco, "Omeprazol");
	TotalAlmacenes[2].ListaPedidosAlmacen[1].HuecoOcupadoFarmacos[2] = true;
	TotalAlmacenes[2].ListaPedidosAlmacen[1].DatosFarmaco[2].PesoFarmaco = 20;
	TotalAlmacenes[2].ListaPedidosAlmacen[1].DatosFarmaco[2].NumeroFarmacos = 20;
	TotalAlmacenes[2].ListaPedidosAlmacen[1].DatosFarmaco[2].PesoTotalFarmacos = 400;
	TotalAlmacenes[2].ListaPedidosAlmacen[1].PesoTotalEnvio = 800;
	TotalAlmacenes[2].HuecoOcupadoPedidos[1] = true;

	/* Guardado de datos del sexto pedido */
	TotalAlmacenes[3].ListaPedidosAlmacen[1].AlmacenPedido = 3;
	TotalAlmacenes[3].ListaPedidosAlmacen[1].RefPedido = 1;
	TotalAlmacenes[3].ListaPedidosAlmacen[1].NumeroEnvios = 1;
	TotalAlmacenes[3].ListaPedidosAlmacen[1].Fecha.Dia = 2;
	TotalAlmacenes[3].ListaPedidosAlmacen[1].Fecha.Mes = 1;
	TotalAlmacenes[3].ListaPedidosAlmacen[1].Fecha.Anho = 2021;
	strcpy (TotalAlmacenes[3].ListaPedidosAlmacen[1].DatosFarmaco[1].Farmaco, "Acido Clavulanico");
	TotalAlmacenes[3].ListaPedidosAlmacen[1].HuecoOcupadoFarmacos[1] = true;
	TotalAlmacenes[3].ListaPedidosAlmacen[1].DatosFarmaco[1].PesoFarmaco = 875;
	TotalAlmacenes[3].ListaPedidosAlmacen[1].DatosFarmaco[1].NumeroFarmacos = 2;
	TotalAlmacenes[3].ListaPedidosAlmacen[1].DatosFarmaco[1].PesoTotalFarmacos = 1750;
	TotalAlmacenes[3].ListaPedidosAlmacen[1].PesoTotalEnvio = 1750;
	TotalAlmacenes[3].HuecoOcupadoPedidos[1] = true;

	/* Guardado de datos del septimo pedido */
	TotalAlmacenes[3].ListaPedidosAlmacen[2].AlmacenPedido = 3;
	TotalAlmacenes[3].ListaPedidosAlmacen[2].RefPedido = 1;
	TotalAlmacenes[3].ListaPedidosAlmacen[2].NumeroEnvios = 1;
	TotalAlmacenes[3].ListaPedidosAlmacen[2].Fecha.Dia = 3;
	TotalAlmacenes[3].ListaPedidosAlmacen[2].Fecha.Mes = 1;
	TotalAlmacenes[3].ListaPedidosAlmacen[2].Fecha.Anho = 2021;
	strcpy (TotalAlmacenes[3].ListaPedidosAlmacen[2].DatosFarmaco[1].Farmaco, "Acenocumarol");
	TotalAlmacenes[3].ListaPedidosAlmacen[2].HuecoOcupadoFarmacos[1] = true;
	TotalAlmacenes[3].ListaPedidosAlmacen[2].DatosFarmaco[1].PesoFarmaco = 25;
	TotalAlmacenes[3].ListaPedidosAlmacen[2].DatosFarmaco[1].NumeroFarmacos = 2;
	TotalAlmacenes[3].ListaPedidosAlmacen[2].DatosFarmaco[1].PesoTotalFarmacos = 50;
	strcpy (TotalAlmacenes[3].ListaPedidosAlmacen[2].DatosFarmaco[2].Farmaco, "Pantoprazol");
	TotalAlmacenes[3].ListaPedidosAlmacen[2].HuecoOcupadoFarmacos[2] = true;
	TotalAlmacenes[3].ListaPedidosAlmacen[2].DatosFarmaco[2].PesoFarmaco = 50;
	TotalAlmacenes[3].ListaPedidosAlmacen[2].DatosFarmaco[2].NumeroFarmacos = 1;
	TotalAlmacenes[3].ListaPedidosAlmacen[2].DatosFarmaco[2].PesoTotalFarmacos = 50;
	strcpy (TotalAlmacenes[3].ListaPedidosAlmacen[2].DatosFarmaco[3].Farmaco, "Ibuprofeno");
	TotalAlmacenes[3].ListaPedidosAlmacen[2].HuecoOcupadoFarmacos[3] = true;
	TotalAlmacenes[3].ListaPedidosAlmacen[2].DatosFarmaco[3].PesoFarmaco = 600;
	TotalAlmacenes[3].ListaPedidosAlmacen[2].DatosFarmaco[3].NumeroFarmacos = 1;
	TotalAlmacenes[3].ListaPedidosAlmacen[2].DatosFarmaco[3].PesoTotalFarmacos = 600;
	strcpy (TotalAlmacenes[3].ListaPedidosAlmacen[2].DatosFarmaco[4].Farmaco, "Tiamina");
	TotalAlmacenes[3].ListaPedidosAlmacen[2].HuecoOcupadoFarmacos[4] = true;
	TotalAlmacenes[3].ListaPedidosAlmacen[2].DatosFarmaco[4].PesoFarmaco = 5;
	TotalAlmacenes[3].ListaPedidosAlmacen[2].DatosFarmaco[4].NumeroFarmacos = 1;
	TotalAlmacenes[3].ListaPedidosAlmacen[2].DatosFarmaco[4].PesoTotalFarmacos = 5;
	TotalAlmacenes[3].ListaPedidosAlmacen[2].PesoTotalEnvio = 705;
	TotalAlmacenes[3].HuecoOcupadoPedidos[2] = true;

	/* Guardado de datos del octavo pedido */
	TotalAlmacenes[3].ListaPedidosAlmacen[3].AlmacenPedido = 3;
	TotalAlmacenes[3].ListaPedidosAlmacen[3].RefPedido = 2;
	TotalAlmacenes[3].ListaPedidosAlmacen[3].NumeroEnvios = 1;
	TotalAlmacenes[3].ListaPedidosAlmacen[3].Fecha.Dia = 4;
	TotalAlmacenes[3].ListaPedidosAlmacen[3].Fecha.Mes = 1;
	TotalAlmacenes[3].ListaPedidosAlmacen[3].Fecha.Anho = 2021;
	strcpy (TotalAlmacenes[3].ListaPedidosAlmacen[3].DatosFarmaco[1].Farmaco, "Amoxicilina");
	TotalAlmacenes[3].ListaPedidosAlmacen[3].HuecoOcupadoFarmacos[1] = true;
	TotalAlmacenes[3].ListaPedidosAlmacen[3].DatosFarmaco[1].PesoFarmaco = 125;
	TotalAlmacenes[3].ListaPedidosAlmacen[3].DatosFarmaco[1].NumeroFarmacos = 1;
	TotalAlmacenes[3].ListaPedidosAlmacen[3].DatosFarmaco[1].PesoTotalFarmacos = 125;
	TotalAlmacenes[3].ListaPedidosAlmacen[3].PesoTotalEnvio = 125;
	TotalAlmacenes[3].HuecoOcupadoPedidos[3] = true;

	/* Guardado de datos del noveno pedido */
	TotalAlmacenes[3].ListaPedidosAlmacen[4].AlmacenPedido = 3;
	TotalAlmacenes[3].ListaPedidosAlmacen[4].RefPedido = 3;
	TotalAlmacenes[3].ListaPedidosAlmacen[4].NumeroEnvios = 1;
	TotalAlmacenes[3].ListaPedidosAlmacen[4].Fecha.Dia = 5;
	TotalAlmacenes[3].ListaPedidosAlmacen[4].Fecha.Mes = 1;
	TotalAlmacenes[3].ListaPedidosAlmacen[4].Fecha.Anho = 2021;
	strcpy (TotalAlmacenes[3].ListaPedidosAlmacen[4].DatosFarmaco[1].Farmaco, "Pantoprazol");
	TotalAlmacenes[3].ListaPedidosAlmacen[4].HuecoOcupadoFarmacos[1] = true;
	TotalAlmacenes[3].ListaPedidosAlmacen[4].DatosFarmaco[1].PesoFarmaco = 50;
	TotalAlmacenes[3].ListaPedidosAlmacen[4].DatosFarmaco[1].NumeroFarmacos = 5;
	TotalAlmacenes[3].ListaPedidosAlmacen[4].DatosFarmaco[1].PesoTotalFarmacos = 250;
	TotalAlmacenes[3].ListaPedidosAlmacen[4].PesoTotalEnvio = 250;
	TotalAlmacenes[3].HuecoOcupadoPedidos[4] = true;

	/* Guardado de datos del decimo pedido */
	TotalAlmacenes[3].ListaPedidosAlmacen[5].AlmacenPedido = 3;
	TotalAlmacenes[3].ListaPedidosAlmacen[5].RefPedido = 2;
	TotalAlmacenes[3].ListaPedidosAlmacen[5].NumeroEnvios = 1;
	TotalAlmacenes[3].ListaPedidosAlmacen[5].Fecha.Dia = 5;
	TotalAlmacenes[3].ListaPedidosAlmacen[5].Fecha.Mes = 1;
	TotalAlmacenes[3].ListaPedidosAlmacen[5].Fecha.Anho = 2021;
	strcpy (TotalAlmacenes[3].ListaPedidosAlmacen[5].DatosFarmaco[1].Farmaco, "Acenocumarol");
	TotalAlmacenes[3].ListaPedidosAlmacen[5].HuecoOcupadoFarmacos[1] = true;
	TotalAlmacenes[3].ListaPedidosAlmacen[5].DatosFarmaco[1].PesoFarmaco = 10;
	TotalAlmacenes[3].ListaPedidosAlmacen[5].DatosFarmaco[1].NumeroFarmacos = 10;
	TotalAlmacenes[3].ListaPedidosAlmacen[5].DatosFarmaco[1].PesoTotalFarmacos = 100;
	TotalAlmacenes[3].ListaPedidosAlmacen[5].PesoTotalEnvio = 100;
	TotalAlmacenes[3].HuecoOcupadoPedidos[5] = true;

	/* Guardado de datos del undecimo pedido */
	TotalAlmacenes[3].ListaPedidosAlmacen[6].AlmacenPedido = 3;
	TotalAlmacenes[3].ListaPedidosAlmacen[6].RefPedido = 4;
	TotalAlmacenes[3].ListaPedidosAlmacen[6].NumeroEnvios = 1;
	TotalAlmacenes[3].ListaPedidosAlmacen[6].Fecha.Dia = 1;
	TotalAlmacenes[3].ListaPedidosAlmacen[6].Fecha.Mes = 2;
	TotalAlmacenes[3].ListaPedidosAlmacen[6].Fecha.Anho = 2021;
	strcpy (TotalAlmacenes[3].ListaPedidosAlmacen[6].DatosFarmaco[1].Farmaco, "Paracetamol");
	TotalAlmacenes[3].ListaPedidosAlmacen[6].HuecoOcupadoFarmacos[1] = true;
	TotalAlmacenes[3].ListaPedidosAlmacen[6].DatosFarmaco[1].PesoFarmaco = 100;
	TotalAlmacenes[3].ListaPedidosAlmacen[6].DatosFarmaco[1].NumeroFarmacos = 1;
	TotalAlmacenes[3].ListaPedidosAlmacen[6].DatosFarmaco[1].PesoTotalFarmacos = 100;
	strcpy (TotalAlmacenes[3].ListaPedidosAlmacen[6].DatosFarmaco[2].Farmaco, "Pantoprazol");
	TotalAlmacenes[3].ListaPedidosAlmacen[6].HuecoOcupadoFarmacos[2] = true;
	TotalAlmacenes[3].ListaPedidosAlmacen[6].DatosFarmaco[2].PesoFarmaco = 50;
	TotalAlmacenes[3].ListaPedidosAlmacen[6].DatosFarmaco[2].NumeroFarmacos = 2;
	TotalAlmacenes[3].ListaPedidosAlmacen[6].DatosFarmaco[2].PesoTotalFarmacos = 100;
	strcpy (TotalAlmacenes[3].ListaPedidosAlmacen[6].DatosFarmaco[3].Farmaco, "Ibuprofeno");
	TotalAlmacenes[3].ListaPedidosAlmacen[6].HuecoOcupadoFarmacos[3] = true;
	TotalAlmacenes[3].ListaPedidosAlmacen[6].DatosFarmaco[3].PesoFarmaco = 10;
	TotalAlmacenes[3].ListaPedidosAlmacen[6].DatosFarmaco[3].NumeroFarmacos = 1;
	TotalAlmacenes[3].ListaPedidosAlmacen[6].DatosFarmaco[3].PesoTotalFarmacos = 10;
	strcpy (TotalAlmacenes[3].ListaPedidosAlmacen[6].DatosFarmaco[4].Farmaco, "Metamizol");
	TotalAlmacenes[3].ListaPedidosAlmacen[6].HuecoOcupadoFarmacos[4] = true;
	TotalAlmacenes[3].ListaPedidosAlmacen[6].DatosFarmaco[4].PesoFarmaco = 50;
	TotalAlmacenes[3].ListaPedidosAlmacen[6].DatosFarmaco[4].NumeroFarmacos = 5;
	TotalAlmacenes[3].ListaPedidosAlmacen[6].DatosFarmaco[4].PesoTotalFarmacos = 250;
	strcpy (TotalAlmacenes[3].ListaPedidosAlmacen[6].DatosFarmaco[5].Farmaco, "Acido Valproico");
	TotalAlmacenes[3].ListaPedidosAlmacen[6].HuecoOcupadoFarmacos[5] = true;
	TotalAlmacenes[3].ListaPedidosAlmacen[6].DatosFarmaco[5].PesoFarmaco = 175;
	TotalAlmacenes[3].ListaPedidosAlmacen[6].DatosFarmaco[5].NumeroFarmacos = 5;
	TotalAlmacenes[3].ListaPedidosAlmacen[6].DatosFarmaco[5].PesoTotalFarmacos = 875;
	TotalAlmacenes[3].ListaPedidosAlmacen[6].PesoTotalEnvio = 1335;
	TotalAlmacenes[3].HuecoOcupadoPedidos[6] = true;

	/* Guardado de datos del duodecimo pedido */
	TotalAlmacenes[3].ListaPedidosAlmacen[7].AlmacenPedido = 3;
	TotalAlmacenes[3].ListaPedidosAlmacen[7].RefPedido = 5;
	TotalAlmacenes[3].ListaPedidosAlmacen[7].NumeroEnvios = 1;
	TotalAlmacenes[3].ListaPedidosAlmacen[7].Fecha.Dia = 1;
	TotalAlmacenes[3].ListaPedidosAlmacen[7].Fecha.Mes = 2;
	TotalAlmacenes[3].ListaPedidosAlmacen[7].Fecha.Anho = 2021;
	strcpy (TotalAlmacenes[3].ListaPedidosAlmacen[7].DatosFarmaco[1].Farmaco, "Paracetamol");
	TotalAlmacenes[3].ListaPedidosAlmacen[7].HuecoOcupadoFarmacos[1] = true;
	TotalAlmacenes[3].ListaPedidosAlmacen[7].DatosFarmaco[1].PesoFarmaco = 100;
	TotalAlmacenes[3].ListaPedidosAlmacen[7].DatosFarmaco[1].NumeroFarmacos = 5;
	TotalAlmacenes[3].ListaPedidosAlmacen[7].DatosFarmaco[1].PesoTotalFarmacos = 500;
	TotalAlmacenes[3].ListaPedidosAlmacen[7].PesoTotalEnvio = 500;
	TotalAlmacenes[3].HuecoOcupadoPedidos[7] = true;

	/* Guardado de datos del decimotercer pedido */
	TotalAlmacenes[3].ListaPedidosAlmacen[8].AlmacenPedido = 3;
	TotalAlmacenes[3].ListaPedidosAlmacen[8].RefPedido = 5;
	TotalAlmacenes[3].ListaPedidosAlmacen[8].NumeroEnvios = 1;
	TotalAlmacenes[3].ListaPedidosAlmacen[8].Fecha.Dia = 2;
	TotalAlmacenes[3].ListaPedidosAlmacen[8].Fecha.Mes = 2;
	TotalAlmacenes[3].ListaPedidosAlmacen[8].Fecha.Anho = 2021;
	strcpy (TotalAlmacenes[3].ListaPedidosAlmacen[8].DatosFarmaco[1].Farmaco, "Acenocumarol");
	TotalAlmacenes[3].ListaPedidosAlmacen[8].HuecoOcupadoFarmacos[1] = true;
	TotalAlmacenes[3].ListaPedidosAlmacen[8].DatosFarmaco[1].PesoFarmaco = 50;
	TotalAlmacenes[3].ListaPedidosAlmacen[8].DatosFarmaco[1].NumeroFarmacos = 15;
	TotalAlmacenes[3].ListaPedidosAlmacen[8].DatosFarmaco[1].PesoTotalFarmacos = 750;
	TotalAlmacenes[3].ListaPedidosAlmacen[8].PesoTotalEnvio = 750;
	TotalAlmacenes[3].HuecoOcupadoPedidos[8] = true;

	/* Guardado de datos del decimocuarto pedido */
	TotalAlmacenes[4].ListaPedidosAlmacen[1].AlmacenPedido = 4;
	TotalAlmacenes[4].ListaPedidosAlmacen[1].RefPedido = 1;
	TotalAlmacenes[4].ListaPedidosAlmacen[1].NumeroEnvios = 1;
	TotalAlmacenes[4].ListaPedidosAlmacen[1].Fecha.Dia = 1;
	TotalAlmacenes[4].ListaPedidosAlmacen[1].Fecha.Mes = 1;
	TotalAlmacenes[4].ListaPedidosAlmacen[1].Fecha.Anho = 2021;
	strcpy (TotalAlmacenes[4].ListaPedidosAlmacen[1].DatosFarmaco[1].Farmaco, "Ranitidina");
	TotalAlmacenes[4].ListaPedidosAlmacen[1].HuecoOcupadoFarmacos[1] = true;
	TotalAlmacenes[4].ListaPedidosAlmacen[1].DatosFarmaco[1].PesoFarmaco = 20;
	TotalAlmacenes[4].ListaPedidosAlmacen[1].DatosFarmaco[1].NumeroFarmacos = 5;
	TotalAlmacenes[4].ListaPedidosAlmacen[1].DatosFarmaco[1].PesoTotalFarmacos = 100;
	strcpy (TotalAlmacenes[4].ListaPedidosAlmacen[1].DatosFarmaco[2].Farmaco, "Lactulosa");
	TotalAlmacenes[4].ListaPedidosAlmacen[1].HuecoOcupadoFarmacos[2] = true;
	TotalAlmacenes[4].ListaPedidosAlmacen[1].DatosFarmaco[2].PesoFarmaco = 80;
	TotalAlmacenes[4].ListaPedidosAlmacen[1].DatosFarmaco[2].NumeroFarmacos = 8;
	TotalAlmacenes[4].ListaPedidosAlmacen[1].DatosFarmaco[2].PesoTotalFarmacos = 640;
	strcpy (TotalAlmacenes[4].ListaPedidosAlmacen[1].DatosFarmaco[3].Farmaco, "Metamizol");
	TotalAlmacenes[4].ListaPedidosAlmacen[1].HuecoOcupadoFarmacos[3] = true;
	TotalAlmacenes[4].ListaPedidosAlmacen[1].DatosFarmaco[3].PesoFarmaco = 50;
	TotalAlmacenes[4].ListaPedidosAlmacen[1].DatosFarmaco[3].NumeroFarmacos = 5;
	TotalAlmacenes[4].ListaPedidosAlmacen[1].DatosFarmaco[3].PesoTotalFarmacos = 250;
	TotalAlmacenes[4].ListaPedidosAlmacen[1].PesoTotalEnvio = 990;
	TotalAlmacenes[4].HuecoOcupadoPedidos[1] = true;

	/* Guardado de datos del decimoquinto pedido */
	TotalAlmacenes[4].ListaPedidosAlmacen[2].AlmacenPedido = 4;
	TotalAlmacenes[4].ListaPedidosAlmacen[2].RefPedido = 1;
	TotalAlmacenes[4].ListaPedidosAlmacen[2].NumeroEnvios = 1;
	TotalAlmacenes[4].ListaPedidosAlmacen[2].Fecha.Dia = 1;
	TotalAlmacenes[4].ListaPedidosAlmacen[2].Fecha.Mes = 2;
	TotalAlmacenes[4].ListaPedidosAlmacen[2].Fecha.Anho = 2021;
	strcpy (TotalAlmacenes[4].ListaPedidosAlmacen[2].DatosFarmaco[1].Farmaco, "Paracetamol");
	TotalAlmacenes[4].ListaPedidosAlmacen[2].HuecoOcupadoFarmacos[1] = true;
	TotalAlmacenes[4].ListaPedidosAlmacen[2].DatosFarmaco[1].PesoFarmaco = 100;
	TotalAlmacenes[4].ListaPedidosAlmacen[2].DatosFarmaco[1].NumeroFarmacos = 5;
	TotalAlmacenes[4].ListaPedidosAlmacen[2].DatosFarmaco[1].PesoTotalFarmacos = 500;
	TotalAlmacenes[4].ListaPedidosAlmacen[2].PesoTotalEnvio = 500;
	TotalAlmacenes[4].HuecoOcupadoPedidos[2] = true;

	printf("\nListado Gestion FarmaDron\n\n");
	printf("      Almacen %d -- %s -- %s -- %s\n", TotalAlmacenes[1].IdentificadorAlmacen, TotalAlmacenes[1].DireccionAlmacen, TotalAlmacenes[1].MunicipioAlmacen, TotalAlmacenes[1].ProvinciaAlmacen);
	printf("      Descripcion: %s", TotalAlmacenes[1].DescripcionAlmacen);
	printf("\n\n      -Clientes-\n");
	printf("      Ref.  Identificador           Distancia      Angulo         \n");
	printf("      ___________________________________________________\n");
	printf("      %-6d%-24s%-15d%-15d\n", TotalAlmacenes[1].UbicacionesAlmacen[1].Referencia,TotalAlmacenes[1].UbicacionesAlmacen[1].Identificador, TotalAlmacenes[1].UbicacionesAlmacen[1].Distancia, TotalAlmacenes[1].UbicacionesAlmacen[1].Angulo);
	printf("      %-6d%-24s%-15d%-15d\n", TotalAlmacenes[1].UbicacionesAlmacen[2].Referencia,TotalAlmacenes[1].UbicacionesAlmacen[2].Identificador, TotalAlmacenes[1].UbicacionesAlmacen[2].Distancia, TotalAlmacenes[1].UbicacionesAlmacen[2].Angulo);
	printf("      %-6d%-24s%-15d%-15d\n", TotalAlmacenes[1].UbicacionesAlmacen[3].Referencia,TotalAlmacenes[1].UbicacionesAlmacen[3].Identificador, TotalAlmacenes[1].UbicacionesAlmacen[3].Distancia, TotalAlmacenes[1].UbicacionesAlmacen[3].Angulo);
	printf("\n      -Pedidos-\n");
	printf("      Cliente   Fecha        Farmaco               Peso    Unidades");
	printf("\n      _____________________________________________________________\n");
	printf("      %-10d%-2d/%-2d/%-7d%-22s%-8d%-8d\n", TotalAlmacenes[1].ListaPedidosAlmacen[1].RefPedido, TotalAlmacenes[1].ListaPedidosAlmacen[1].Fecha.Dia, TotalAlmacenes[1].ListaPedidosAlmacen[1].Fecha.Mes, TotalAlmacenes[1].ListaPedidosAlmacen[1].Fecha.Anho, TotalAlmacenes[1].ListaPedidosAlmacen[1].DatosFarmaco[1].Farmaco, TotalAlmacenes[1].ListaPedidosAlmacen[1].DatosFarmaco[1].PesoFarmaco, TotalAlmacenes[1].ListaPedidosAlmacen[1].DatosFarmaco[1].NumeroFarmacos);			
	printf("                             %-22s%-8d%-8d\n", TotalAlmacenes[1].ListaPedidosAlmacen[1].DatosFarmaco[2].Farmaco, TotalAlmacenes[1].ListaPedidosAlmacen[1].DatosFarmaco[2].PesoFarmaco, TotalAlmacenes[1].ListaPedidosAlmacen[1].DatosFarmaco[2].NumeroFarmacos);			
	printf("      %-10d%-2d/%-2d/%-7d%-22s%-8d%-8d\n", TotalAlmacenes[1].ListaPedidosAlmacen[2].RefPedido, TotalAlmacenes[1].ListaPedidosAlmacen[2].Fecha.Dia, TotalAlmacenes[1].ListaPedidosAlmacen[2].Fecha.Mes, TotalAlmacenes[1].ListaPedidosAlmacen[2].Fecha.Anho, TotalAlmacenes[1].ListaPedidosAlmacen[2].DatosFarmaco[1].Farmaco, TotalAlmacenes[1].ListaPedidosAlmacen[2].DatosFarmaco[1].PesoFarmaco, TotalAlmacenes[1].ListaPedidosAlmacen[2].DatosFarmaco[1].NumeroFarmacos);			
	printf("                             %-22s%-8d%-8d\n", TotalAlmacenes[1].ListaPedidosAlmacen[2].DatosFarmaco[2].Farmaco, TotalAlmacenes[1].ListaPedidosAlmacen[2].DatosFarmaco[2].PesoFarmaco, TotalAlmacenes[1].ListaPedidosAlmacen[2].DatosFarmaco[2].NumeroFarmacos);			
	printf("                             %-22s%-8d%-8d\n", TotalAlmacenes[1].ListaPedidosAlmacen[2].DatosFarmaco[3].Farmaco, TotalAlmacenes[1].ListaPedidosAlmacen[2].DatosFarmaco[3].PesoFarmaco, TotalAlmacenes[1].ListaPedidosAlmacen[2].DatosFarmaco[3].NumeroFarmacos);			
	printf("      %-10d%-2d/%-2d/%-7d%-22s%-8d%-8d\n", TotalAlmacenes[1].ListaPedidosAlmacen[3].RefPedido, TotalAlmacenes[1].ListaPedidosAlmacen[3].Fecha.Dia, TotalAlmacenes[1].ListaPedidosAlmacen[3].Fecha.Mes, TotalAlmacenes[1].ListaPedidosAlmacen[3].Fecha.Anho, TotalAlmacenes[1].ListaPedidosAlmacen[3].DatosFarmaco[1].Farmaco, TotalAlmacenes[1].ListaPedidosAlmacen[3].DatosFarmaco[1].PesoFarmaco, TotalAlmacenes[1].ListaPedidosAlmacen[3].DatosFarmaco[1].NumeroFarmacos);			
	printf("                             %-22s%-8d%-8d\n", TotalAlmacenes[1].ListaPedidosAlmacen[3].DatosFarmaco[2].Farmaco, TotalAlmacenes[1].ListaPedidosAlmacen[3].DatosFarmaco[2].PesoFarmaco, TotalAlmacenes[1].ListaPedidosAlmacen[3].DatosFarmaco[2].NumeroFarmacos);			
	printf("      %-10d%-2d/%-2d/%-7d%-22s%-8d%-8d\n", TotalAlmacenes[1].ListaPedidosAlmacen[4].RefPedido, TotalAlmacenes[1].ListaPedidosAlmacen[4].Fecha.Dia, TotalAlmacenes[1].ListaPedidosAlmacen[4].Fecha.Mes, TotalAlmacenes[1].ListaPedidosAlmacen[4].Fecha.Anho, TotalAlmacenes[1].ListaPedidosAlmacen[4].DatosFarmaco[1].Farmaco, TotalAlmacenes[1].ListaPedidosAlmacen[4].DatosFarmaco[1].PesoFarmaco, TotalAlmacenes[1].ListaPedidosAlmacen[4].DatosFarmaco[1].NumeroFarmacos);			
	
	printf("\n\n      Almacen %d -- %s -- %s -- %s\n", TotalAlmacenes[2].IdentificadorAlmacen, TotalAlmacenes[2].DireccionAlmacen, TotalAlmacenes[2].MunicipioAlmacen, TotalAlmacenes[2].ProvinciaAlmacen);
	printf("      Descripcion: %s", TotalAlmacenes[2].DescripcionAlmacen);
	printf("\n\n      -Clientes-\n");
	printf("      Ref.  Identificador           Distancia      Angulo         \n");
	printf("      ___________________________________________________\n");
	printf("      %-6d%-24s%-15d%-15d\n", TotalAlmacenes[2].UbicacionesAlmacen[1].Referencia,TotalAlmacenes[2].UbicacionesAlmacen[1].Identificador, TotalAlmacenes[2].UbicacionesAlmacen[1].Distancia, TotalAlmacenes[2].UbicacionesAlmacen[1].Angulo);
	printf("\n      -Pedidos-\n");
	printf("      Cliente   Fecha        Farmaco               Peso    Unidades");
	printf("\n      _____________________________________________________________\n");
	printf("      %-10d%-2d/%-2d/%-7d%-22s%-8d%-8d\n", TotalAlmacenes[2].ListaPedidosAlmacen[1].RefPedido, TotalAlmacenes[2].ListaPedidosAlmacen[1].Fecha.Dia, TotalAlmacenes[2].ListaPedidosAlmacen[1].Fecha.Mes, TotalAlmacenes[2].ListaPedidosAlmacen[1].Fecha.Anho, TotalAlmacenes[2].ListaPedidosAlmacen[1].DatosFarmaco[1].Farmaco, TotalAlmacenes[2].ListaPedidosAlmacen[1].DatosFarmaco[1].PesoFarmaco, TotalAlmacenes[2].ListaPedidosAlmacen[1].DatosFarmaco[1].NumeroFarmacos);			
	printf("                             %-22s%-8d%-8d\n", TotalAlmacenes[2].ListaPedidosAlmacen[1].DatosFarmaco[2].Farmaco, TotalAlmacenes[2].ListaPedidosAlmacen[1].DatosFarmaco[2].PesoFarmaco, TotalAlmacenes[2].ListaPedidosAlmacen[1].DatosFarmaco[2].NumeroFarmacos);			
	
	printf("\n\n      Almacen %d -- %s -- %s -- %s\n", TotalAlmacenes[3].IdentificadorAlmacen, TotalAlmacenes[3].DireccionAlmacen, TotalAlmacenes[3].MunicipioAlmacen, TotalAlmacenes[3].ProvinciaAlmacen);
	printf("      Descripcion: %s", TotalAlmacenes[3].DescripcionAlmacen);
	printf("\n\n      -Clientes-\n");
	printf("      Ref.  Identificador           Distancia      Angulo         \n");
	printf("      ___________________________________________________\n");
	printf("      %-6d%-24s%-15d%-15d\n", TotalAlmacenes[3].UbicacionesAlmacen[1].Referencia,TotalAlmacenes[3].UbicacionesAlmacen[1].Identificador, TotalAlmacenes[3].UbicacionesAlmacen[1].Distancia, TotalAlmacenes[3].UbicacionesAlmacen[1].Angulo);
	printf("      %-6d%-24s%-15d%-15d\n", TotalAlmacenes[3].UbicacionesAlmacen[2].Referencia,TotalAlmacenes[3].UbicacionesAlmacen[2].Identificador, TotalAlmacenes[3].UbicacionesAlmacen[2].Distancia, TotalAlmacenes[3].UbicacionesAlmacen[2].Angulo);
	printf("      %-6d%-24s%-15d%-15d\n", TotalAlmacenes[3].UbicacionesAlmacen[3].Referencia,TotalAlmacenes[3].UbicacionesAlmacen[3].Identificador, TotalAlmacenes[3].UbicacionesAlmacen[3].Distancia, TotalAlmacenes[3].UbicacionesAlmacen[3].Angulo);
	printf("      %-6d%-24s%-15d%-15d\n", TotalAlmacenes[3].UbicacionesAlmacen[4].Referencia,TotalAlmacenes[3].UbicacionesAlmacen[4].Identificador, TotalAlmacenes[3].UbicacionesAlmacen[4].Distancia, TotalAlmacenes[3].UbicacionesAlmacen[4].Angulo);
	printf("      %-6d%-24s%-15d%-15d\n", TotalAlmacenes[3].UbicacionesAlmacen[5].Referencia,TotalAlmacenes[3].UbicacionesAlmacen[5].Identificador, TotalAlmacenes[3].UbicacionesAlmacen[5].Distancia, TotalAlmacenes[3].UbicacionesAlmacen[5].Angulo);
	printf("\n      -Pedidos-\n");
	printf("      Cliente   Fecha        Farmaco               Peso    Unidades");
	printf("\n      _____________________________________________________________\n");
	printf("      %-10d%-2d/%-2d/%-7d%-22s%-8d%-8d\n", TotalAlmacenes[3].ListaPedidosAlmacen[1].RefPedido, TotalAlmacenes[3].ListaPedidosAlmacen[1].Fecha.Dia, TotalAlmacenes[3].ListaPedidosAlmacen[1].Fecha.Mes, TotalAlmacenes[3].ListaPedidosAlmacen[1].Fecha.Anho, TotalAlmacenes[3].ListaPedidosAlmacen[1].DatosFarmaco[1].Farmaco, TotalAlmacenes[3].ListaPedidosAlmacen[1].DatosFarmaco[1].PesoFarmaco, TotalAlmacenes[3].ListaPedidosAlmacen[1].DatosFarmaco[1].NumeroFarmacos);			
	printf("      %-10d%-2d/%-2d/%-7d%-22s%-8d%-8d\n", TotalAlmacenes[3].ListaPedidosAlmacen[2].RefPedido, TotalAlmacenes[3].ListaPedidosAlmacen[2].Fecha.Dia, TotalAlmacenes[3].ListaPedidosAlmacen[2].Fecha.Mes, TotalAlmacenes[3].ListaPedidosAlmacen[2].Fecha.Anho, TotalAlmacenes[3].ListaPedidosAlmacen[2].DatosFarmaco[1].Farmaco, TotalAlmacenes[3].ListaPedidosAlmacen[2].DatosFarmaco[1].PesoFarmaco, TotalAlmacenes[3].ListaPedidosAlmacen[2].DatosFarmaco[1].NumeroFarmacos);			
	printf("                             %-22s%-8d%-8d\n", TotalAlmacenes[3].ListaPedidosAlmacen[2].DatosFarmaco[2].Farmaco, TotalAlmacenes[3].ListaPedidosAlmacen[2].DatosFarmaco[2].PesoFarmaco, TotalAlmacenes[3].ListaPedidosAlmacen[2].DatosFarmaco[2].NumeroFarmacos);			
	printf("                             %-22s%-8d%-8d\n", TotalAlmacenes[3].ListaPedidosAlmacen[2].DatosFarmaco[3].Farmaco, TotalAlmacenes[3].ListaPedidosAlmacen[2].DatosFarmaco[3].PesoFarmaco, TotalAlmacenes[3].ListaPedidosAlmacen[2].DatosFarmaco[3].NumeroFarmacos);			
	printf("                             %-22s%-8d%-8d\n", TotalAlmacenes[3].ListaPedidosAlmacen[2].DatosFarmaco[4].Farmaco, TotalAlmacenes[3].ListaPedidosAlmacen[2].DatosFarmaco[4].PesoFarmaco, TotalAlmacenes[3].ListaPedidosAlmacen[2].DatosFarmaco[4].NumeroFarmacos);			
	printf("      %-10d%-2d/%-2d/%-7d%-22s%-8d%-8d\n", TotalAlmacenes[3].ListaPedidosAlmacen[3].RefPedido, TotalAlmacenes[3].ListaPedidosAlmacen[3].Fecha.Dia, TotalAlmacenes[3].ListaPedidosAlmacen[3].Fecha.Mes, TotalAlmacenes[3].ListaPedidosAlmacen[3].Fecha.Anho, TotalAlmacenes[3].ListaPedidosAlmacen[3].DatosFarmaco[1].Farmaco, TotalAlmacenes[3].ListaPedidosAlmacen[3].DatosFarmaco[1].PesoFarmaco, TotalAlmacenes[3].ListaPedidosAlmacen[3].DatosFarmaco[1].NumeroFarmacos);			
	printf("      %-10d%-2d/%-2d/%-7d%-22s%-8d%-8d\n", TotalAlmacenes[3].ListaPedidosAlmacen[4].RefPedido, TotalAlmacenes[3].ListaPedidosAlmacen[4].Fecha.Dia, TotalAlmacenes[3].ListaPedidosAlmacen[4].Fecha.Mes, TotalAlmacenes[3].ListaPedidosAlmacen[4].Fecha.Anho, TotalAlmacenes[3].ListaPedidosAlmacen[4].DatosFarmaco[1].Farmaco, TotalAlmacenes[3].ListaPedidosAlmacen[4].DatosFarmaco[1].PesoFarmaco, TotalAlmacenes[3].ListaPedidosAlmacen[4].DatosFarmaco[1].NumeroFarmacos);			
	printf("      %-10d%-2d/%-2d/%-7d%-22s%-8d%-8d\n", TotalAlmacenes[3].ListaPedidosAlmacen[5].RefPedido, TotalAlmacenes[3].ListaPedidosAlmacen[5].Fecha.Dia, TotalAlmacenes[3].ListaPedidosAlmacen[5].Fecha.Mes, TotalAlmacenes[3].ListaPedidosAlmacen[5].Fecha.Anho, TotalAlmacenes[3].ListaPedidosAlmacen[5].DatosFarmaco[1].Farmaco, TotalAlmacenes[3].ListaPedidosAlmacen[5].DatosFarmaco[1].PesoFarmaco, TotalAlmacenes[3].ListaPedidosAlmacen[5].DatosFarmaco[1].NumeroFarmacos);			
	printf("      %-10d%-2d/%-2d/%-7d%-22s%-8d%-8d\n", TotalAlmacenes[3].ListaPedidosAlmacen[6].RefPedido, TotalAlmacenes[3].ListaPedidosAlmacen[6].Fecha.Dia, TotalAlmacenes[3].ListaPedidosAlmacen[6].Fecha.Mes, TotalAlmacenes[3].ListaPedidosAlmacen[6].Fecha.Anho, TotalAlmacenes[3].ListaPedidosAlmacen[6].DatosFarmaco[1].Farmaco, TotalAlmacenes[3].ListaPedidosAlmacen[6].DatosFarmaco[1].PesoFarmaco, TotalAlmacenes[3].ListaPedidosAlmacen[6].DatosFarmaco[1].NumeroFarmacos);			
	printf("                             %-22s%-8d%-8d\n", TotalAlmacenes[3].ListaPedidosAlmacen[6].DatosFarmaco[2].Farmaco, TotalAlmacenes[3].ListaPedidosAlmacen[6].DatosFarmaco[2].PesoFarmaco, TotalAlmacenes[3].ListaPedidosAlmacen[6].DatosFarmaco[2].NumeroFarmacos);			
	printf("                             %-22s%-8d%-8d\n", TotalAlmacenes[3].ListaPedidosAlmacen[6].DatosFarmaco[3].Farmaco, TotalAlmacenes[3].ListaPedidosAlmacen[6].DatosFarmaco[3].PesoFarmaco, TotalAlmacenes[3].ListaPedidosAlmacen[6].DatosFarmaco[3].NumeroFarmacos);			
	printf("                             %-22s%-8d%-8d\n", TotalAlmacenes[3].ListaPedidosAlmacen[6].DatosFarmaco[4].Farmaco, TotalAlmacenes[3].ListaPedidosAlmacen[6].DatosFarmaco[4].PesoFarmaco, TotalAlmacenes[3].ListaPedidosAlmacen[6].DatosFarmaco[4].NumeroFarmacos);			
	printf("                             %-22s%-8d%-8d\n", TotalAlmacenes[3].ListaPedidosAlmacen[6].DatosFarmaco[5].Farmaco, TotalAlmacenes[3].ListaPedidosAlmacen[6].DatosFarmaco[5].PesoFarmaco, TotalAlmacenes[3].ListaPedidosAlmacen[6].DatosFarmaco[5].NumeroFarmacos);			
	printf("      %-10d%-2d/%-2d/%-7d%-22s%-8d%-8d\n", TotalAlmacenes[3].ListaPedidosAlmacen[7].RefPedido, TotalAlmacenes[3].ListaPedidosAlmacen[7].Fecha.Dia, TotalAlmacenes[3].ListaPedidosAlmacen[7].Fecha.Mes, TotalAlmacenes[3].ListaPedidosAlmacen[7].Fecha.Anho, TotalAlmacenes[3].ListaPedidosAlmacen[7].DatosFarmaco[1].Farmaco, TotalAlmacenes[3].ListaPedidosAlmacen[7].DatosFarmaco[1].PesoFarmaco, TotalAlmacenes[3].ListaPedidosAlmacen[7].DatosFarmaco[1].NumeroFarmacos);			
	printf("      %-10d%-2d/%-2d/%-7d%-22s%-8d%-8d\n", TotalAlmacenes[3].ListaPedidosAlmacen[8].RefPedido, TotalAlmacenes[3].ListaPedidosAlmacen[8].Fecha.Dia, TotalAlmacenes[3].ListaPedidosAlmacen[8].Fecha.Mes, TotalAlmacenes[3].ListaPedidosAlmacen[8].Fecha.Anho, TotalAlmacenes[3].ListaPedidosAlmacen[8].DatosFarmaco[1].Farmaco, TotalAlmacenes[3].ListaPedidosAlmacen[8].DatosFarmaco[1].PesoFarmaco, TotalAlmacenes[3].ListaPedidosAlmacen[8].DatosFarmaco[1].NumeroFarmacos);			
	
	printf("\n\n      Almacen %d -- %s -- %s -- %s\n", TotalAlmacenes[4].IdentificadorAlmacen, TotalAlmacenes[4].DireccionAlmacen, TotalAlmacenes[4].MunicipioAlmacen, TotalAlmacenes[4].ProvinciaAlmacen);
	printf("      Descripcion: %s", TotalAlmacenes[4].DescripcionAlmacen);
	printf("\n\n      -Clientes-\n");
	printf("      Ref.  Identificador           Distancia      Angulo         \n");
	printf("      ___________________________________________________\n");
	printf("      %-6d%-24s%-15d%-15d\n", TotalAlmacenes[4].UbicacionesAlmacen[1].Referencia,TotalAlmacenes[4].UbicacionesAlmacen[1].Identificador, TotalAlmacenes[4].UbicacionesAlmacen[1].Distancia, TotalAlmacenes[4].UbicacionesAlmacen[1].Angulo);
	printf("\n      -Pedidos-\n");
	printf("      Cliente   Fecha        Farmaco               Peso    Unidades");
	printf("\n      _____________________________________________________________\n");
	printf("      %-10d%-2d/%-2d/%-7d%-22s%-8d%-8d\n", TotalAlmacenes[4].ListaPedidosAlmacen[1].RefPedido, TotalAlmacenes[4].ListaPedidosAlmacen[1].Fecha.Dia, TotalAlmacenes[4].ListaPedidosAlmacen[1].Fecha.Mes, TotalAlmacenes[4].ListaPedidosAlmacen[1].Fecha.Anho, TotalAlmacenes[4].ListaPedidosAlmacen[1].DatosFarmaco[1].Farmaco, TotalAlmacenes[4].ListaPedidosAlmacen[1].DatosFarmaco[1].PesoFarmaco, TotalAlmacenes[4].ListaPedidosAlmacen[1].DatosFarmaco[1].NumeroFarmacos);			
	printf("                             %-22s%-8d%-8d\n", TotalAlmacenes[4].ListaPedidosAlmacen[1].DatosFarmaco[2].Farmaco, TotalAlmacenes[4].ListaPedidosAlmacen[1].DatosFarmaco[2].PesoFarmaco, TotalAlmacenes[4].ListaPedidosAlmacen[1].DatosFarmaco[2].NumeroFarmacos);			
	printf("                             %-22s%-8d%-8d\n", TotalAlmacenes[4].ListaPedidosAlmacen[1].DatosFarmaco[3].Farmaco, TotalAlmacenes[4].ListaPedidosAlmacen[1].DatosFarmaco[3].PesoFarmaco, TotalAlmacenes[4].ListaPedidosAlmacen[1].DatosFarmaco[3].NumeroFarmacos);			
	printf("      %-10d%-2d/%-2d/%-7d%-22s%-8d%-8d\n", TotalAlmacenes[4].ListaPedidosAlmacen[2].RefPedido, TotalAlmacenes[4].ListaPedidosAlmacen[2].Fecha.Dia, TotalAlmacenes[4].ListaPedidosAlmacen[2].Fecha.Mes, TotalAlmacenes[4].ListaPedidosAlmacen[2].Fecha.Anho, TotalAlmacenes[4].ListaPedidosAlmacen[2].DatosFarmaco[1].Farmaco, TotalAlmacenes[4].ListaPedidosAlmacen[2].DatosFarmaco[1].PesoFarmaco, TotalAlmacenes[4].ListaPedidosAlmacen[2].DatosFarmaco[1].NumeroFarmacos);			
	

	printf("\n\n      Almacen %d -- %s -- %s -- %s\n", TotalAlmacenes[5].IdentificadorAlmacen, TotalAlmacenes[5].DireccionAlmacen, TotalAlmacenes[5].MunicipioAlmacen, TotalAlmacenes[5].ProvinciaAlmacen);
	printf("      Descripcion: %s", TotalAlmacenes[5].DescripcionAlmacen);
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
			IniciarHuecosAlta();
			IniciarHuecosPedido();
			for (int k=1; k<=10 && (HuecoEncontradoAlmacen==false); k++) {
				if(HuecoOcupadoAlmacen[k] == false && Almacen.IdentificadorAlmacen == k) {
					HuecoEncontradoAlmacen = true;
					Almacen.MaximoPacientes = 0;
					TotalAlmacenes[k] = Almacen;                   /* Aqui se meten los datos introducidos en Almacen en el vector TotalAlmacenes */
					HuecoOcupadoAlmacen[k] = true;
					MaximoAlmacenes++;
				}
			}
			if (MaximoAlmacenes == 10) {
				printf("\n\nMaximo de almacenes alcanzado\n");
				return;
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
				if(TotalAlmacenes[FilaUbicaciones.AlmacenPaciente].HuecoOcupadoAlta[k] == false) {
				  	HuecoEncontradoAlta = true;
					FilaUbicaciones.Referencia = k;
					TotalAlmacenes[FilaUbicaciones.AlmacenPaciente].UbicacionesAlmacen[k] = FilaUbicaciones;                   /* Aqui se meten los datos introducidos en FilaUbicaciones en el vector TablaUbicaciones */
					TotalAlmacenes[FilaUbicaciones.AlmacenPaciente].HuecoOcupadoAlta[k] = true;
					TotalAlmacenes[FilaUbicaciones.AlmacenPaciente].MaximoPacientes++;
				}
			}
			if (TotalAlmacenes[FilaUbicaciones.AlmacenPaciente].MaximoPacientes == 20) {
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
	int codigoubicacion;
	
	printf("\nLista de pacientes y su ubicacion:\n");
	printf("\n      Codigo almacen? ");
	try {
		scanf("%d", &codigoubicacion);
		if (codigoubicacion <1 || codigoubicacion >10) {
			throw error24;
		}
		else if (HuecoOcupadoAlmacen[codigoubicacion] == false) {
			throw error24;
		}
	}
	catch (ErroresPrograma error24) {
		printf("\n\nDato incorrecto para codigo almacen: o fuera del rango, o no esta creado aun\n");
		return;
	}
	for (int k=1; k<=10; k++) {
		if (codigoubicacion == TotalAlmacenes[k].IdentificadorAlmacen) {
			printf("\n      Ref.  ");
			printf("Identificador           ");
			printf("Distancia      ");
			printf("Angulo         \n");
			for(int i=1; i<=20; i++) {
				if(TotalAlmacenes[codigoubicacion].HuecoOcupadoAlta[i] == true) {
					printf("      %-6d%-24s%-15d%-15d\n", TotalAlmacenes[k].UbicacionesAlmacen[i].Referencia,TotalAlmacenes[k].UbicacionesAlmacen[i].Identificador, TotalAlmacenes[k].UbicacionesAlmacen[i].Distancia, TotalAlmacenes[k].UbicacionesAlmacen[i].Angulo);
				}
			}
			return;
		}
	}	
}

void MENU::NuevoPedido() {
	bool codigocorrecto = false;

	DatosPedido.PesoTotalEnvio = 0;

	IniciarHuecosFarmaco();
	MaximoFarmacos = 1;

	for (int indice=0; indice<=5; indice++) {                                           /* Bucle para convertir en nulo todos los huecos del vector Farmaco */
		for (int k=0; k<=20; k++) {
			DatosPedido.DatosFarmaco[indice].Farmaco[k] = '\0';
		}
	}
	for (int k=0; k<=20; k++) {                                           /* Bucle para convertir en nulo todos los huecos del vector FarmacoAux */
		FarmacoAux[k] = '\0';
	}

	printf("\nNuevo Pedido:\n\n");
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
				if(TotalAlmacenes[DatosPedido.AlmacenPedido].HuecoOcupadoPedidos[k] == false) {
					HuecoEncontradoPedido = true;
					TotalAlmacenes[DatosPedido.AlmacenPedido].ListaPedidosAlmacen[k] = DatosPedido;                     /* Aqui guardamos los datos de DatosPedido en el vector ListaTotalPedidos en cada almacen */
					TotalAlmacenes[DatosPedido.AlmacenPedido].HuecoOcupadoPedidos[k] = true;
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
									TotalAlmacenes[DatosPedido.AlmacenPedido].HuecoOcupadoPedidos[k+indice] = true;
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
										TotalAlmacenes[DatosPedido.AlmacenPedido].HuecoOcupadoPedidos[k+indice] = true;
									}
									else if ((DatosPedido.Fecha.Mes+1) >12) {
										DatosPedido.Fecha.Mes = (DatosPedido.Fecha.Mes +1) % 12;
										DatosPedido.Fecha.Anho = DatosPedido.Fecha.Anho+1;
										TotalAlmacenes[DatosPedido.AlmacenPedido].ListaPedidosAlmacen[k+indice] = DatosPedido;         /* Aqui guardamos los nuevos datos de dia, mes y año de DatosPedido en el vector ListaTotalPedidos de cada almacen */
										TotalAlmacenes[DatosPedido.AlmacenPedido].HuecoOcupadoPedidos[k+indice] = true;
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
				printf("\n      Nombre farmaco (Entre 1 y 20 caracteres)? ");
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
				printf("\n      Otro farmaco (S/N)? ");
				scanf("%s", &otrofarmaco);
				if (otrofarmaco == 'S' || otrofarmaco == 's') {
					pedirmasfarmacos = true;
					NuevoFarmaco();
					return;
				}
				else if(otrofarmaco == 'N' || otrofarmaco == 'n') {
					for(int k=1; k<=100 && HuecoEncontradoPedido==false; k++) {
						if(TotalAlmacenes[DatosPedido.AlmacenPedido].HuecoOcupadoPedidos[k] == false) {
							HuecoEncontradoPedido = true;
							TotalAlmacenes[DatosPedido.AlmacenPedido].ListaPedidosAlmacen[k] = DatosPedido;              /* Aqui guardamos los nuevos datos de DatosPedido en el vector ListaTotalPedidos en cada almacen */
							TotalAlmacenes[DatosPedido.AlmacenPedido].HuecoOcupadoPedidos[k] = true;
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
											TotalAlmacenes[DatosPedido.AlmacenPedido].HuecoOcupadoPedidos[k+indice] = true;
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
												TotalAlmacenes[DatosPedido.AlmacenPedido].HuecoOcupadoPedidos[k+indice] = true;
											}
											else if ((DatosPedido.Fecha.Mes+1) >12) {
												DatosPedido.Fecha.Mes = (DatosPedido.Fecha.Mes +1) % 12;
												DatosPedido.Fecha.Anho = DatosPedido.Fecha.Anho+1;
												TotalAlmacenes[DatosPedido.AlmacenPedido].ListaPedidosAlmacen[k+indice] = DatosPedido;         /* Aqui guardamos los nuevos datos de dia, mes y año de DatosPedido en el vector ListaTotalPedidos */
												TotalAlmacenes[DatosPedido.AlmacenPedido].HuecoOcupadoPedidos[k+indice] = true;
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
		printf ("\n\nDato incorrecto para codigo almacen: o valor fuera del rango permitido o el almacen indicado aun no existe\n");
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
			printf("\nPEDIDO ALMACEN - %s", TotalAlmacenes[indice].DescripcionAlmacen);
			printf("\n_______________________________________________________");
			for (int k=1; k<=100; k++) {
				if (FechaLista.Dia == TotalAlmacenes[indice].ListaPedidosAlmacen[k].Fecha.Dia && FechaLista.Mes == TotalAlmacenes[indice].ListaPedidosAlmacen[k].Fecha.Mes && FechaLista.Anho == TotalAlmacenes[indice].ListaPedidosAlmacen[k].Fecha.Anho) {
					for (int i=1; i<=20; i++) {
						if (TotalAlmacenes[indice].ListaPedidosAlmacen[k].RefPedido == TotalAlmacenes[indice].UbicacionesAlmacen[i].Referencia) {
							printf("\n\n      Pedido %d", k);
							printf("\nUbicacion pedido ==> Distancia: %d y Angulo: %d", TotalAlmacenes[indice].UbicacionesAlmacen[i].Distancia, TotalAlmacenes[indice].UbicacionesAlmacen[i].Angulo);
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

void MENU::ProgramarRutas() {
	float Angulo2EnGrados;
	float Angulo1EnGrados;
	float puntox2;
	float puntox1;
	float puntoy2;
	float puntoy1;
	float puntoxCUADRADO;
	float puntoyCUADRADO;
	int distanciaentrepuntos;
	int distanciaentrepuntosanterior;
	int distanciaActual;
	int anguloActual;
	int icliente;
	int iclienteAnterior;
	int codigorutas;
	int refalmacen;
	int numeroruta = 0;
	bool codigocorrectorutas =  false;
	EstadoHuecoPedidos pedidosSObool;
	ListadoPedidos listaPedidosAux;
	TipoPedido pedidoAux;
	int pesototalprog = 0;
	int pesoruta;
	int distanciaruta;
	int r;
	bool inicioRuta;
	bool rutacompleta;

	for(int k=1; k<=101; k++) {
		pedidosSObool[k] = false;
	}
	
	printf("\nProgramar rutas diarias del dron\n\n");
	printf("Codigo almacen? ");
	try {
		scanf("%d", &codigorutas);
		if (codigorutas <1 || codigorutas >10) {
			throw error29;
		}
		for (int k=1; k<=10; k++) {
			if (codigorutas == TotalAlmacenes[k].IdentificadorAlmacen) {
				codigocorrectorutas = true;
			}
		}
		if (codigocorrectorutas == false) {
			throw error29;
		}
	}
	catch (ErroresPrograma error29) {
		printf ("\n\nDato incorrecto para codigo almacen: o valor fuera del rango permitido o el almacen indicado aun no existe\n");
		return;
	}	
	printf("\n      Dia? ");
	try {
		scanf("%d", &FechaRutas.Dia);
		printf("      Mes? ");
		scanf("%d", &FechaRutas.Mes);
		printf("      Año? ");
		scanf("%d", &FechaRutas.Anho);
		switch (FechaRutas.Mes) {
			case 2:
			if (FechaRutas.Anho % 4 == 0 && FechaRutas.Anho % 100 != 0 || FechaRutas.Anho % 400 == 0) { 
				if (FechaRutas.Dia <1 || FechaRutas.Dia >29) {
					throw error30;
				}
			}	
			else {
				if (FechaRutas.Dia <1 || FechaRutas.Dia >28) {
					throw error30;
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
			if (FechaRutas.Dia <1 || FechaRutas.Dia >31) {
				throw error30;
			}
			break;
			case 4:
			case 6:
			case 9:
			case 11:
			if (FechaRutas.Dia <1 || FechaRutas.Dia >30) {
				throw error30;
			}
			break;
			default:
			throw error30;
		}
		if (FechaRutas.Anho < 1600 || FechaRutas.Anho >3000) {
			throw error30;
		}
	}
	catch (ErroresPrograma error30) {
		printf("\n\nFormato de fecha incorrecta\n");
		return;
	}
	// Localizamos el almacen y guardamos los pedidos del día indicado en el vector listaPedidosAux
	for (int indice=1; indice<=10; indice++) {
		r=1;
		if (codigorutas == TotalAlmacenes[indice].IdentificadorAlmacen) {
			refalmacen = TotalAlmacenes[indice].IdentificadorAlmacen;
			for (int k=1; k<=100; k++) {
				if (FechaRutas.Dia == TotalAlmacenes[indice].ListaPedidosAlmacen[k].Fecha.Dia && FechaRutas.Mes == TotalAlmacenes[indice].ListaPedidosAlmacen[k].Fecha.Mes && FechaRutas.Anho == TotalAlmacenes[indice].ListaPedidosAlmacen[k].Fecha.Anho) {
					pedidosSObool[r] = true;
					listaPedidosAux[r] = TotalAlmacenes[indice].ListaPedidosAlmacen[k];
					pesototalprog = pesototalprog + TotalAlmacenes[indice].ListaPedidosAlmacen[k].PesoTotalEnvio;
					r++;
				}
			}
		}
	}

	//Metodo para ordenar
	for (int i = 1; i < (101 - 1); i++) {
		for (int j = i+1; j < 101; j++){
			if(pedidosSObool[i] == true && pedidosSObool[j] == true){
				if (listaPedidosAux[j].PesoTotalEnvio > listaPedidosAux[i].PesoTotalEnvio){
					pedidoAux = listaPedidosAux[j];
					listaPedidosAux[j] = listaPedidosAux[i];
					listaPedidosAux[i] = pedidoAux;
				}
			}
		}
	}

	while(pesototalprog>0) {
		distanciaentrepuntosanterior = 0;
		rutacompleta = false;
		iclienteAnterior = 0;
		inicioRuta = true;
		pesoruta = 0;
		distanciaruta = 0;
		distanciaActual = 0; //inicialmente en origen
		anguloActual = 0; //inicialmente en origen
		numeroruta = numeroruta + 1;
		printf("\n      Ruta %d\n", numeroruta);
		printf("__________________________________________________________________________________________\n");
		printf("Origen a ");

		for(int t = 1; t<=100 && rutacompleta == false; t++){
			if(pedidosSObool[t] == true) {
				Angulo2EnGrados = 0;
				Angulo1EnGrados = 0;
				puntox2 = 0;
				puntox1 = 0;
				puntoy2 = 0;
				puntoy1 = 0;
				puntoxCUADRADO = 0;
				puntoyCUADRADO =0;
				distanciaentrepuntos = 0;
				icliente = 0;
				pesoruta = pesoruta + listaPedidosAux[t].PesoTotalEnvio;

				//Buscamos la distancia al cliente
				for (int i=1; i<=20; i++) {
					if (TotalAlmacenes[refalmacen].HuecoOcupadoAlta[i] == true && listaPedidosAux[t].RefPedido == TotalAlmacenes[refalmacen].UbicacionesAlmacen[i].Referencia) {
						Angulo2EnGrados = ((TotalAlmacenes[refalmacen].UbicacionesAlmacen[i].Angulo/1000) * 180) / pi;
						Angulo1EnGrados = ((anguloActual/1000) * 180) / pi;
						puntox2 = cos(Angulo2EnGrados)*TotalAlmacenes[refalmacen].UbicacionesAlmacen[i].Distancia;
						puntox1 = cos(Angulo1EnGrados)*distanciaActual;
						puntoy2 = sin(Angulo2EnGrados)*TotalAlmacenes[refalmacen].UbicacionesAlmacen[i].Distancia;
						puntoy1 = sin(Angulo1EnGrados)*distanciaActual;
						puntoxCUADRADO= (puntox2 - puntox1) * (puntox2 - puntox1);
						puntoyCUADRADO = (puntoy2 - puntoy1) * (puntoy2 - puntoy1);
						distanciaentrepuntos = sqrt (puntoxCUADRADO + puntoyCUADRADO);
						icliente = i;
						anguloActual = TotalAlmacenes[refalmacen].UbicacionesAlmacen[i].Angulo;
						distanciaActual = TotalAlmacenes[refalmacen].UbicacionesAlmacen[i].Distancia;
						distanciaentrepuntosanterior = distanciaentrepuntos;
						if(inicioRuta == true){
							distanciaruta = distanciaruta + TotalAlmacenes[refalmacen].UbicacionesAlmacen[i].Distancia;
						} 
						else {
							distanciaruta = distanciaruta + distanciaentrepuntos;
						}
					}
				}
				if((pesoruta<=3000) && (distanciaruta<10000) && (inicioRuta == true)){
					inicioRuta = false;
					pedidosSObool[t] = false;
					pesototalprog = pesototalprog - listaPedidosAux[t].PesoTotalEnvio;
					printf("Cliente %-6d", TotalAlmacenes[refalmacen].UbicacionesAlmacen[icliente].Referencia);
					printf("--     Distancia recorrida: %-7d", TotalAlmacenes[refalmacen].UbicacionesAlmacen[icliente].Distancia);
					printf("Angulo: %-7d", TotalAlmacenes[refalmacen].UbicacionesAlmacen[icliente].Angulo);
					printf("Peso: %-4d gramos\n", listaPedidosAux[t].PesoTotalEnvio);
					iclienteAnterior = icliente;
				} 
				else if((pesoruta<=3000) && (distanciaruta<10000) && (inicioRuta == false)){
					pedidosSObool[t] = false;
					pesototalprog = pesototalprog - listaPedidosAux[t].PesoTotalEnvio;
					printf("Cliente %d a Cliente %-3d", TotalAlmacenes[refalmacen].UbicacionesAlmacen[iclienteAnterior].Referencia, TotalAlmacenes[refalmacen].UbicacionesAlmacen[icliente].Referencia);
					printf("--     Distancia recorrida: %-7d", distanciaentrepuntos);
					printf("Angulo: %-7d", TotalAlmacenes[refalmacen].UbicacionesAlmacen[icliente].Angulo);
					printf("Peso: %-4d gramos\n", listaPedidosAux[t].PesoTotalEnvio);
					iclienteAnterior = icliente;
				} 
				else {
					rutacompleta = true;
					printf("Cliente %d a Origen     ", TotalAlmacenes[refalmacen].UbicacionesAlmacen[iclienteAnterior].Referencia);
					printf("--     Distancia recorrida: %-7d", TotalAlmacenes[refalmacen].UbicacionesAlmacen[iclienteAnterior].Distancia);
					distanciaruta = distanciaruta - distanciaentrepuntos;
					distanciaruta = distanciaruta + TotalAlmacenes[refalmacen].UbicacionesAlmacen[iclienteAnterior].Distancia;
					printf("Angulo: %-7d", TotalAlmacenes[refalmacen].UbicacionesAlmacen[iclienteAnterior].Angulo);
					printf("Peso: 0    gramos\n");
				}
			}
		}
		if(rutacompleta==false) {
			printf("Cliente %d a Origen     ", TotalAlmacenes[refalmacen].UbicacionesAlmacen[iclienteAnterior].Referencia);
			printf("--     Distancia recorrida: %-7d", TotalAlmacenes[refalmacen].UbicacionesAlmacen[iclienteAnterior].Distancia);
			distanciaruta = distanciaruta + TotalAlmacenes[refalmacen].UbicacionesAlmacen[iclienteAnterior].Distancia;
			printf("Angulo: %-7d", TotalAlmacenes[refalmacen].UbicacionesAlmacen[iclienteAnterior].Angulo);
			printf("Peso: 0    gramos\n");
		}
		printf("Distancia total de la ruta: %d metros\n", distanciaruta);
	}
}

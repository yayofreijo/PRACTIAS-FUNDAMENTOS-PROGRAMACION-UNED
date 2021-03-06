/**************************************
* NOMBRE: #Alvaro#
* PRIMER APELLIDO: #Freijo#
* SEGUNDO APELLIDO: #Pineiro#
* DNI: #34282248#
* EMAIL: #afreijo5@alumno.uned.es#
***************************************/

/*************************************************************************
* Interfaz del modulo Menu para la practica 5 basada en el dron FarmaDron *
 *************************************************************************/

#pragma once

typedef char TipoIdentificador[21];                                    /* Tipo vector de caracteres con el maximo de caracteres permitidos en identificador y farmaco*/

typedef char TipoCuarentayocho[49];                                    /* Tipo vector char con el maximo de caracteres, 48, de varios datos del almacen */

typedef char TipoProvincia[17];                                        /* Tipo vector char con el maximo de caracteres, 16, posibles para Provincia */ 

typedef char EstadoHuecoAlta[21];                                      /* Tipo vector bool para saber el estado de los huecos que forman el vector de ubicaciones */

typedef struct TipoUbicacion {                                         /* Tipo struct con los datos que forman cada ubicacion */
	int AlmacenPaciente;
	int Referencia;
	TipoIdentificador Identificador;
	int Distancia;
	int Angulo;
};

typedef TipoUbicacion TipoUbicacionesTotal[21];                        /* Tipo vector con el maximo de ubicaciones posibles, que son 20 */

typedef struct TipoFecha {                                             /* Tipo struct de los datos que forman una fecha */
	int Dia;
	int Mes;
	int Anho;
};

typedef bool EstadoHuecoFarmacos[6];                                   /* Tipo vector bool para saber si los huecos del tipo vector ListaFarmacos estan vacios o no */

typedef struct TipoFarmaco {                                           /* Tipo struct con los datos que pertenecen a cada fármaco dentro de un pedido */
	TipoIdentificador Farmaco;
	int PesoFarmaco;
	int NumeroFarmacos;
	int PesoTotalFarmacos;
};

typedef TipoFarmaco ListaFarmacos[6];                                  /* Tipo vector con el numero maximo de farmacos por pedido, que son 5 */

typedef bool EstadoHuecoPedidos[101];                                  /* Tipo vector bool para saber el estado de los huecos que forman el vector de pedidos posibles */

typedef struct TipoPedido {                                            /* Tipo struct con los datos que forman cada pedido */
	int AlmacenPedido;
	int RefPedido;
	int NumeroEnvios;
	TipoFecha Fecha;
	ListaFarmacos DatosFarmaco;
	EstadoHuecoFarmacos HuecoOcupadoFarmacos;
	int PesoTotalEnvio;
	int DiasEntreEnvio;
};

typedef TipoPedido ListadoPedidos[101];                                /* Tipo vector con el maximo de pedidos posibles, que son 100 */

typedef bool EstadoHuecosAlmacen[11];                                  /* Tipo vector bool para saber el estado de los huecos que forman el vector de pedidos posibles */

typedef struct TipoAlmacen {                                           /* Tipo struct con todos los datos a los que tiene acceso un almacen */
	int MaximoPacientes;
	int IdentificadorAlmacen;
	TipoCuarentayocho DireccionAlmacen;
	TipoCuarentayocho MunicipioAlmacen;
	TipoProvincia ProvinciaAlmacen;
	TipoCuarentayocho DescripcionAlmacen;
	EstadoHuecoAlta HuecoOcupadoAlta;
	TipoUbicacionesTotal UbicacionesAlmacen;                       /* Variable para almacenar todas las ubicaciones totales de un almacen */
	EstadoHuecoPedidos HuecoOcupadoPedidos;
	ListadoPedidos ListaPedidosAlmacen;                            /* Variable para almacenar todos los pedidos de un almacen */
};

typedef TipoAlmacen TipoTotalAlmacenes[11];                            /* Tipo vector con el maximo de almacenes posibles, que son 10 */

typedef char TipoCuarentayochoAux[];                                   /* Tipo vector de caracteres abierto auxiliar */

typedef char TipoProvinciaAux[];                                       /* Tipo vector de caracteres abierto auxiliar */

typedef char TipoIdentificadorAux[];                                   /* Tipo vector de caracteres abierto auxiliar */

typedef enum ErroresPrograma {ErrorPrograma};                          /* Tipo enumerado con los posibles errores de los programas */

const int pi = 3.1416;



typedef struct MENU {
	EstadoHuecosAlmacen HuecoOcupadoAlmacen;
	TipoAlmacen Almacen;                                   /* Variable para un solo almacen */
	TipoTotalAlmacenes TotalAlmacenes;                     /* Variable para todos los almacenes */
	TipoPedido DatosPedido;                                /* Variable para un solo pedido */
	TipoFecha FechaLista, FechaRutas;
	TipoIdentificadorAux IdentificadorAux, FarmacoAux;
	TipoCuarentayochoAux DireccionAlmacenAux, MunicipioAlmacenAux, DescripcionAlmacenAux;
	TipoProvinciaAux ProvinciaAlmacenAux;
	ErroresPrograma error1, error2, error3, error4, error5, error6, error7, error8, error9, error10, error11, error12, error13, error14, error15, 
	error16, error17, error18, error19, error20, error21, error22, error23, error24, error25, error26, error27, error28, error29, error30;
	char LetraMenu, i, j, otropedido, otrofarmaco, almacencorrecto;
	bool pedirmasfarmacos, HuecoEncontradoFarmaco, HuecoEncontradoPedido, HuecoEncontradoIdentificador;
	int MaximoFarmacos, MaximoAlmacenes, DiasMesEnvio;

	/* Procedimiento convertir todos los huecos del vector que vamos a utilizar en Alta Nueva vacios en "falso" dentro de un bool */
	void IniciarHuecosAlta();

	/* Procedimiento convertir todos los huecos del vector que vamos a utilizar en Nuevo Farmaco vacios en "falso" dentro de un bool */
	void IniciarHuecosFarmaco();

	/* Procedimiento convertir todos los huecos del vector que vamos a utilizar en Nuevo Pedido vacios en "falso" dentro de un bool */
	void IniciarHuecosPedido();

	/* Procedimiento convertir todos los huecos del vector que vamos a utilizar en Alta Almacen vacios en "falso" dentro de un bool */
	void IniciarHuecosAlmacen();

	/* Menu Principal */
	void ImprimirMenu();

	/* Switch para seleccionar el menu */
	void ElegirLetra();

	/* Opcion Iniciar Gestion */
	void IniciarGestion();

	/* Opcion Alta Almacen */
	void AltaAlmacen();

	/* Opcion Alta Nueva */
	void AltaNueva();

	/* Opcion UbicacionPacientes */
	void UbicacionPacientes();

	/* Opcion Nuevo Pedido */
	void NuevoPedido();

	/* Opcion Nuevo Farmaco */
	void NuevoFarmaco();

	/* Opcion Listar Pedidos */
	void ListaPedidos();

	/* Opcion Programar Rutas */
	void ProgramarRutas();
};

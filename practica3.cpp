/**************************************
* NOMBRE: #Alvaro#
* PRIMER APELLIDO: #Freijo#
* SEGUNDO APELLIDO: #Pineiro#
* DNI: #34282248#
* EMAIL: #afreijo5@alumno.uned.es#
***************************************/

#include <stdio.h>

typedef enum TipoDia {                                                      /* Nuevo tipo de datos con los dias de la semana */
	Lunes, Martes, Miercoles, Jueves, Viernes, Sabado, Domingo
}

/* Funcion para sumar dias de la semana */
TipoDia SumarDias (TipoDia dia, int j) {
	const int DiasTotalesSemana=7
	int auxiliar

	auxiliar=(int(dia)+j) % DiasTotalesSemana
	return TipoDia(auxiliar);
}

/*  Procedimiento para leer la fecha */
void LeerFecha (int &mes, int &anno) {
	printf("¿Mes (1..12)?");
	scanf("%d", (int &mes);
	printf("¿Año (1601..3000)?");
	scanf("%d", &anno);
	printf("\n");
}

/* Funcion para calcular el numero de bisiestos */
int CalcularBisiestos (int mes, int anno) {
	int bisiestos
	bisiestos=0
	if (mes < 2) {
		for (int k=1601; k<anno; k++){
			if ((k%4 == 0) && (k%100 != 0 || k%400 == 0)) {
				bisiestos++
			}
		}
	}	
	if (mes >= 2) {	
		for (int k=1601; k<=anno; k++){
			if ((k%4 == 0) && (k%100 != 0 || k%400 == 0)) {
				bisiestos++
			}
		}		
	}
	return bisiestos		
}

/* Funcion para calcular el numero de años que pasan desde 1601 */
int CalcularAnnos (int anno){
	const int OrigenAnno=1601
	return (anno - Origen Anno)
}

/* Funcion para calcular el incremento de días con respecto al mes de enero */
int CalcularDias (int mes) {
	switch (mes) {
		case 1:
		case 10:
		return 0;
		break;
		case 5:
		return 1;
		break;
		case 8:
		return 2;
		break;
		case 2:
		case 3:
		case 11:
		return 3;
		break;
		case 6:
		return 4;
		break;
		case 9:
		case 12:
		return 5;
		break;
		default:
		return 6;
	}
}
/* Funcion para asignar dias de la semana */
TipoDia DiaDeLaSemana (int &IncrementoDiasTotales) {
	TipoDia UnoDeEnero1601 = Lunes;
	return SumarDias (UnoDeEnero1601, IncrementoDiasTotales);
}

/* Funcion para imprimir la parte superior del calendario */
void SuperiorCalendario (int (&mes), int &anno) {
	if (mes == 1) {
		printf ("ENERO");
	} else if (mes == 2) {
		printf ("FEBRERO");
	} else if (mes == 3) {
		printf ("MARZO");
	} else if (mes == 4) {
		printf ("ABRIL");
	} else if (mes == 5) {
		printf ("MAYO");
	} else if (mes == 6) {
		printf ("JUNIO");
	} else if (mes == 7) {
		printf ("JULIO");
	} else if (mes == 8) {
		printf ("AGOSTO");
	} else if (mes == 9) {
		printf ("SEPTIEMBRE");
	} else if (mes == 10) {
		printf ("OCTUBRE");
	} else if (mes == 11) {
		printf ("NOVIEMBRE");
	} else if (mes == 12) {
		printf ("DICIEMBRE");
	}
	printf ("                  ");
	printf("%d", anno);
	printf("\n");
	printf("===========================\n");
	printf("LU  MA  MI  JU  VI | SA  DO\n");
	printf("===========================\n");
}	

/* Programa principal */
int mes; anno; IncrementoDias; IncrementoAnnos; IncrementoBisiestos; IncrementoDiasTotales;
TipoDia diasemana; dia;

IncrementoDias = CalcularDias (mes);
IncrementoBisiestos = CalcularBisiestos (mes, anno);
IncrementoAnnos = CalcularAnnos (anno);
IncrementoDiasTotales = IncrementoDias + IncrementoAnnos + IncrementoBisiestos;
diasemana = DiaDeLaSemana (IncrementoDiasTotales);

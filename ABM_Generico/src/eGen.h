#ifndef EGEN_H_
#define EGEN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS_CADENAS 30
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

//*** eGen
typedef struct {
	int idGen;
	int isEmpty;
} eGen;
//***

/** INICIO CABECERAS DE FUNCION*/
void eGen_Inicializar(eGen array[], int TAM);
int eGen_ObtenerIndexLibre(eGen array[], int TAM);
int eGen_BuscarPorID(eGen array[], int TAM, int ID);
void eGen_MostrarUno(eGen Gen);
int eGen_MostrarTodos(eGen array[], int TAM);
int eGen_MostrarDadosDeBaja(eGen array[], int TAM);

/** SORT */
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR
int eGen_Sort(eGen array[], int TAM, int criterio);

//ABM
eGen eGen_CargarDatos(void);
eGen eGen_ModificarUno(eGen Gen);
int eGen_Alta(eGen array[], int TAM);
int eGen_Baja(eGen array[], int TAM);
int eGen_Modificacion(eGen array[], int TAM);
/** FIN CABECERAS DE FUNCION*/
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef EProducto_H_
#define EProducto_H_

//*** DEFINE
#define MAX_CHARS_CADENAS 30
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

//*** ESTRUCTURA
typedef struct {
	int idProducto;
	int isEmpty;
} eProducto;
//***

/** INICIO CABECERAS DE FUNCION*/
void eProducto_Inicializar(eProducto array[], int TAM);
int eProducto_ObtenerID(void);
int eProducto_ObtenerIndexLibre(eProducto array[], int TAM);
int eProducto_BuscarPorID(eProducto array[], int TAM, int ID);
void eProducto_MostrarUno(eProducto Producto);
int eProducto_MostrarTodos(eProducto array[], int TAM);
int eProducto_MostrarDadosDeBaja(eProducto array[], int TAM);

/** SORT */
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR
int eProducto_Sort(eProducto array[], int TAM, int criterio);

//ABM
eProducto eProducto_CargarDatos(void);
eProducto eProducto_ModificarUno(eProducto Producto);
int eProducto_Alta(eProducto array[], int TAM);
int eProducto_Baja(eProducto array[], int TAM);
int eProducto_Modificacion(eProducto array[], int TAM);
/** FIN CABECERAS DE FUNCION*/
#endif

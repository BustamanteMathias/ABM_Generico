#include "eProducto.h"

/**IMPORTANTE - SETEAR VALOR INICIAL CON EL PREFERIDO PARA COMENZAR IDs*/
//ID AUTOINCREMENTAL
int Producto_idIncremental = 0;

int eProducto_ObtenerID() {
	//INCREMENTA VARIABLE ESTATICA CADA VEZ QUE SE LLAMA ESTA FUNCION
	return Producto_idIncremental += 1;
}

void eProducto_Inicializar(eProducto array[], int TAM) {
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//SET ESTADO DE "LIBRE"
			array[i].isEmpty = LIBRE;
		}
	}
}

int eProducto_ObtenerIndexLibre(eProducto array[], int TAM) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR EL ESTADO "LIBRE"
			if (array[i].isEmpty == LIBRE) {
				//OBTENGO EL PRIMER INDEX DEL VECTOR "LIBRE" Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

int eProducto_BuscarPorID(eProducto array[], int TAM, int ID) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (array[i].idProducto == ID && array[i].isEmpty == OCUPADO) {
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

void eProducto_MostrarUno(eProducto Producto) {
	//PRINTF DE UN SOLO Producto
	printf("%5d\n", Producto.idProducto);
}

int eProducto_MostrarTodos(eProducto array[], int TAM) {
	int i;
	int rtn = 0;

	//CABECERA
	puts("\n\t> LISTADO Producto");
	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (array[i].isEmpty == OCUPADO) {
				//MUESTRO UN SOLO Producto
				eProducto_MostrarUno(array[i]);
				//CONTADOR DE Producto
				rtn++;
			}
		}
	}

	return rtn;
}

int eProducto_MostrarDadosDeBaja(eProducto array[], int TAM) {
	int i;
	int rtn = 0;

	//CABECERA
	puts("\t> Producto\n");
	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "BAJA"
			if (array[i].isEmpty == BAJA) {
				//MUESTRO UN SOLO Producto
				eProducto_MostrarUno(array[i]);
				//CONTADOR DE Producto
				rtn++;
			}
		}
	}

	return rtn;
}

eProducto eProducto_CargarDatos(void) {
	eProducto auxiliar;
	/** CARGAR DATOS NECESARIOS PARA EL ALTA*/
	/** IMPORTANTE - NO CARGAR ID NI ESTADO - SE HACE EN EL eProducto_Alta() */
	return auxiliar;
}

eProducto eProducto_ModificarUno(eProducto Producto) {
	eProducto auxiliar = Producto;
	/** MODIFICAR DATOS NECESARIOS PARA EL "MODIFICAR" */
	/** IMPORTANTE - MODIFICAR EL AUXILIAR QUE ES LA COPIA DEL ORIGINAL */
	return auxiliar;
}

int eProducto_Alta(eProducto array[], int TAM) {
	int rtn = 0;
	eProducto auxProducto;

	//BUSCO ESPACIO EN ARRAY
	int index = eProducto_ObtenerIndexLibre(array, TAM);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1) {
		//PIDO DATOS - CARGO Producto AUXILIAR
		auxProducto = eProducto_CargarDatos();
		//SETEO ID UNICO - VARIABLE AUTOINCREMENTAL
		auxProducto.idProducto = eProducto_ObtenerID();
		//CAMBIO SU ESTADO A "OCUPADO"
		auxProducto.isEmpty = OCUPADO;

		//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
		array[index] = auxProducto;
		//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
		rtn = 1;

	}

	return rtn;
}

int eProducto_Baja(eProducto array[], int TAM) {
	int rtn = 0;
	int idProducto;
	int index;
	int flag = 0;

	//LISTO TODOS LOS Producto
	if (eProducto_MostrarTodos(array, TAM)) {
		//BANDERA EN 1 SI HAY Producto DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Producto PARA DAR DE BAJA
	if (flag) {
		//PIDO ID A DAR DE BAJA
		idProducto = 1; /**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/

		//BUSCO INDEX POR ID EN ARRAY
		while (eProducto_BuscarPorID(array, TAM, idProducto) == -1) {
			puts("NO EXISTE ID.");
			idProducto = 1; /**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		}

		//OBTENGO INDEX DEL ARRAY DE Producto A DAR DE BAJA
		index = eProducto_BuscarPorID(array, TAM, idProducto);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//BAJA ACEPTADA - CAMBIO ESTADO A "BAJA"
		array[index].isEmpty = BAJA;

		//RETORNO 1 SI SE DIO DE BAJA CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}

int eProducto_Modificacion(eProducto array[], int TAM) {
	int rtn = 0;
	int idProducto;
	int index;
	int flag = 0;
	eProducto auxiliar;

	//LISTO TODOS LOS Producto
	if (eProducto_MostrarTodos(array, TAM)) {
		//BANDERA EN 1 SI HAY Producto DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Producto PARA MODIFICAR
	if (flag) {
		//PIDO ID A MODIFICAR
		idProducto = 1; /**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/

		//BUSCO INDEX POR ID EN ARRAY
		while (eProducto_BuscarPorID(array, TAM, idProducto) == -1) {
			puts("NO EXISTE ID.");
			idProducto = 1; /**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		}

		//OBTENGO INDEX DEL ARRAY DE Producto A MODIFICAR
		index = eProducto_BuscarPorID(array, TAM, idProducto);

		//LLAMO A FUNCION QUE MODIFICA Producto
		auxiliar = eProducto_ModificarUno(array[index]);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//MODIFICACION ACEPTADA
		array[index] = auxiliar;

		//RETORNO 1 SI SE MODIFICO CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}

int eProducto_Sort(eProducto array[], int TAM, int criterio) {
	int rtn = 0;
	int i;
	int j;
	eProducto aux;

	/** EJEMPLO DE SORT CON ID DE Producto */
	/** MODIFICAR "CRITERIO DE ORDENAMIENTO" PARA OTROS CASOS DE ORDENAMIENTO */

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		switch (criterio) {
		case -1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (array[i].isEmpty == OCUPADO
							&& array[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (array[i].idProducto > array[j].idProducto) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
					}
				}
			}
			rtn = 1;
			break;
		case 1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (array[i].isEmpty == OCUPADO
							&& array[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (array[i].idProducto < array[j].idProducto) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
					}
				}
			}
			rtn = 1;
			break;
		default:
			//CRITERIO DE ORDENAMIENTO MAL INGRESADO
			rtn = 0;
			break;
		}
	}
	return rtn;
}


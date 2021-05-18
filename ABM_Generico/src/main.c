#include "eGen.h"
#define TAM_Gen 10000

int main(void) {
	setbuf(stdout, NULL);

	int opc;
	int criterioDeOrdenamiento;

	//CREO ARRAY DE ESTRUCTURA
	eGen Gen[TAM_Gen];

	//INICIALIAZO ARRAY DE ESTRUCTURA
	eGen_Inicializar(Producto, TAM_Gen);

	//BUCLE DE MENU
	do {
		//MENU PRINT
		//Menu();
		printf("INGRESE OPCION: ");
		scanf("%d", &opc);

		//MENU SWITCH
		switch (opc)
		{
		case 0:
			/** PREGUNTAR SI DESEA SALIR */
			opc = 0;
			break;
		case 1:
			//ALTA
			if (eGen_Alta(Gen, TAM_Gen)) {
				puts(" * Gen DADO DE ALTA EXITOSAMENTE");
			} else {
				puts(" * ERROR. SIN ESPACIO PARA ALMACENAR MAS Gen");
			}
			system("pause");
			break;
		case 2:
			//BAJA
			if (eGen_Baja(Gen, TAM_Gen)) {
				puts("\n * BAJA DE Gen EXITOSA");
				eGen_MostrarTodos(Gen, TAM_Gen);
			} else {
				puts("\n * BAJA DE Gen CANCELADA");
			}
			system("pause");
			break;
		case 3:
			//MODIFICACION
			if (eGen_Modificacion(Gen, TAM_Gen)) {
				puts("\n * MODIFICACION DE Gen EXITOSA\n");
				eGen_MostrarTodos(Gen, TAM_Gen);
			} else {
				puts("\n * MODIFICACION DE Gen CANCELADA");
			}
			system("pause");
			break;
		case 4:
			//LISTADO Producto
			if(eGen_MostrarTodos(Gen, TAM_Gen)){
				system("pause");
			}else{
				puts("No hay nada para mostrar pa");
			}

			break;
		case 5:
			//ORDENAR Producto
			criterioDeOrdenamiento = -1; //PEDIR CRITERIO DE ORDENAMIENTO
			eGen_Sort(Gen, TAM_Gen, criterioDeOrdenamiento);
			system("pause");
			break;
		}
	} while (opc != 0);

	puts("\n... FIN PROGRAMA");

	return 0;
}

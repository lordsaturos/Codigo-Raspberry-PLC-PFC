#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <stdint.h>
#include <time.h>
#include "i2c.h"
#include "gpio.h"

//definición de prototipos. Debera ser movido a un descodificar.h
void 	llamarFuncion(int codigo);
int  	decodeMsg(const uint8_t *rxData); 
int		buscarCodigo(const uint8_t *rxData, int i);
//Fin del fichero descodificar.h


/* Esta funcion se encarga de ir leyendo el mensaje para descodificarlo.
 */
 int
 decodeMsg(const uint8_t *rxData) {
	int count = 0, codigo = 0, i;
	printf("Hemos entrado en la funcion decodeMsg\n");
	
	for (i = 0; rxData[i] != '\0'; i++) {
		
		codigo = buscarCodigo(rxData,i);
		
		if(codigo != 0) {
		llamarFuncion(codigo);
		}
	
		//printf("Estamos con el codigo %d, ",codigo);
		
		
	}
		
		
		
	
	
	
	
	return count;
}

/* Esta función se encarga del nº de código que debe ejecutar restando al valor ascii de las letras mayusculas restandole el valor 64. 
De esta forma la letra 'A' se convierte en 1, 'B' se convierte en 2, así de forma sucesiva. */
int 
buscarCodigo(const uint8_t *rxData, int i) {
	int codigo = 0, count;
	
	if (rxData[i] >= 64 && rxData[i] <= 90) {
		//printf("La posición de la letra-codigo es: %d, y correspondende al valor ASCII %d \n",rxData[i]- 64, rxData[i]);
		codigo = rxData[i] -64;
	}
	 
	return codigo;
}

/* Esta funcion llama a la función correspondiente según el código proporcionado como argumento. Llama a una funcion según la tarea a realizar. */
void 
llamarFuncion(int codigo) {
	
	switch (codigo) {
		case 0:
		printf("Error, codigo %d. \n",codigo);
		break;
		
		case 1:
		printf("Status Online. Sin errores.\n");
		break;
		
		case 2:	
		printf("Status Online. Errores presentes\n");
		break;
		
		case 3:	
		printf("Tareas pendientes.\n");
		break;
		
		case 4:	
		printf("Fecha y Hora del Arduino.\n");
		break;
		
		case 5:	
		printf("Error del Arduino.\n");
		break;
		
		case 6:
		printf("Recibir estado de Reles. \n",codigo);
		break;
		
		case 7:	
		printf("Recibido Pulsaciones Teclado.\n");
		break;
		
		case 8:	
		printf("Recibir estado Entradas Digitales. \n");
		break;
		
		case 9:	
		printf("Recibir estado salidas Digitales.\n");
		break;
		
		case 10:	
		printf("Recibir valor entrada analogica Precisión.\n");
		break;
		
		case 11:	
		printf("Recibir estado sensores de Corriente.\n");
		break;
		
		case 12:	
		printf("Recibir estado Buzzer.\n");
		break;
		
		case 13:	
		printf("Recibir estado Modo Debug.\n");
		break;
		
		case 14:	
		printf("Orden no definida.\n");
		break;
		
		case 15:	
		printf("Orden no definida.\n");
		break;
		
		case 16:
		printf("Orden no definida.\n");
		break;
		
		case 17:
		printf("Orden no definida.\n");
		break;
		
		case 18:
		printf("Orden no definida.\n");
		break;
		
		case 19:
		printf("Orden no definida.\n");
		break;
		
		case 20:
		printf("Orden no definida.\n");
		break;
		
		case 21:
		printf("Orden no definida.\n");
		break;
		
		case 22:
		printf("Orden no definida.\n");
		break;
		
		case 23:
		printf("Orden no definida.\n");
		break;
		
		case 24:
		printf("Orden no definida.\n");
		break;
		
		case 25:
		printf("Orden no definida.\n");
		break;
		
		case 26:
		printf("Fin de la orden actual.\n");
		break;
	}
	
	return;
}
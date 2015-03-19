#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <stdint.h>
#include <time.h>
#include "i2c.h"
#include "gpio.h"

/* Esta funcion se encarga de ir leyendo el mensaje para descodificarlo.
 */
 
 int decodeMsg(const uint8_t *rxData) {
	int count = 0, codigo = 0;
	printf("Hemos entrado en la funcion decodeMsg\n");
	
	codigo = buscarCodigo(rxData, );
	llamarFuncion(codigo);
	
	printf("Estamos con el codigo %d, ",codigo);
	
	
	return count;
}

/* Esta función se encarga del nº de código que debe ejecutar restando al valor ascii de las letras mayusculas restandole el valor 64. 
De esta forma la letra 'A' se convierte en 1, 'B' se convierte en 2, así de forma sucesiva. */
int buscarCodigo(const uint8_t *rxData, int i) {
	int codigo = 0, count;
	
	if (rxData[i] >= 64 && rxData[i] <= 90) {
		//printf("La posición de la letra-codigo es: %d, y correspondende al valor ASCII %d \n",rxData[i]- 64, rxData[i]);
		codigo = rxData[i] -64;
	}
	 
	return codigo;
}

/* Esta funcion llama a la función correspondiente según el código proporcionado como argumento. Llama a una funcion según la tarea a realizar. */
void llamarFuncion(int codigo) {
	
	switch (case) {
		case 0:
		printf("Error, codigo %d. \n",codigo);
		break;
		
		case 1()	
		
		break;

	
	}
	
	
	
	
	
	
}
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <stdint.h>
#include <time.h>
#include <stdbool.h> //Include para facilitar el uso de valores Booleanos. Permite definir bool DbgFlag = false/true.

#include "i2c.h"
#include "gpio.h"

//#include "protocolo_i2c.c"


int main() {
	bool DbgFlag = true; //Variable booleana sobre el estado del modo debug
	
	
	uint8_t rxData[100] = {0x00};
	
	const char * string = "1234567890";  //string a enviar
	printf("Hello world...\n");
	enviai2c(string,DbgFlag);
	printf("El string ha sido enviado exitosamente ");
	
	//char *stringentrante;
	//char *stringentrante;
	recibei2c(rxData, 20, DbgFlag);  //Escribimos en el array rxData el mensaje de llegada
	
	printf("Received Data:\n%s\n", rxData); 
	decodeMsg(rxData, DbgFlag);
	return 0;
}
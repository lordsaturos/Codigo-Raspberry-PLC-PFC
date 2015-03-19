#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <stdint.h>
#include <time.h>
#include "i2c.h"
#include "gpio.h"

//#include "protocolo_i2c.c"


int main() {
	uint8_t rxData[100] = {0x00};
	
	const char * string = "1234567890";  //string a enviar
	printf("Hello world...\n");
	enviai2c(string);
	printf("El string ha sido enviado exitosamente ");
	
	//char *stringentrante;
	//char *stringentrante;
	recibei2c(rxData, 20);  //Escribimos en el array rxData el mensaje de llegada
	
	printf("Received Data:\n%s\n", rxData); 
	decodeMsg(rxData);
	return 0;
}
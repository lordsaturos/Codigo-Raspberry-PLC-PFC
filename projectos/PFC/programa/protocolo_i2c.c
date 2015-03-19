#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h> //Include para facilitar el uso de valores Booleanos. Permite definir bool DbgFlag = false/true.


#include "i2c.h"
#include "gpio.h"


//Para incluir en el protocolo_i2c.h
void enviai2c(const char * string, bool DbgFlag);
void recibei2c(uint8_t *rxData, int count, bool DbgFlag);
///// fin del fichero protocolo_i2c.h



/* Esta función envia por i2c el string deseado con una longitud inferior a 100, siendo no recomendable dicha velocidad. Iniciamos
el puerto i2c establecemos la configuración, enviamos el mensaje que hemos obtenido en un argumento en forma de string, esperamos
un segundo y finalmente desconectamos el i2c. */
void 
enviai2c(const char * string, bool DbgFlag){
	
	uint8_t txData[100] = {0x00};  //array de uint8_t a enviar inicializado a cero.
	memcpy(&txData[1], string, strlen(string));

	printf("Comando SendI2C\n");
	gpioSetup();
	gpioI2cSetup();
	gpioI2cSetClock(10000);
	gpioI2cSet7BitSlave(0x04);
	
	gpioI2cWriteData(txData,10);  //Escribir el mensaje en i2c. 
		
	//sleep(1);
	usleep(500000);  //usamos 500ms para detener la linea
	
	gpioI2cCleanup();	

	return;
}



/* Esta función recibe por i2c un string procedente del buffer FIFO del i2c. Se produce el volcado a un puntero proporcionado como
argumento. */
void  
recibei2c(uint8_t *rxData, int count, bool DbgFlag) {
	
	gpioI2cSetup();
	gpioI2cSetClock(10000);
	gpioI2cSet7BitSlave(0x04);
	
	gpioI2cReadData(rxData,20);
	//printf("Received Data:\n%s\n", rxData); //DEBUG de mensajes i2c recibidos.
	
	//sleep(1);
	usleep(500000); //usamos 500ms para detener la linea

	gpioI2cCleanup();
	
	return;
}
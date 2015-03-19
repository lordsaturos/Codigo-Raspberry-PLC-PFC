#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <stdint.h>
#include <time.h>
#include "i2c.h"
#include "gpio.h"

#define WRITE_TIME_NS	1000000000  //    /* 1 s */


//char RTN = "null";
int main() {
		
		
		
		uint8_t txData[100] = {0x00};  //array de uint8_t a enviar inicializado a cero.
		uint8_t rxData[100] = {0x00};  //array de uint8_t a recibir inicializado a cero.
		
		// struct timespec sleepForWriteTime;
		// sleepForWriteTime.tv_sec = 1;
		// sleepForWriteTime.tv_nsec = WRITE_TIME_NS;
		
		const char * string = "1234567890";  //string a enviar
		memcpy(&txData[1], string, strlen(string));

		
		printf("Hello world...\n");
		gpioSetup();
		gpioI2cSetup();
		gpioI2cSetClock(10000);
		gpioI2cSet7BitSlave(0x04);
		//RTN = gpioI2cSet7BitSlave(20);
		//printf(RTN);
		
		gpioI2cWriteData(txData,10);  //Escribir el mensaje en i2c. 
		
		//nanosleep(&sleepForWriteTime, NULL);
		sleep(1);
		
		
		gpioI2cCleanup();
		gpioI2cSetup();
		gpioI2cSetClock(5000);
		// gpioI2cSet7BitSlave(0x04);

		gpioI2cReadData(rxData,20);
		printf("Received Data:\n%s\n", rxData);
		
		
		
		
		return 0;
}
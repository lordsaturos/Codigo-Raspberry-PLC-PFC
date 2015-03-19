#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <stdint.h>
#include <time.h>
#include <stdbool.h> //Include para facilitar el uso de valores Booleanos. Permite definir bool DbgFlag = false/true.


#include "i2c.h"
#include "gpio.h"

//definición de prototipos. Debera ser movido a un descodificar.h
int  	decodeMsg(const uint8_t *rxData, bool DbgFlag); 
int		buscarCodigo(const uint8_t *rxData, uint8_t *rxDeco, int i, bool DbgFlag);
void 	llamarFuncion(int codigo, uint8_t *rxDeco, int i, bool DbgFlag);
//Fin del fichero descodificar.h


/* Esta funcion se encarga de ir leyendo el mensaje para descodificarlo.
 */
 int
 decodeMsg(const uint8_t *rxData, bool DbgFlag) {
	int count = 0, codigo = 0, i, Point_rxData;
	uint8_t rxDeco[100] = {0x00};
	printf("Hemos entrado en la funcion decodeMsg\n");
	
	
	for (i = 0; rxData[i] != '\0'; i++) {
		
		for (Point_rxData = 0; Point_rxData <= 100; Point_rxData++) {
			rxDeco[Point_rxData] = '?' ; //Inicializamos el rxDeco array a todo '?'
		}
		
		codigo = buscarCodigo(rxData,rxDeco,i,DbgFlag); //Obtenemos el codigo y sus parametros.
		
		if(codigo != 0) {
			llamarFuncion(codigo,rxDeco,i,DbgFlag);
		}
		
	}
		
	return count;
}



/* Esta función se encarga del nº de código que debe ejecutar restando al valor ascii de las letras mayusculas restandole el valor 64. 
De esta forma la letra 'A' se convierte en 1, 'B' se convierte en 2, así de forma sucesiva. */
int 
buscarCodigo(const uint8_t *rxData, uint8_t *rxDeco, int i, bool DbgFlag) {
	int codigo = 0, count = 0, pointer;
	//uint8_t rxDeco[100] = {0x00};
	
	
	if (rxData[i] >= 64 && rxData[i] <= 90) {
		//printf("La posición de la letra-codigo es: %d, y correspondende al valor ASCII %d \n",rxData[i]- 64, rxData[i]);
		codigo = rxData[i] -64;
		
		for (pointer = i + 1; (rxData[pointer] >= 48 &&  rxData[pointer] <= 57) || (rxData[pointer] >= 97 &&  rxData[pointer] <= 122); pointer++) {
			rxDeco[count] = rxData[pointer];
			count++;
		}
		rxDeco[count]= '\n';
		
		if(DbgFlag) {
			int pointer_debugData = 0;
			int pointer_debugDeco = 0;
			
			printf("Nuestro rxData es: ");
			printf("%.20s",rxData);
			printf(". Nuestro rxData es: ");
			printf("%.5s",rxDeco);
			printf("\n");
		}
		
		
		
	}
	 
	 //TENGO QUE AÑADIR UN ELEMENTO QUE ME DEVUELVA LOS PARAMETROS DEL CODIGO ACTUAL. UN PUNTERO DONDE VOY A IR GRABANDO LA INFORMACIÓN HASTA LLEGAR AL 
	 // VALOR DE CONTROL Z
	 
	 
	return codigo;
}



/* Esta funcion llama a la función correspondiente según el código proporcionado como argumento. Llama a una funcion según la tarea a realizar. */
void 
llamarFuncion(int codigo, uint8_t *rxDeco, int i, bool DbgFlag) {
	
	switch (codigo) {
		case 0:
		if (DbgFlag)
			printf("Error, codigo %d. \n",codigo);
		//No existe el codigo actual Avisar a la BD
		break;
		
		case 1:
		if (DbgFlag)
			printf("Status Online. Sin errores.\n");
		//rxStatusOk(rxDeco);		//Sin definir.
		break;
		
		case 2:
		if (DbgFlag)		
			printf("Status Online. Errores presentes\n");
		//rxStatusError(rxDeco);		//Comprobar lista de errores, avisar al sistema BD, buzzer
		break;
		
		case 3:	
		if (DbgFlag)
			printf("Tareas pendientes.\n");
		//pedirTareas(rxDeco) //Sin definir
		break;
		
		case 4:	
		if (DbgFlag)
			printf("Fecha y Hora del Arduino.\n");
		//checkTime(rxDeco) //Comprobar hora del arduino
		break;
		
		case 5:	
		if (DbgFlag)
			printf("Error del Arduino.\n");
		//checkError(rxDeco) //sin definir
		break;
		
		case 6:
		if (DbgFlag)
			printf("Recibir estado de Reles. \n",codigo);
		//checkRele(rxDeco) //comprobar estado reles
		break;
		
		case 7:	
		if (DbgFlag)
		printf("Recibido Pulsaciones Teclado.\n");
		//checkTeclado(rxDeco) //sin definir
		break;
		
		case 8:	
		if (DbgFlag)
			printf("Recibir estado Entradas Digitales. \n");
		//checkDigitalInput(rxDeco);
		break;
		
		case 9:
		if (DbgFlag)		
			printf("Recibir estado salidas Digitales.\n");
		//checkDigitalOutput(rxDeco);
		break;
		
		case 10:
		if (DbgFlag)		
			printf("Recibir valor entrada analogica Precisión.\n");
		//checkAnalogInput(rxDeco);
		break;
		
		case 11:	
		if (DbgFlag)
			printf("Recibir estado sensores de Corriente.\n");
		//checkCurrentSensor(rxDeco);
		break;
		
		case 12:	
		if (DbgFlag)
			printf("Recibir estado Buzzer.\n");
		//checkBuzzerStatus(rxDeco);
		break;
		
		case 13:	
		if (DbgFlag)
		printf("Recibir estado Modo Debug.\n");
		//checkArduinoDebug(rxDeco);
		break;
		
		case 14:	
		if (DbgFlag)
		printf("Orden no definida.\n");
		break;
		
		case 15:	
		if (DbgFlag)
		printf("Orden no definida.\n");
		break;
		
		case 16:
		if (DbgFlag)
		printf("Orden no definida.\n");
		break;
		
		case 17:
		if (DbgFlag)
		printf("Orden no definida.\n");
		break;
		
		case 18:
		if (DbgFlag)
		printf("Orden no definida.\n");
		break;
		
		case 19:
		if (DbgFlag)
		printf("Orden no definida.\n");
		break;
		
		case 20:
		if (DbgFlag)
		printf("Orden no definida.\n");
		break;
		
		case 21:
		if (DbgFlag)
		printf("Orden no definida.\n");
		break;
		
		case 22:
		if (DbgFlag)
		printf("Orden no definida.\n");
		break;
		
		case 23:
		if (DbgFlag)
		printf("Orden no definida.\n");
		break;
		
		case 24:
		if (DbgFlag)
		printf("Orden no definida.\n");
		break;
		
		case 25:
		if (DbgFlag)
		printf("Orden no definida.\n");
		break;
		
		case 26:
		if (DbgFlag)
		printf("Fin de la orden actual.\n");
		break;
	}
	
	return;
}
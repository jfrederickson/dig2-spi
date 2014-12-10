/*
 * mcp23017.c
 *
 * Author: James Ritchie III
 * Date Submitted: December 17, 2014
 * Latest Version: 20141207
 */
#include <msp430.h>

#include "mcp23S17.h"
#include "spi.h"

void MCP23S17_SetDir(uint8_t portA, uint8_t portB){

	uint8_t data[4];

	//Set the direction of the pins on the chip by
	//writing the chip address, the chip I/O direction,
	//and the ports
	data[0] = MCP23S17_ADDRESS;
	data[1] = MCP23S17_IODIR;
	data[2] = portA;
	data[3] = portB;

	SPIWrite(&data[0], 4);

}

void MCP23S17_WriteGPIO(uint8_t portA, uint8_t portB){
	uint8_t data[4];

	//Write GPIO by writing chip address, chip GPIO,
	//and the ports
	data[0] = MCP23S17_ADDRESS;
	data[1] = MCP23S17_GPIO;
	data[2] = portA;
	data[3] = portB;

	SPIWrite(&data[0], 4);
}

void MCP23S17_ReadGPIO(uint8_t data[], uint8_t length){
	uint8_t i;
	uint8_t output[4];

	//Read bit is 0x41
	output[0] = MCP23S17_ADDRESS + 1;
	output[1] = MCP23S17_GPIO;

	//Set the values for the outputs
	for(i = 0; i < length; i++){
		output[i+2] = data[i];
	}

	//Read the output
	SPIRead(&output[0],4);

	//Save the output under data array
	for(i = 0; i < length; i++){
		data[i] = output[i+2];
	}
}



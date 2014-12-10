#include <msp430.h> 
#include "msp430_launchpad.h"
#include "spi.h"
#include "mcp23S17.h"

/*
 * main.c
 *
 * Author: James Ritchie III
 * Date Submitted: December 17, 2014
 * Latest Version: 20141207
 *
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

	uint8_t data[2];

	//Initialization for SPI Mode
	SPIInit();

	//Sets PORTA as inputs and PORTB as outputs
	MCP23S17_SetDir(0xFF,0x00);
	MCP23S17_WriteGPIO(0x00, 0x00);

	while(1){
		//Read data from both ports
		MCP23S17_ReadGPIO(&data[0], 2);

		//Write data from PORTA to PORTB
		MCP23S17_WriteGPIO(0x00, data[0]);
	}
}

/*
 * spi.c
 *
 * Author: James Ritchie III
 * Date Submitted: December 17, 2014
 * Latest Version: 20141207
 */

#include <msp430.h>
#include "msp430_launchpad.h"
#include "spi.h"

void SPIInit(void){
	//Hold the module in reset
	UCB0CTL1 |= UCSWRST;

	//Set mode to SPI, set clock polarity, set synchronous mode,
	//set master mode
	UCB0CTL0 |= UCMSB + UCCKPH + UCSYNC + UCMST;

	//Set the clock to SMCLK, UCBR = 11, f_bitclock = 100kbps
	UCB0CTL1 |= UCSSEL_2;
	UCB0BR0 = 11;
	UCB0BR1 = 0;

	//Set GPIO Out Pin for Chip Select
	P1OUT |= PIN0;
	P1DIR |= PIN0;

	//Configure pins for SPI
	P1SEL |= PIN5 + PIN6 + PIN7;
	P1SEL2 |= PIN5 + PIN6 + PIN7;

	//Hold the module in reset
	UCB0CTL1 &= ~UCSWRST;
}

void SPIWrite(uint8_t data[], uint8_t length){
	uint8_t i;

	//Set the select chip
	P1OUT &= ~PIN0;

	//Write data to buffer
	for(i = 0; i < length; i++){
		UCB0TXBUF = data[i];

		//Wait for the data to be transmitted
		while(UCB0STAT & UCBUSY);
	}

	//Reset the select chip
	P1OUT |= PIN0;

}

void SPIRead(uint8_t data[], uint8_t length){
	uint8_t i;

	//Set the select chip
	P1OUT &= ~PIN0;

	//Write data to buffer
	for(i = 0; i < 2; i++){
		UCB0TXBUF = data[i];

		//Wait for the data to be transmitted
		while(UCB0STAT & UCBUSY);
	}

	for(i = 2; i < length; i++){
		//Set the slave to output
		UCB0TXBUF = 0xFF;
		while(UCB0STAT & UCBUSY);

		//Read data transmitted by slave
		data[i] = UCB0RXBUF;
	}

	//Reset the select chip
	P1OUT |= PIN0;

}



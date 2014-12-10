/*
 * mcp23017.h
 *
 * Author: James Ritchie III
 * Date Submitted: December 17, 2014
 * Latest Version: 20141207
 */

#ifndef MCP23S17_H_
#define MCP23S17_H_

#include <stdint.h>

#define MCP23S17_ADDRESS 0x40

//register addresses for non-bank mode:
#define MCP23S17_IODIR 0x00
#define MCP23S17_IPOL 0x02
#define MCP23S17_GPINTEN 0x04
#define MCP23S17_DEFVAL 0x06
#define MCP23S17_IOCON 0x0A
#define MCP23S17_INTCON 0x08
#define MCP23S17_GPPU 0x0c
#define MCP23S17_INTF 0x0E
#define MCP23S17_INTCAP 0x10
#define MCP23S17_GPIO 0x12
#define MCP23S17_OLAT 0x14



void MCP23S17_SetDir(uint8_t portA, uint8_t portB);
void MCP23S17_WriteGPIO(uint8_t portA, uint8_t portB);
void MCP23S17_ReadGPIO(uint8_t data[], uint8_t length);


#endif /* MCP23S17_H_ */

/*
 * spi.h
 *
 * Author: James Ritchie III
 * Date Submitted: December 17, 2014
 * Latest Version: 20141207
 */

#ifndef SPI_H_
#define SPI_H_

#include <stdint.h>
#include <stdbool.h>

void SPIInit(void);
void SPIWrite(uint8_t data[], uint8_t length);
void SPIRead(uint8_t data[], uint8_t length);

#endif /* SPI_H_ */

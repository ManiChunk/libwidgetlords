#ifndef PI_SPI_H
#define PI_SPI_H

#include <stdint.h>

// Define Pins as used by Pi-SPi modules
#define DIR_RS485	25

// SPI module channels
#define SPI_8KO 0
#define SPI_8AI 1
#define SPI_2AO 2
#define SPI_8DI 3
#define SPI_SPARE 4

void pi_spi_init();

#define DEFAULT 0
#define OPTIONAL 1

void pi_spi_2ao_write_single(uint8_t channel, uint16_t counts, uint8_t type);

uint16_t pi_spi_8ai_read_single(uint8_t channel, uint8_t type);

uint8_t pi_spi_8di_read(uint8_t address, uint8_t type);
uint8_t pi_spi_8di_read_single(uint8_t address, uint8_t channel, uint8_t type);
void pi_spi_8di_init(uint8_t address, uint8_t type);

void pi_spi_8ko_write(uint8_t data, uint8_t type);
void pi_spi_8ko_write_single(uint8_t channel, uint8_t data, uint8_t type);

#endif

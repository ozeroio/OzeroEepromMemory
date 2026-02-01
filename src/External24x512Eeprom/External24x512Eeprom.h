/**
 * Ozeroio - External 24x512 eeprom
 *
 * This an implementation of 24x512 eeprom.
 *
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef OZEROIO_EXTERNAL_24X512_EEPROM_H
#define OZEROIO_EXTERNAL_24X512_EEPROM_H 1

#include <ExternalEeprom/ExternalEeprom.h>
#include <stdint.h>

class External24x512Eeprom : public ExternalEeprom {

public:
	/**
	 * Default constructor.
	 * Initializes the 24x512 EEPROM with device address 0.
	 */
	explicit External24x512Eeprom();

	/**
	 * Public constructor with device address.
	 *
	 * @param deviceAddress The I2C device address of the device.
	 */
	explicit External24x512Eeprom(uint8_t deviceAddress);
};

#endif// OZEROIO_EXTERNAL_24X512_EEPROM_H

/**
 * Ozeroio - External 24x128 eeprom
 *
 * This an implementation of 24x128 eeprom.
 *
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef OZEROIO_EXTERNAL_24X128_EEPROM_H
#define OZEROIO_EXTERNAL_24X128_EEPROM_H 1

#include <ExternalEeprom/ExternalEeprom.h>

class External24x128Eeprom : public ExternalEeprom {

public:
	/**
	 * Default constructor.
	 * Initializes the 24x128 EEPROM with device address 0.
	 */
	External24x128Eeprom();

	/**
	 * Public constructor with device address.
	 *
	 * @param deviceAddress The I2C device address of the device.
	 */
	explicit External24x128Eeprom(uint8_t deviceAddress);
};

#endif// OZEROIO_EXTERNAL_24X128_EEPROM_H

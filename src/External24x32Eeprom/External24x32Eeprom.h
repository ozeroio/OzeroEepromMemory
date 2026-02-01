/**
 * Ozeroio - External 24x32 eeprom
 *
 * This an implementation of 24x32 eeprom.
 *
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef OZEROIO_EXTERNAL_24X32_EEPROM_H
#define OZEROIO_EXTERNAL_24X32_EEPROM_H 1

#include <ExternalEeprom/ExternalEeprom.h>

class External24x32Eeprom : public ExternalEeprom {

public:
	/**
	 * Default constructor.
	 * Initializes the 24x32 EEPROM with device address 0.
	 */
	External24x32Eeprom();

	/**
	 * Public constructor with device address.
	 *
	 * @param deviceAddress The I2C device address of the device.
	 */
	explicit External24x32Eeprom(uint8_t deviceAddress);
};

#endif// OZEROIO_EXTERNAL_24X32_EEPROM_H

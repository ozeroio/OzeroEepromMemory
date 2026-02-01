/**
 * Ozero - External 24x64 eeprom
 *
 * This an implementation of 24x64 eeprom.
 *
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef OZERO_MEMORY_EXTERNAL_24X64_EEPROM_H
#define OZERO_MEMORY_EXTERNAL_24X64_EEPROM_H 1

#include <ExternalEeprom/ExternalEeprom.h>

class External24x64Eeprom : public ExternalEeprom {

public:
	/**
	 * Default constructor.
	 * Initializes the 24x64 EEPROM with device address 0.
	 */
	External24x64Eeprom();

	/**
	 * Public constructor with device address.
	 *
	 * @param deviceAddress The I2C device address of the device.
	 */
	explicit External24x64Eeprom(uint8_t deviceAddress);
};

#endif// OZERO_MEMORY_EXTERNAL_24X64_EEPROM_H

/**
 * Ozeroio - External 24x256 eeprom
 *
 * This an implementation of 24x256 eeprom.
 *
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef OZEROIO_EXTERNAL_24X256_EEPROM_H
#define OZEROIO_EXTERNAL_24X256_EEPROM_H 1

#include <ExternalEeprom/ExternalEeprom.h>

class External24x256Eeprom : public ExternalEeprom {

public:
	/**
	 * Public constructor.
	 *
	 * @param deviceAddress The i2c address of the device.
	 */
	External24x256Eeprom();

	/**
	 * Public constructor.
	 *
	 * @param deviceAddress The i2c address of the device.
	 */
	explicit External24x256Eeprom(uint8_t deviceAddress);
};

#endif// OZEROIO_EXTERNAL_24X256_EEPROM_H

/**
 * Ozeroio - External 24cl256 eeprom
 * 
 * This an implementation of 24cl256 eeprom.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef OZEROIO_EXTERNAL_24CL256_EEPROM_H
#define OZEROIO_EXTERNAL_24CL256_EEPROM_H 1

#include <ExternalEeprom/ExternalEeprom.h>

class External24cl256Eeprom : public ExternalEeprom {

public:
	/**
	 * Public constructor.
	 *
	 * @param deviceAddress The i2c address of the device.
	 */
	External24cl256Eeprom();

	/**
	 * Public constructor.
	 *
	 * @param deviceAddress The i2c address of the device.
	 */
	explicit External24cl256Eeprom(uint8_t deviceAddress);
};

#endif /* OZEROIO_EXTERNAL_24CL256_EEPROM_H */

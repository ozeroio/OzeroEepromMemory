/**
 * Ozeroio - External 24cl512 eeprom
 * 
 * This an implementation of 24cl512 eeprom.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef OZEROIO_EXTERNAL_24CL512_EEPROM_H
#define OZEROIO_EXTERNAL_24CL512_EEPROM_H 1

#include <ExternalEeprom/ExternalEeprom.h>
#include <stdint.h>

class External24cl512Eeprom : public ExternalEeprom {

public:
	/**
	 * Public constructor.
	 */
	explicit External24cl512Eeprom();

	/**
	 * Public constructor.
	 *
	 * @param deviceAddress The i2c address of the device.
	 */
	explicit External24cl512Eeprom(uint8_t deviceAddress);
};

#endif /* OZEROIO_EXTERNAL_24CL512_EEPROM_H */

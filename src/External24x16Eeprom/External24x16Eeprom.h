/**
 * Ozeroio - External 24x16 eeprom
 *
 * This an implementation of 24X16 eeprom.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef OZEROIO_EXTERNAL_24X16_EEPROM_H
#define OZEROIO_EXTERNAL_24X16_EEPROM_H 1

#include <ExternalEeprom/ExternalEeprom.h>

class External24x16Eeprom : public ExternalEeprom {
public:
	/**
	 * Public constructor.
	 *
	 * @param device The i2c address of the device.
	 */
	explicit External24x16Eeprom(uint8_t deviceAddress);

	/**
	 * Public constructor.
	 *
	 * NOTE: For devices that support custom i2c pins.
	 *
	 * @param sdaPin          The i2c data pin of the device.
	 * @param sclPin          The i2c clock pin of the device.
	 * @param deviceAddress   The i2c address of the device.
	 */
	External24x16Eeprom(uint8_t sdaPin, uint8_t sclPin, uint8_t deviceAddress);
};

#endif /* OZEROIO_EXTERNAL_24X16_EEPROM_H */

/**
 * Ozeroio - External 24x08 eeprom
 *
 * This an implementation of 24x08 eeprom.
 *
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef OZEROIO_EXTERNAL_24X08_EEPROM_H
#define OZEROIO_EXTERNAL_24X08_EEPROM_H 1

#include <ExternalEeprom/ExternalEeprom.h>

class External24x08Eeprom : public ExternalEeprom {

public:
	/**
	 * Public constructor.
	 *
	 * @param deviceAddress The i2c address of the device.
	 */
	External24x08Eeprom();

	/**
	 * Public constructor.
	 *
	 * @param deviceAddress The i2c address of the device.
	 */
	explicit External24x08Eeprom(uint8_t deviceAddress);

	/**
	 * From datasheet: Following the A2 hardware slave address bit are bits A9 and A8 (bit 2 and bit 1 of the device address
	 * byte), which are the two Most Significant bits of the memory array word address. Refer to Table 6-1 to
	 * review these bit positions.
	 *
	 * @param memoryAddress
	 * @return
	 */
	uint8_t dynamicAddress(int32_t memoryAddress) const override;
};

#endif// OZEROIO_EXTERNAL_24X08_EEPROM_H

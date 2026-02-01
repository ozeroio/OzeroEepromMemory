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
	 * Default constructor.
	 * Initializes the 24x08 EEPROM with device address 0.
	 */
	External24x08Eeprom();

	/**
	 * Public constructor with device address.
	 *
	 * @param deviceAddress The I2C device address of the device.
	 */
	explicit External24x08Eeprom(uint8_t deviceAddress);

	/**
	 * Gets the dynamic I2C address for a given memory address.
	 * From datasheet: Following the A2 hardware slave address bit are bits A9 and A8 (bit 2 and bit 1 of the device address
	 * byte), which are the two Most Significant bits of the memory array word address. Refer to Table 6-1 to
	 * review these bit positions.
	 *
	 * @param memoryAddress The memory address to convert.
	 * @return              The dynamic I2C address for the given memory address.
	 */
	uint8_t dynamicAddress(int32_t memoryAddress) const override;
};

#endif// OZEROIO_EXTERNAL_24X08_EEPROM_H

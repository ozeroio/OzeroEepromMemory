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
	 */
	External24x16Eeprom();

	/**
	 * Public constructor.
	 *
	 * @param device The i2c address of the device.
	 */
	explicit External24x16Eeprom(uint8_t deviceAddress);

	/**
	 * Standard EEPROM Access: The 16K EEPROM device requires an 8-bit device address word following a Start
	 * Condition to enable the chip for a Read or Write operation. The device address word consists of a mandatory
	 * "1010" (Ah) sequence for the first four Most Significant Bits (MSB) as shown in Figure 10. on page 12. This is common
	 * to all the EEPROM devices.
	 * The next three bits used for memory page addressing are the most significant bits of the data word address which follows.
	 *
	 * The AT24C16 does not use the device address pins, which limits the number of devices
	 * on a single bus to one. The A0, A1 and A2 pins are no connects.
	 *
	 * @param memoryAddress
	 * @return
	 */
	uint8_t dynamicAddress(int32_t memoryAddress) const override;
};

#endif// OZEROIO_EXTERNAL_24X16_EEPROM_H

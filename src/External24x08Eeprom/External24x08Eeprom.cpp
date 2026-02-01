/**
 * Ozero - External 24x08 eeprom
 *
 * This an implementation of 24x08 eeprom.
 *
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#include "External24x08Eeprom.h"

External24x08Eeprom::External24x08Eeprom() : External24x08Eeprom(0) {
}

External24x08Eeprom::External24x08Eeprom(uint8_t deviceAddress) : ExternalEeprom(deviceAddress) {
	setDeviceSize(0x400);
	setPageSize(0x10);
	setAddressSize(0x01);
	setWriteCycleTime(5000);
	setAddressBitsSize(8);
}

uint8_t External24x08Eeprom::dynamicAddress(int32_t memoryAddress) const {

	// Set A9 and A8 bits as part of LSB of the device address.
	return (deviceAddress & 0xfc) | ((memoryAddress >> 8) & 0x03);
}
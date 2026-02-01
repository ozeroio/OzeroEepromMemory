/**
 * Ozero - External 24x16 eeprom
 *
 * This an implementation of 24x16 eeprom.
 *
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#include "External24x16Eeprom.h"

External24x16Eeprom::External24x16Eeprom() : External24x16Eeprom(0) {
}

External24x16Eeprom::External24x16Eeprom(uint8_t deviceAddress) : ExternalEeprom(deviceAddress) {
	setDeviceSize(0x800);
	setPageSize(0x10);
	setAddressSize(0x01);
	setWriteCycleTime(5000);
	setAddressBitsSize(8);
}

uint8_t External24x16Eeprom::dynamicAddress(int32_t memoryAddress) const {

	// Set A10, A9 and A8 bits as part of LSB of the device address.
	return (deviceAddress & 0xf8) | ((memoryAddress >> 8) & 0x07);
}
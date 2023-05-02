/**
 * Ozeroio - External eeprom formation.
 *
 * To use > 1 eeprom on the same bus as if they were 1.
 *
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#include "ExternalEepromFormation.h"
#include <Arduino.h>

ExternalEepromFormation::ExternalEepromFormation(ExternalEeprom *eeprom, uint8_t size, uint8_t hardwareAddressMask)
	: ExternalEeprom(eeprom->getAddress()), eeprom(eeprom), size(size), hardwareAddressMask(hardwareAddressMask) {
	setDeviceSize(eeprom->getDeviceSize() * size);
	setPageSize(eeprom->getPageSize());
	setAddressSize(eeprom->getAddressSize());
	setWriteCycleTime(eeprom->getWriteCycleTime());
	setAddressBitsSize(eeprom->getAddressBitsSize());
}

uint8_t ExternalEepromFormation::dynamicAddress(int32_t memoryAddress) const {
	uint8_t eepromDynamicAddress = eeprom->dynamicAddress(memoryAddress);
	return (eepromDynamicAddress & ~hardwareAddressMask) | ((memoryAddress >> getAddressBitsSize()) & hardwareAddressMask);
}

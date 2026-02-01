/**
 * Ozero - External eeprom
 *
 * This is a class that maps a ExternalEeprom from start to end addresses.
 *
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#include "ExternalMappedEeprom.h"
#include <ozero.h>

ExternalMappedEeprom::ExternalMappedEeprom(ExternalEeprom *eeprom, const int32_t startAddress, const int32_t endAddress)
	: ExternalEeprom(0),
	  eeprom(eeprom), startAddress(startAddress), endAddress(endAddress) {
	if (eeprom) {

		// Inherit properties from the underlying eeprom
		setPageSize(eeprom->getPageSize());
		setAddressSize(eeprom->getAddressSize());
		setWriteCycleTime(eeprom->getWriteCycleTime());
		setAddressBitsSize(eeprom->getAddressBitsSize());
	}
}

int32_t ExternalMappedEeprom::writeBlock(const int32_t address, uint8_t *buf, const int32_t len) {
	if (!eeprom || !buf) {
		return -1;
	}
	int32_t remaining = deviceRemainingRoom(address);
	if (remaining <= 0) {
		return 0;
	}
	return eeprom->writeBlock(startAddress + address, buf, ozero_min(len, remaining));
}

int32_t ExternalMappedEeprom::readBlock(const int32_t address, uint8_t *buf, const int32_t len) {
	if (!eeprom || !buf) {
		return -1;
	}
	int32_t remaining = deviceRemainingRoom(address);
	if (remaining <= 0) {
		return 0;
	}
	return eeprom->readBlock(startAddress + address, buf, ozero_min(len, remaining));
}

int32_t ExternalMappedEeprom::pageRemainingRoom(int32_t address) const {
	if (!eeprom) {
		return 0;
	}
	return eeprom->pageRemainingRoom(startAddress + address);
}

int32_t ExternalMappedEeprom::deviceRemainingRoom(int32_t address) const {
	return endAddress - (startAddress + address);
}

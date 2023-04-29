/**
 * Ozeroio - External eeprom
 *
 * This is a class that maps a ExternalEeprom from start to end addresses.
 *
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#include "ExternalMappedEeprom.h"

ExternalMappedEeprom::ExternalMappedEeprom(ExternalEeprom *eemprom, const int32_t startAddress, const int32_t endAddress)
	: ExternalEeprom(OZEROIO_WIRE_NOT_VALID_ADDRESS),
	  eeprom(eemprom), startAddress(startAddress), endAddress(endAddress) {
}

int32_t ExternalMappedEeprom::writeBlock(const int32_t address, uint8_t *buf, const int32_t len) {
	int32_t remaining = deviceRemainingRoom(address);
	if (remaining <= 0) {
		return 0;
	}
	return eeprom->writeBlock(startAddress + address, buf, ozero_min(len, remaining));
}

int32_t ExternalMappedEeprom::readBlock(const int32_t address, uint8_t *buf, const int32_t len) {
	int32_t remaining = deviceRemainingRoom(address);
	if (remaining <= 0) {
		return 0;
	}
	return eeprom->readBlock(startAddress + address, buf, ozero_min(len, remaining));
}

int32_t ExternalMappedEeprom::pageRemainingRoom(int32_t address) const {
	return eeprom->pageRemainingRoom(startAddress + address);
}

int32_t ExternalMappedEeprom::deviceRemainingRoom(int32_t address) const {
	return endAddress - (startAddress + address);
}

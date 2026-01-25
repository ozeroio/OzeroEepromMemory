/**
 * Ozeroio - External Virtual eeprom
 *
 * This an implementation of eeprom using byte array.
 *
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#include "ExternalByteArrayEeprom.h"

ExternalByteArrayEeprom::ExternalByteArrayEeprom(uint8_t *byteArray, int32_t deviceSize)
	: ExternalEeprom(0), byteArray(byteArray) {
	setDeviceSize(deviceSize);

	// Write operations respect page boundaries. Therefore, having page size set is necessary.
	// Since this is a byte array, the whole array can be seen as a 1-page space.
	setPageSize(deviceSize);
	setAddress(0);
}

void ExternalByteArrayEeprom::setByteArray(uint8_t *byteArray) {
	this->byteArray = byteArray;
}

uint8_t *ExternalByteArrayEeprom::getByteArray() {
	return byteArray;
}

int32_t ExternalByteArrayEeprom::writeBlock(int32_t address, uint8_t *buf, int32_t len) {
	if (!byteArray || !buf) {
		return -1;
	}
	address = ozero_max(address, 0);
	len = ozero_min(len, getDeviceSize() - address);
	for (int32_t i = 0; i < len; i++) {
		byteArray[address + i] = buf[i];
	}
	return len;
}

int32_t ExternalByteArrayEeprom::readBlock(int32_t address, uint8_t *buf, int32_t len) {
	if (!byteArray || !buf) {
		return -1;
	}
	address = ozero_max(address, 0);
	len = ozero_min(len, deviceRemainingRoom(address));
	for (int32_t i = 0; i < len; i++) {
		buf[i] = byteArray[address + i];
	}
	return len;
}

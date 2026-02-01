/**
 * Ozero - External eeprom
 *
 * This is an abstract class of external eeprom.
 *
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#include "ExternalEeprom.h"
#include <ozero.h>

ExternalEeprom::ExternalEeprom(const uint8_t deviceAddress)
	: EepromBasedWiredDevice(0x50 | deviceAddress),
	  pageSize(0), deviceSize(0), addressBitsSize(0) {
}

uint16_t ExternalEeprom::write(const int32_t address, uint8_t b) {
	return (uint16_t) writeBlock(address, &b, 1);
}

int32_t ExternalEeprom::writeBytes(int32_t address, uint8_t *buf, const int32_t len) {
	int32_t room, remaining, length, written = 0;
	room = deviceRemainingRoom(address);
	if (room <= 0) {
		return 0;
	}
	remaining = ozero_min(room, len);

	// Eeprom devices are page bounded for writing. Attempting to write beyond the page boundaries in a single
	// operation it causes the data address to roll-over and previous data will be overwritten.
	// The approach is to write blocks not longer than the remaining of the current page.
	while (remaining > 0) {
		room = pageRemainingRoom(address);
		length = ozero_min(room, remaining);
		int32_t w = writeBlock(address, buf, length);
		if (w == 0) {

			// If it returned 0, there is no point in continuing. Return the amount that was written.
			return written;
		} else if (w < 0) {

			// If writeBlock returned a negative value, the value means the error that happened while writing.
			return w;
		}
		address += w;
		buf += w;
		written += w;
		remaining -= w;
	}
	return written;
}

int16_t ExternalEeprom::read(const int32_t address) {
	uint8_t b;
	auto result = (int16_t) readBytes(address, &b, 1);
	if (result < 0) {
		return result;
	}
	return (int16_t) b;
}

int32_t ExternalEeprom::readBytes(const int32_t address, uint8_t *buf, int32_t len) {
	int32_t read = 0;

	len = ozero_min(deviceRemainingRoom(address), len);

	// Read operation is not bounded by pages.
	// Sequential ReadSequential Read is used by readBlock.
	// Even though, due limit on wire library buffer,multiple read ops might be necessary
	// to be performed to retrieve all requested data.
	while (read < len) {
		int32_t r = readBlock(address + read, buf + read, len - read);
		if (r < 0) {
			return r;
		} else if (r == 0) {
			break;
		}
		read += r;
	}
	return read;
}

int32_t ExternalEeprom::setBytes(const int32_t address, const uint8_t b, const int32_t len) {
	int32_t written = 0, remaining = len, size = ozero_min(len, MAX_AUXILIARY_BUFFER_SIZE);
	uint8_t buf[size];

	// Memset
	for (int32_t i = 0; i < size; i++) {
		buf[i] = b;
	}
	while (remaining > 0) {
		int32_t w = writeBytes(address + written, buf, ozero_min(remaining, size));
		if (w < 0) {
			return w;
		} else if (w == 0) {
			break;
		}
		remaining -= w;
		written += w;
	}
	return written;
}

int32_t ExternalEeprom::pageRemainingRoom(const int32_t address) const {
	if (pageSize <= 0) {
		return 0;
	}
	return pageSize - (address % pageSize);
}

int32_t ExternalEeprom::deviceRemainingRoom(const int32_t address) const {
	return deviceSize - address;
}
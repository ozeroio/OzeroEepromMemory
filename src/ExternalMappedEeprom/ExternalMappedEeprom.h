/**
 * Ozeroio - External eeprom
 *
 * This is a class that maps a ExternalEeprom from start to end addresses.
 *
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef OZEROIO_EXTERNAL_MAPPED_EEPROM_H
#define OZEROIO_EXTERNAL_MAPPED_EEPROM_H 1

#include <ExternalEeprom/ExternalEeprom.h>
#include <stdint.h>

class ExternalMappedEeprom : public ExternalEeprom {

	/**
	 * The underlying external eeprom
	 */
	ExternalEeprom *eeprom;

	/**
	 * The start address of the map
	 */
	int32_t startAddress;

	/**
	 * The end address of the map
	 */
	int32_t endAddress;

public:
	/**
	 * Public constructor.
	 *
	 * @param eeprom      The underlying external eeprom to map.
	 * @param startAddress The start address of the mapping.
	 * @param endAddress   The end address of the mapping.
	 */
	ExternalMappedEeprom(ExternalEeprom *eeprom, int32_t startAddress, int32_t endAddress);

	/**
	 * Device size.
	 *
	 * @return
	 */
	int32_t getDeviceSize() const override {
		return endAddress - startAddress;
	}

	/**
	 * Return the remaining room from backed eeprom.
	 *
	 * @param address     The current address.
	 * @return            The number of bytes remaining until the next page boundary in the underlying device.
	 */
	int32_t pageRemainingRoom(int32_t address) const override;

	/**
	 * Return the remaining space on the mapped eeprom.
	 *
	 * @param address     The current address in the mapped region.
	 * @return            The number of bytes remaining from address to end of mapped region.
	 */
	int32_t deviceRemainingRoom(int32_t address) const override;

protected:
	/**
	 * Writes a block of bytes separately by pages to the device.
	 * All bytes during a page write operation must reside on the same page.
	 *
	 * @param address
	 * @param buf
	 * @param len
	 */
	int32_t writeBlock(int32_t address, uint8_t *buf, int32_t len) override;

	/**
	 * Reads a block of bytes from the device.
	 *
	 * @param address
	 * @param buffer
	 * @param len
	 */
	int32_t readBlock(int32_t address, uint8_t *buf, int32_t len) override;
};

#endif// OZEROIO_EXTERNAL_MAPPED_EEPROM_H

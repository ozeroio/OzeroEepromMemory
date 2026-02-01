/**
 * Ozero - External eeprom
 *
 * This is a class that maps a ExternalEeprom from start to end addresses.
 *
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef OZERO_MEMORY_EXTERNAL_MAPPED_EEPROM_H
#define OZERO_MEMORY_EXTERNAL_MAPPED_EEPROM_H 1

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
	 * @return            The size of the mapped region (endAddress - startAddress).
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
	 * @param address     The address in the mapped region where data will be written.
	 * @param buf         The buffer containing data to write.
	 * @param len         The length of data to write.
	 * @return            If >= 0: How many bytes were written.
	 *                    If < 0: Error code.
	 */
	int32_t writeBlock(int32_t address, uint8_t *buf, int32_t len) override;

	/**
	 * Reads a block of bytes from the device.
	 *
	 * @param address     The address in the mapped region where data will be read from.
	 * @param buf         The buffer to store read data.
	 * @param len         The length of data to read.
	 * @return            If >= 0: How many bytes were read.
	 *                    If < 0: Error code.
	 */
	int32_t readBlock(int32_t address, uint8_t *buf, int32_t len) override;
};

#endif// OZERO_MEMORY_EXTERNAL_MAPPED_EEPROM_H

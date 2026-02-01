/**
 * Ozero - External Virtual eeprom
 *
 * This an implementation of eeprom using byte array.
 *
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef OZERO_MEMORY_EXTERNAL_BYTE_ARRAY_EEPROM_H
#define OZERO_MEMORY_EXTERNAL_BYTE_ARRAY_EEPROM_H 1

#include <ExternalEeprom/ExternalEeprom.h>
#include <stdint.h>

class ExternalByteArrayEeprom : public ExternalEeprom {

	/**
	 * The used buffer.
	 */
	uint8_t *byteArray;

public:
	/**
	 * Public constructor.
	 *
	 * @param byteArray   The byte array to use as backing storage.
	 * @param deviceSize  The size of the byte array device.
	 */
	ExternalByteArrayEeprom(uint8_t *byteArray, int32_t deviceSize);

	/**
	 * Set byte array.
	 *
	 * @param byteArray   The byte array to set as backing storage.
	 */
	void setByteArray(uint8_t *byteArray);

	/**
	 * Get byte array.
	 *
	 * @return            The backing byte array.
	 */
	uint8_t *getByteArray();


protected:
	/**
	 * Writes a block of bytes separately by pages to the device.
	 * All bytes during a page write operation must reside on the same page.
	 *
	 * @param address     The address where the data will be written.
	 * @param buf         The buffer containing data to write.
	 * @param len         The length of data to write.
	 * @return            If >= 0: How many bytes were written.
	 *                    If < 0: Error code.
	 */
	int32_t writeBlock(int32_t address, uint8_t *buf, int32_t len) override;

	/**
	 * Reads a block of bytes from the device.
	 *
	 * @param address     The address where the data will be read from.
	 * @param buf         The buffer to store read data.
	 * @param len         The length of data to read.
	 * @return            If >= 0: How many bytes were read.
	 *                    If < 0: Error code.
	 */
	int32_t readBlock(int32_t address, uint8_t *buf, int32_t len) override;
};

#endif// OZERO_MEMORY_EXTERNAL_BYTE_ARRAY_EEPROM_H

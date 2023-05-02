/**
 * Ozeroio - External Virtual eeprom
 *
 * This an implementation of eeprom using byte array.
 *
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef OZEROIO_EXTERNAL_BYTE_ARRAY_EEPROM_H
#define OZEROIO_EXTERNAL_BYTE_ARRAY_EEPROM_H 1

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
	 * @param device
	 */
	ExternalByteArrayEeprom(uint8_t *byteArray, int32_t deviceSize);

	/**
	 * Set byte array.
	 *
	 * @param byteArray
	 */
	void setByteArray(uint8_t *byteArray);

	/**
	 * Get byte array.
	 *
	 * @return
	 */
	uint8_t *getByteArray();



protected:
	/**
	 * Writes a block of bytes separately by pages to the device.
	 * All bytes during a page write operation must reside on the same page.
	 *
	 * @param address
	 * @param buffer
	 * @param len
	 */
	int32_t writeBlock(int32_t address, uint8_t *buf, int32_t len) override;

	/**
	 * Reads a block of bytes from the device.
	 *
	 * @param address
	 * @param buf
	 * @param len
	 */
	int32_t readBlock(int32_t address, uint8_t *buf, int32_t len) override;
};

#endif// OZEROIO_EXTERNAL_BYTE_ARRAY_EEPROM_H

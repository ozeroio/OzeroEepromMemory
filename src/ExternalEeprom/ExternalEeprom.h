/**
 * Ozeroio - External eeprom
 *
 * This is an abstract class of external eeprom.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef OZEROIO_EXTERNAL_EEPROM_H
#define OZEROIO_EXTERNAL_EEPROM_H 1

#include <EepromBasedWiredDevice/EepromBasedWiredDevice.h>
#include <stdint.h>

class ExternalEeprom : public EepromBasedWiredDevice {

    // Max auxiliary buffer size is 32.
    static const int32_t MAX_AUXILIARY_BUFFER_SIZE = 0x20;

    /**
     * The size of the device page.
     */
    int32_t pageSize;

    /**
     * The size of the device.
     */
    int32_t deviceSize;

    /**
     * The number of bits used in address byte(s) to effectively address data (usually the log2 of the deviceSize - except
     * of device that use the hard address (A2, A1 and A0) to address data).
     */
    uint8_t addressBitsSize;

public:

    /**
     * Writes a uint8_t at the address into the device.
     *
     * @param address     The address where the data will be written.
     * @param b           The data to be written.
     */
    virtual uint16_t write(int32_t address, uint8_t b);

    /**
     * Writes a buffer of bytes at the address into the device.
     *
     * @param address     The address where the data will be written.
     * @param buffer      The data to be written.
     * @param len         The amount of data to be written.
     * @return            If >= 0: How many bytes were written.
     *                    If < 0: Error code. See underling implementation.
     */
    virtual int32_t writeBytes(int32_t address, uint8_t *buf, int32_t len);

    /**
     * Reads a byte from the device.
     *
     * @param address
     * @return            If >= 0: The read byte.
     *                    If < 0: Error code. See underling implementation.
     */
    virtual int16_t read(int32_t address);

    /**
     * Reads a buffer with len bytes from the device.
     *
     * @param address     The address where the data will be read.
     * @param buffer      The data to be read.
     * @param len         The amount of data to be read.
     * @return            If >= 0: How many bytes were read.
     *                    If < 0: Error code. See underling implementation.
     */
    virtual int32_t readBytes(int32_t address, uint8_t *buf, int32_t len);

    /**
     * Writes len bytes at the address with data.
     *
     * @param address     The address where the data will be set.
     * @param buffer      The data to be set.
     * @param len         The amount of data to be set.
     * @return            If >= 0: How many bytes were set.
     *                    If < 0: Error code. See underling implementation.
     */
    virtual int32_t setBytes(int32_t address, uint8_t b, int32_t len);

    /**
     * Gets the page size of the device.
     *
     * @return
     */
    int32_t getPageSize() const {
        return pageSize;
    }

    /**
     * Sets the page size of the device.
     *
     * @param pageSize
     */
    void setPageSize(const int32_t pageSize) {
        this->pageSize = pageSize;
    }

	/**
     * Gets the total size of the device.
     *
     * @return
	 */
	virtual int32_t getDeviceSize() const {
		return deviceSize;
	}

	/**
     * Sets the size of the device.
     *
     * @param deviceSize
	 */
	void setDeviceSize(const int32_t deviceSize) {
		this->deviceSize = deviceSize;
	}

	/**
     * Gets the number of bits used to address data.
     *
     * @return
	 */
	virtual uint8_t getAddressBitsSize() const {
		return addressBitsSize;
	}

	/**
     * Sets the number of bits used to address data.
     *
     * @param addressBitsSize
	 */
	void setAddressBitsSize(const uint8_t addressBitsSize) {
		this->addressBitsSize = addressBitsSize;
	}

    /**
     * Determines the length until first multiple of 'pageSize' of an address
     * so writing always occurs up to 'pageSize' uint8_t boundaries.
     *
     * @param address
     * @return
     */
    virtual int32_t pageRemainingRoom(int32_t address) const;

    /**
     * Determines the length until end of device.
     *
     * @param address
     * @return
     */
	virtual int32_t deviceRemainingRoom(int32_t address) const;

protected:

    /**
     * Protected constructor.
     *
     * @param deviceAddress   The i2c address of the device.
     */
    explicit ExternalEeprom(uint8_t deviceAddress);
};

#endif// OZEROIO_EXTERNAL_EEPROM_H

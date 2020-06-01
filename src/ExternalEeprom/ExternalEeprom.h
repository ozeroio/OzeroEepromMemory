/**
 * Ozeroio - External eeprom
 *
 * This is an abstract class of external eeprom.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __OZEROIO_EXTERNAL_EEPROM_H__
#define __OZEROIO_EXTERNAL_EEPROM_H__ 1

#define max(x, y) (((x) > (y)) ? (x) : (y))
#define min(x, y) (((x) < (y)) ? (x) : (y))

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

public:

  /**
   * Virtual destructor.
   */
  virtual ~ExternalEeprom() {
  }

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
  int32_t getPageSize() {
    return pageSize;
  }

  /**
   * Sets the page size of the device.
   *
   * @param pageSize
   */
  void setPageSize(int32_t pageSize) {
    this->pageSize = pageSize;
  }

  /**
   * Gets the total size of the device.
   *
   * @return
   */
  int32_t getDeviceSize() {
    return deviceSize;
  }

  /**
   * Sets the size of the device.
   *
   * @param deviceSize
   */
  void setDeviceSize(int32_t deviceSize) {
    this->deviceSize = deviceSize;
  }

  /**
   * Determines the length until first multiple of 'pageSize' of an address
   * so writing always occurs up to 'pageSize' uint8_t boundaries.
   *
   * @param address
   * @return
   */
  int32_t pageRemainingRoom(int32_t address);

  /**
   * Determines the length until end of device.
   *
   * @param address
   * @return
   */
  int32_t deviceRemainingRoom(int32_t address);

protected:

  /**
   * Protected constructor.
   *
   * @param deviceAddress   The i2c address of the device.
   */
  ExternalEeprom(uint8_t deviceAddress);

  /**
   * Protected constructor.
   *
   * NOTE: For devices that support custom i2c pins.
   *
   * @param sdaPin          The i2c data pin of the device.
   * @param sclPin          The i2c clock pin of the device.
   * @param deviceAddress   The i2c address of the device.
   */
  ExternalEeprom(uint8_t sdaPin, uint8_t sclPin, uint8_t deviceAddress);
};

#endif /* __OZEROIO_EXTERNAL_EEPROM_H__ */

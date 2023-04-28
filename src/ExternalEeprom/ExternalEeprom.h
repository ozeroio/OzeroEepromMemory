/**
 * Ozeroio - External eeprom
 *
 * This is an abstract class of external eeprom.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef OZEROIO_EXTERNAL_EEPROM_H
#define OZEROIO_EXTERNAL_EEPROM_H 1

#ifndef ozero_max
#define ozero_max(x, y) (((x) > (y)) ? (x) : (y))
#endif

#ifndef ozero_min
#define ozero_min(x, y) (((x) < (y)) ? (x) : (y))
#endif

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
  ~ExternalEeprom() override = default;

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
  int32_t getDeviceSize() const {
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
  ExternalEeprom(const uint8_t deviceAddress);

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

#endif /* OZEROIO_EXTERNAL_EEPROM_H */

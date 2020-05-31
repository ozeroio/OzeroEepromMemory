/**
 * Ozeroio - External Virtual eeprom
 *
 * This an implementation of VIRTUAL eeprom.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __OZEROIO_EXTERNAL_BYTE_ARRAY_EEPROM_H__
#define __OZEROIO_EXTERNAL_BYTE_ARRAY_EEPROM_H__ 1

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

protected:

  /**
   * Writes a block of bytes separately by pages to the device.
   * All bytes during a page write operation must reside on the same page.
   *
   * @param address
   * @param buffer
   * @param len
   */
  virtual int32_t writeBlock(int32_t address, uint8_t *buf, int32_t len);

  /**
   * Reads a block of bytes from the device.
   *
   * @param address
   * @param buf
   * @param len
   */
  virtual int32_t readBlock(int32_t address, uint8_t *buf, int32_t len);
};

#endif /* __OZEROIO_EXTERNAL_BYTE_ARRAY_EEPROM_H__ */

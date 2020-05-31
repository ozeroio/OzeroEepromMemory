/**
 * Ozeroio - External eeprom
 * 
 * This is an abstract class of external eeprom.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __OZEROIO_EXTERNAL_MAPPED_EEPROM_H__
#define __OZEROIO_EXTERNAL_MAPPED_EEPROM_H__ 1

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
   * @param eemprom
   * @param startAddress
   * @param endAddress
   */
  ExternalMappedEeprom(ExternalEeprom *eemprom, int32_t startAddress, int32_t endAddress);

  /**
   * Device size.
   *
   * @return
   */
  int32_t getDeviceSize() {
    return (endAddress - startAddress);
  }

protected:

  /**
   * Writes a block of bytes separately by pages to the device.
   * All bytes during a page write operation must reside on the same page.
   *
   * @param address
   * @param buf
   * @param len
   */
  virtual int32_t writeBlock(int32_t address, uint8_t *buf, int32_t len);

  /**
   * Reads a block of bytes from the device.
   *
   * @param address
   * @param buffer
   * @param len
   */
  virtual int32_t readBlock(int32_t address, uint8_t *buf, int32_t len);
};

#endif /* __OZEROIO_EXTERNAL_MAPPED_EEPROM_H__ */

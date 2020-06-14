/**
 * Ozeroio - External 24cl512 eeprom
 * 
 * This an implementation of 24cl512 eeprom.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __OZEROIO_EXTERNAL_24CL512_EEPROM_H__
#define __OZEROIO_EXTERNAL_24CL512_EEPROM_H__ 1

#include <ExternalEeprom/ExternalEeprom.h>

class External24cl512Eeprom : public ExternalEeprom {

public:

  /**
   * Public constructor.
   *
   * @param deviceAddress The i2c address of the device.
   */
  External24cl512Eeprom(uint8_t deviceAddress);

  /**
   * Public constructor.
   *
   * NOTE: For devices that support custom i2c pins.
   *
   * @param sdaPin          The i2c data pin of the device.
   * @param sclPin          The i2c clock pin of the device.
   * @param deviceAddress   The i2c address of the device.
   */
  External24cl512Eeprom(uint8_t sdaPin, uint8_t sclPin, uint8_t deviceAddress);
};

#endif /* __OZEROIO_EXTERNAL_24CL512_EEPROM_H__ */

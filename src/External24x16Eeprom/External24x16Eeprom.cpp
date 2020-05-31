/**
 * Ozeroio - External 24x16 eeprom
 *
 * This an implementation of 24x16 eeprom.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#include "External24x16Eeprom.h"

External24x16Eeprom::External24x16Eeprom(uint8_t deviceAddress) :
    ExternalEeprom(deviceAddress) {
  setDeviceSize(0x7ff);
  setPageSize(0x20);
  setAddressSize(0x01);
  setWriteCycleTime(5);
}

External24x16Eeprom::External24x16Eeprom(uint8_t sdaPin, uint8_t sclPin, uint8_t deviceAddress) :
    ExternalEeprom(sdaPin, sclPin, deviceAddress) {
  setDeviceSize(0x7ff);
  setPageSize(0x20);
  setAddressSize(0x01);
  setWriteCycleTime(5);
}

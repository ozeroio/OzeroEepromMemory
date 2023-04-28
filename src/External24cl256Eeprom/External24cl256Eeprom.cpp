/**
 * Ozeroio - External 24cl256 eeprom
 * 
 * This an implementation of 24cl256 eeprom.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#include "External24cl256Eeprom.h"

External24cl256Eeprom::External24cl256Eeprom(uint8_t deviceAddress) :
    ExternalEeprom(deviceAddress) {
  setDeviceSize(0x7fff);
  setPageSize(0x40);
  setAddressSize(0x02);
  setWriteCycleTime(5000);
}

External24cl256Eeprom::External24cl256Eeprom(uint8_t sdaPin, uint8_t sclPin, uint8_t deviceAddress) :
    ExternalEeprom(sdaPin, sclPin, deviceAddress) {
  setDeviceSize(0x7fff);
  setPageSize(0x40);
  setAddressSize(0x02);
  setWriteCycleTime(5000);
}


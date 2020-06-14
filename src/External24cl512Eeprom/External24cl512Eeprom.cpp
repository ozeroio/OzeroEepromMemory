/**
 * Ozeroio - External 24cl512 eeprom
 * 
 * This an implementation of 24cl512 eeprom.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#include "External24cl512Eeprom.h"

External24cl512Eeprom::External24cl512Eeprom(uint8_t deviceAddress) :
    ExternalEeprom(deviceAddress) {
  setDeviceSize(0xfffe);
  setPageSize(0x80);
  setAddressSize(0x02);
  setWriteCycleTime(5);
}

External24cl512Eeprom::External24cl512Eeprom(uint8_t sdaPin, uint8_t sclPin, uint8_t deviceAddress) :
    ExternalEeprom(sdaPin, sclPin, deviceAddress) {
  setDeviceSize(0xfffe);
  setPageSize(0x80);
  setAddressSize(0x02);
  setWriteCycleTime(5);
}


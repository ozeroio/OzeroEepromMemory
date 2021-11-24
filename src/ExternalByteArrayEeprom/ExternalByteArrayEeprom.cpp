/**
 * Ozeroio - External Virtual eeprom
 *
 * This an implementation of Virtual eeprom.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#include "ExternalByteArrayEeprom.h"

ExternalByteArrayEeprom::ExternalByteArrayEeprom(uint8_t *byteArray, int32_t deviceSize): ExternalEeprom(0), byteArray(byteArray) {
    setDeviceSize(deviceSize);
}

// TODO: missing some boundaries check.
int32_t ExternalByteArrayEeprom::writeBlock(int32_t address, uint8_t *buf, int32_t len) {
  for (int i = 0; i < len; i++) {
    byteArray[address + i] = buf[i];
  }
  return len;
}

// TODO: missing some boundaries check.
int32_t ExternalByteArrayEeprom::readBlock(int32_t address, uint8_t *buf, int32_t len) {
  for (int i = 0; i < len; i++) {
    buf[i] = byteArray[address + i];
  }
  return len;
}

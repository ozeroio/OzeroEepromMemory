/**
 * Ozeroio - External Virtual eeprom
 *
 * This an implementation of Virtual eeprom.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#include "ExternalByteArrayEeprom.h"

ExternalByteArrayEeprom::ExternalByteArrayEeprom(uint8_t *byteArray, int32_t deviceSize)
    : ExternalEeprom(0), byteArray(byteArray) {
  setDeviceSize(deviceSize);

  // Write operations respect page boundaries. Therefore, having page size set is necessary.
  // Since this is a byte array, the whole array can be seen as a 1-page space.
  setPageSize(deviceSize);
}

int32_t ExternalByteArrayEeprom::writeBlock(int32_t address, uint8_t *buf, int32_t len) {
  address = max(address, 0);
  len = min(len, getDeviceSize() - address);
  for (int i = 0; i < len; i++) {
    byteArray[address + i] = buf[i];
  }
  return len;
}

// TODO: missing some boundaries check.
int32_t ExternalByteArrayEeprom::readBlock(int32_t address, uint8_t *buf, int32_t len) {
  address = max(address, 0);
  len = min(len, getDeviceSize() - address);
  for (int i = 0; i < len; i++) {
    buf[i] = byteArray[address + i];
  }
  return len;
}

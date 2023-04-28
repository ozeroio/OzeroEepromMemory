/**
 * Ozeroio - External eeprom
 * 
 * This is an abstract class of external eeprom.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#include "ExternalMappedEeprom.h"
#include <Arduino.h>

ExternalMappedEeprom::ExternalMappedEeprom(ExternalEeprom *eemprom, const int32_t startAddress, const int32_t endAddress)
    : ExternalEeprom(eemprom->getDeviceAddress(), eemprom->getPageSize(),
                     eemprom->getDeviceSize()), eeprom(eemprom), startAddress(startAddress),
      endAddress(endAddress) {
}

int32_t ExternalMappedEeprom::writeBlock(const int32_t address, uint8_t *buf, int32_t len) {
  int32_t mappedAddress = (address + startAddress);
  if (mappedAddress >= endAddress) {
    return 0;
  }
  int32_t available = (endAddress - mappedAddress);
  len = _min(len, available);
  return eeprom->writeBlock(mappedAddress, buf, len);
}

int32_t ExternalMappedEeprom::readBlock(const int32_t address, uint8_t *buf, const int32_t len) {
  int32_t mappedAddress = (address + startAddress);
  if (mappedAddress >= endAddress) {
    return 0;
  }
  int32_t available = (endAddress - mappedAddress);
  return eeprom->readBlock(mappedAddress, buf, _min(available, len));
}

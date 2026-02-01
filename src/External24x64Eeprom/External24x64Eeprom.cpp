/**
 * Ozero - External 24x64 eeprom
 *
 * This an implementation of 24x64 eeprom.
 *
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#include "External24x64Eeprom.h"

External24x64Eeprom::External24x64Eeprom() : External24x64Eeprom(0) {
}

External24x64Eeprom::External24x64Eeprom(uint8_t deviceAddress) : ExternalEeprom(deviceAddress) {
	setDeviceSize(0x2000);
	setPageSize(0x20);
	setAddressSize(0x02);
	setWriteCycleTime(5000);
	setAddressBitsSize(13);
}
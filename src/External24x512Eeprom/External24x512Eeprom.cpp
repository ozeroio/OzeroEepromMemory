/**
 * Ozeroio - External 24x512 eeprom
 *
 * This an implementation of 24x512 eeprom.
 *
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#include "External24x512Eeprom.h"

External24x512Eeprom::External24x512Eeprom() : External24x512Eeprom(0) {
}

External24x512Eeprom::External24x512Eeprom(uint8_t deviceAddress) : ExternalEeprom(deviceAddress) {
	setDeviceSize(0x10000);
	setPageSize(0x80);
	setAddressSize(0x02);
	setWriteCycleTime(5000);
	setAddressBitsSize(16);
}
/**
 * Ozeroio - External 24x256 eeprom
 *
 * This an implementation of 24x256 eeprom.
 *
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#include "External24x256Eeprom.h"

External24x256Eeprom::External24x256Eeprom() : External24x256Eeprom(0) {
}

External24x256Eeprom::External24x256Eeprom(uint8_t deviceAddress) : ExternalEeprom(deviceAddress) {
	setDeviceSize(0x8000);
	setPageSize(0x40);
	setAddressSize(0x02);
	setWriteCycleTime(5000);
	setAddressBitsSize(15);
}
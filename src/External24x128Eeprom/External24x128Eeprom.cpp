/**
 * Ozeroio - External 24x128 eeprom
 *
 * This an implementation of 24x128 eeprom.
 *
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#include "External24x128Eeprom.h"

External24x128Eeprom::External24x128Eeprom() : External24x128Eeprom(0) {
}

External24x128Eeprom::External24x128Eeprom(uint8_t deviceAddress) : ExternalEeprom(deviceAddress) {
	setDeviceSize(0x4000);
	setPageSize(0x40);
	setAddressSize(0x02);
	setWriteCycleTime(5000);
	setAddressBitsSize(14);
}
/**
 * Ozeroio - External 24x02 eeprom
 *
 * This an implementation of 24x02 eeprom.
 *
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#include "External24x02Eeprom.h"

External24x02Eeprom::External24x02Eeprom() : External24x02Eeprom(0) {
}

External24x02Eeprom::External24x02Eeprom(uint8_t deviceAddress) : ExternalEeprom(deviceAddress) {
	setDeviceSize(0x100);
	setPageSize(0x10);
	setAddressSize(0x1);
	setWriteCycleTime(1500);
	setAddressBitsSize(8);
}
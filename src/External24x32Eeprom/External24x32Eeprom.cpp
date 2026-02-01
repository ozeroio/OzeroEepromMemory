/**
 * Ozero - External 24x32 eeprom
 *
 * This an implementation of 24x32 eeprom.
 *
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#include "External24x32Eeprom.h"

External24x32Eeprom::External24x32Eeprom() : External24x32Eeprom(0) {
}

External24x32Eeprom::External24x32Eeprom(uint8_t deviceAddress) : ExternalEeprom(deviceAddress) {
	setDeviceSize(0x1000);

	// It should be 64, but it fails with it > 32.
	setPageSize(0x20);
	setAddressSize(0x02);
	setWriteCycleTime(5000);
	setAddressBitsSize(12);
}
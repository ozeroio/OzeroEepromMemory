/**
 * Ozeroio - External eeprom formation.
 *
 * To use > 1 eeprom on the same bus as if they were 1.
 *
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef OZEROIO_EXTERNAL_EEPROM_FORMATION_H
#define OZEROIO_EXTERNAL_EEPROM_FORMATION_H 1

#include <ExternalEeprom/ExternalEeprom.h>
#include <stdint.h>

class ExternalEepromFormation : public ExternalEeprom {

	ExternalEeprom *eeprom;

	uint8_t size;

	// Which part of the address should be multiplexed. A2, A1 and A0 are candidates.
	uint8_t hardwareAddressMask;

public:
	ExternalEepromFormation(ExternalEeprom *eeprom, uint8_t size, uint8_t hardwareAddressMask);


	uint8_t dynamicAddress(int32_t memoryAddress) const override;
};

#endif// OZEROIO_EXTERNAL_EEPROM_FORMATION_H

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

/**
 * What is a EepromFormation?
 */
class ExternalEepromFormation : public ExternalEeprom {

	ExternalEeprom *eeprom;

	uint8_t size;

	// Which part of the address should be multiplexed. A2, A1 and A0 are candidates.
	uint8_t hardwareAddressMask;

public:
	/**
	 * Public constructor.
	 *
	 * @param eeprom             The underlying external eeprom to use.
	 * @param size               The number of eeproms in the formation.
	 * @param hardwareAddressMask The mask indicating which hardware address bits to use for multiplexing.
	 */
	ExternalEepromFormation(ExternalEeprom *eeprom, uint8_t size, uint8_t hardwareAddressMask);

	/**
	 * Gets the dynamic address for a given memory address.
	 *
	 * @param memoryAddress The memory address to convert.
	 * @return              The dynamic I2C address for the given memory address.
	 */
	uint8_t dynamicAddress(int32_t memoryAddress) const override;
};

#endif// OZEROIO_EXTERNAL_EEPROM_FORMATION_H

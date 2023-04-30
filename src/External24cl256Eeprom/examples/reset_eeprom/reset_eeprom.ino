#include <EepromBasedWiredDevice.h>
#include <External24cl256Eeprom.h>
#include <ExternalEeprom.h>
#include <Wire.h>
#include <WiredDevice.h>

External24cl256Eeprom eeprom = External24cl256Eeprom(0x50);

void setup() {
	Serial.begin(9600);
	Wire.begin();
	Serial.println("initialized");
	for (int32_t i = 0; i < eeprom.getDeviceSize(); i++) {
		eeprom.write(i, 0x00);
	}
}

void loop() {
}

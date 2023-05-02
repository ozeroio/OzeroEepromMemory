#include <Arduino.h>
#include <External24x08Eeprom/External24x08Eeprom.cpp>
#include <ExternalEepromFormation/ExternalEepromFormation.cpp>
#include <ExternalEeprom/ExternalEeprom.cpp>
#include <Wire.h>
#ifdef ARDUINO_ARCH_ESP32
#include <freertos/FreeRTOS.h>
#define LEN (1024*2)
#else
#define LEN 1024
#endif

External24x08Eeprom eeprom;
ExternalEepromFormation formation(&eeprom, 2, 0x04);

void setup() {
	Serial.begin(115200);
#ifdef ARDUINO_ARCH_ESP32
	Wire.begin();
#else
	Wire.begin();
#endif

	Serial.print("Device address: ");
	Serial.println(formation.getAddress(), HEX);
	Serial.print("Device size: ");
	Serial.println(formation.getDeviceSize());
	Serial.print("Device page size: ");
	Serial.println(formation.getPageSize());
	Serial.print("Device address size: ");
	Serial.println(formation.getAddressSize());
	Serial.print("Device address bits size: ");
	Serial.println(formation.getAddressBitsSize());

	auto *data = new uint8_t[LEN];
	auto *read = new uint8_t[LEN];
	for (int i = 0; i < LEN; i++) {
		data[i] = random() % 0xff;
		read[i] = 0;
	}
	int address = 0;
	Serial.print("Address: ");
	Serial.println(address);
	Serial.print("Written: ");
	uint32_t start = millis();
	Serial.println(formation.writeBytes(address, data, LEN));
	Serial.print("Write time: ");
	Serial.println(millis() - start);
	Serial.print("Read: ");
	start = millis();
	Serial.println(formation.readBytes(address, read, LEN));
	Serial.print("Read time: ");
	Serial.println(millis() - start);
	bool match = true;
	for (int i = 0; i < LEN; i++) {
		if (data[i] != read[i]) {
			match = false;
			Serial.print("FAILED! AT ");
			Serial.print(i);
			Serial.print(": data[] = ");
			Serial.print(data[i], HEX);
			Serial.print(", read[] = ");
			Serial.println(read[i], HEX);
		}
	}
	free(data);
	free(read);
	if (match) {
		Serial.println("PASSED!");
	}
}

void loop() {
#ifdef ARDUINO_ARCH_ESP32
	Serial.print("Free heap: ");
	Serial.println(xPortGetFreeHeapSize());
#endif
	delay(1000);
}
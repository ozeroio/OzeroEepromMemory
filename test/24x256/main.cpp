#include <Arduino.h>
#include <External24x256Eeprom/External24x256Eeprom.cpp>
#include <ExternalEeprom/ExternalEeprom.cpp>
#include <Wire.h>
#ifdef ARDUINO_ARCH_ESP32
#include <freertos/FreeRTOS.h>
#define LEN 32768
#else
#define LEN 1024
#endif

External24x256Eeprom eeprom;

void setup() {
	Serial.begin(115200);
#ifdef ARDUINO_ARCH_ESP32
	Wire.begin();
#else
	Wire.begin();
#endif

	Serial.print("Device address: ");
	Serial.println(eeprom.getAddress(), HEX);
	Serial.print("Device size: ");
	Serial.println(eeprom.getDeviceSize());
	Serial.print("Device page size: ");
	Serial.println(eeprom.getPageSize());
	Serial.print("Device address size: ");
	Serial.println(eeprom.getAddressSize());
	Serial.print("Device address bits size: ");
	Serial.println(eeprom.getAddressBitsSize());

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
	Serial.println(eeprom.writeBytes(address, data, LEN));
	Serial.print("Write time: ");
	Serial.println(millis() - start);
	Serial.print("Read: ");
	start = millis();
	Serial.println(eeprom.readBytes(address, read, LEN));
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
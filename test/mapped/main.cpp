#include <Arduino.h>
#include <Wire.h>
#include <ExternalEeprom/ExternalEeprom.cpp>
#include <ExternalMappedEeprom/ExternalMappedEeprom.cpp>
#include <ExternalMappedEeprom/ExternalMappedEeprom.h>
#include <External24cl256Eeprom/External24cl256Eeprom.cpp>
#include <External24cl256Eeprom/External24cl256Eeprom.h>
#include <ExternalByteArrayEeprom/ExternalByteArrayEeprom.cpp>
#include <ExternalByteArrayEeprom/ExternalByteArrayEeprom.h>

#ifdef ARDUINO_ARCH_ESP32
#include <freertos/FreeRTOS.h>
#define LEN 32000
#else
#define LEN 256
#endif

ExternalByteArrayEeprom memoryEeprom(new uint8_t[LEN], LEN);
External24cl256Eeprom externalEeprom(0x00);

ExternalMappedEeprom memoryMappedEeprom(&memoryEeprom, 0, LEN / 2);
ExternalMappedEeprom externalMappedEeprom(&externalEeprom, LEN / 2, LEN);

void clearMemory(ExternalEeprom *eeprom) {
	eeprom->setBytes(0, 0x00, eeprom->getDeviceSize());
}

void dump(ExternalEeprom *eeprom) {
	auto size = eeprom->getDeviceSize();
	auto lineSize = 32;
	auto lines = size / lineSize;
	auto *buffer = new uint8_t[lineSize];
	Serial.println("=====DUMP START=====");
	for (int i = 0; i < lines; i++) {
		Serial.print("[");
		auto from = i * lineSize;
		auto to = from + lineSize;
		if (from < 0x10) {
			Serial.print("0");
		}
		if (from < 0x100) {
			Serial.print("0");
		}
		if (from < 0x1000) {
			Serial.print("0");
		}
		Serial.print(from, HEX);
		Serial.print(", ");
		if (to < 0x10) {
			Serial.print("0");
		}
		if (to < 0x100) {
			Serial.print("0");
		}
		if (to < 0x1000) {
			Serial.print("0");
		}
		Serial.print(to, HEX);
		Serial.print("] ");
		eeprom->readBytes(i * lineSize, buffer, lineSize);
		for (int j = 0; j < lineSize; j++) {
			if (buffer[j] < 0x10) {
				Serial.print("0");
			}
			Serial.print(buffer[j], HEX);
			Serial.print(" ");
		}
		Serial.println();
	}
	Serial.println("=====DUMP EMD=====");
}

void setup() {
	Serial.begin(115200);
#ifdef ARDUINO_ARCH_ESP32
	Wire.begin(27, 26);
#else
	Wire.begin();
#endif

	Serial.println("Initializing...");
	auto *data = new uint8_t[LEN];
	auto *read = new uint8_t[LEN];
	for (int i = 0; i < LEN; i++) {
		data[i] = random() % 0xff;
		read[i] = 0;
	}
	Serial.println("Clearing memoryEeprom...");
	clearMemory(&memoryEeprom);
	Serial.println("Clearing externalEeprom...");
	clearMemory(&externalEeprom);
	int address = 0;
	Serial.print("Address: ");
	Serial.println(address);
	Serial.print("Written to memoryMappedEeprom: ");
	uint32_t start = millis();
	Serial.println(memoryMappedEeprom.writeBytes(address, data, LEN / 2));
	Serial.print("Write time: ");
	Serial.println(millis() - start);
	Serial.print("Written to externalMappedEeprom: ");
	start = millis();
	Serial.println(externalMappedEeprom.writeBytes(address, &(data[LEN / 2]), LEN / 2));
	Serial.print("Write time: ");
	Serial.println(millis() - start);
	Serial.print("Read from memoryMappedEeprom: ");
	start = millis();
	Serial.println(memoryMappedEeprom.readBytes(address, read, LEN / 2));
	Serial.print("Read time: ");
	Serial.println(millis() - start);
	Serial.print("Read from externalMappedEeprom: ");
	start = millis();
	Serial.println(externalMappedEeprom.readBytes(address, &(read[LEN / 2]), LEN / 2));
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
	Serial.println("Dumping memoryEeprom");
	dump(&memoryEeprom);
	Serial.println("Dumping externalEeprom");
	dump(&externalEeprom);
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
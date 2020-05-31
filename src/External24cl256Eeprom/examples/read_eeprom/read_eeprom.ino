#include <Wire.h>
#include <WiredDevice.h>
#include <EepromBasedWiredDevice.h>
#include <ExternalEeprom.h>
#include <External24cl256Eeprom.h>

External24cl256Eeprom eeprom = External24cl256Eeprom(0xa0);

void setup() {
  Serial.begin(9600);
  Serial.println("initialized");
  for (int32_t i = 0; i < eeprom.getDeviceSize(); i++) {
    uint8_t c = eeprom.read(i);
    Serial.println(c, HEX);
  }
}

void loop() {
}

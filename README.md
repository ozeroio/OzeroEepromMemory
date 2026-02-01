# Ozero EEPROM Memory

Library for external I2C EEPROM devices and virtual EEPROMs, with helpers for mapping, formation (multiple chips as one), and byte-array backed testing.

## Features

- Support for 24x02, 24x08, 24x16, 24x32, 24x64, 24x128, 24x256, 24x512 devices
- Sequential read/write with automatic page-boundary handling
- Virtual EEPROM backed by a byte array for testing
- Mapped EEPROM view (work with a subrange of another EEPROM)
- EEPROM formation (multiple physical chips as one contiguous device)

## Installation

### PlatformIO

Add to your `platformio.ini`:

```ini
lib_deps =
  ozeroio/OzeroEepromMemory
```

### Arduino IDE

Download the library ZIP and add it via **Sketch > Include Library > Add .ZIP Library...**

## Quick Start

```cpp
#include <Wire.h>
#include <External24x64Eeprom/External24x64Eeprom.h>

External24x64Eeprom eeprom;

void setup() {
  Serial.begin(115200);
  Wire.begin();

  const int address = 0;
  const uint8_t value = 0xAA;

  eeprom.write(address, value);
  int16_t readValue = eeprom.read(address);

  Serial.print("Read value: 0x");
  Serial.println(readValue, HEX);
}

void loop() {}
```

## API Overview

All EEPROM classes inherit from `ExternalEeprom` and provide:

### Core Methods

- `write(address, byte)` - Write a single byte
- `writeBytes(address, buffer, len)` - Write multiple bytes
- `read(address)` - Read a single byte
- `readBytes(address, buffer, len)` - Read multiple bytes
- `setBytes(address, byte, len)` - Fill a range with the same byte value

### Device Information

- `getDeviceSize()` - Total device size in bytes
- `getPageSize()` - Page size for write operations
- `getAddressSize()` - Number of address bytes (1 or 2)
- `getAddressBitsSize()` - Number of bits used for addressing

### Return Values

All read/write methods follow this convention:
- **>= 0**: Number of bytes successfully read/written
- **< 0**: Error code from the underlying implementation

## Examples

### 1. Basic Write/Read Buffer

```cpp
#include <Wire.h>
#include <External24x32Eeprom/External24x32Eeprom.h>

External24x32Eeprom eeprom(0); // Device address 0

void setup() {
  Serial.begin(115200);
  Wire.begin();

  const int address = 0;
  const int len = 16;
  uint8_t data[len] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
  uint8_t readBuffer[len] = {0};

  // Write data
  int32_t written = eeprom.writeBytes(address, data, len);
  Serial.print("Bytes written: ");
  Serial.println(written);

  // Read back
  int32_t read = eeprom.readBytes(address, readBuffer, len);
  Serial.print("Bytes read: ");
  Serial.println(read);

  // Verify
  for (int i = 0; i < len; i++) {
    Serial.print(readBuffer[i]);
    Serial.print(" ");
  }
  Serial.println();
}

void loop() {}
```

### 2. Virtual EEPROM (Byte Array)

Use a byte array as a virtual EEPROM for testing without hardware:

```cpp
#include <ExternalByteArrayEeprom/ExternalByteArrayEeprom.h>

uint8_t memory[128];
ExternalByteArrayEeprom eeprom(memory, sizeof(memory));

void setup() {
  Serial.begin(115200);

  // Fill first 16 bytes with 0xFF
  eeprom.setBytes(0, 0xFF, 16);

  // Read back
  uint8_t buffer[16] = {0};
  eeprom.readBytes(0, buffer, 16);

  Serial.print("Virtual EEPROM size: ");
  Serial.println(eeprom.getDeviceSize());
}

void loop() {}
```

### 3. Mapped EEPROM (Subrange View)

Create a view of a specific address range within a larger EEPROM:

```cpp
#include <Wire.h>
#include <External24x128Eeprom/External24x128Eeprom.h>
#include <ExternalMappedEeprom/ExternalMappedEeprom.h>

External24x128Eeprom baseEeprom(0);
// Map addresses 0x1000 to 0x1800 (2KB window)
ExternalMappedEeprom mappedView(&baseEeprom, 0x1000, 0x1800);

void setup() {
  Serial.begin(115200);
  Wire.begin();

  // Writing to address 0 in the mapped view actually writes to 0x1000 in base
  mappedView.write(0, 0x55);

  // Reading from mapped view
  int16_t value = mappedView.read(0);

  Serial.print("Mapped view size: ");
  Serial.println(mappedView.getDeviceSize()); // Shows 0x800 (2KB)

  Serial.print("Read value: 0x");
  Serial.println(value, HEX);
}

void loop() {}
```

### 4. EEPROM Formation (Multiple Chips as One)

Combine multiple physical EEPROM devices into a single logical device:

```cpp
#include <Wire.h>
#include <External24x08Eeprom/External24x08Eeprom.h>
#include <ExternalEepromFormation/ExternalEepromFormation.h>

// 24x08 uses address bits A2/A1/A0 for memory block selection
External24x08Eeprom chip(0);
// Create formation with 4 devices, using A2/A1/A0 mask (0x07)
ExternalEepromFormation formation(&chip, 4, 0x07);

void setup() {
  Serial.begin(115200);
  Wire.begin();

  // Now you can address across all 4 chips as one contiguous memory
  uint8_t data[] = "Hello Formation!";
  formation.writeBytes(0, data, sizeof(data));

  uint8_t readBuffer[32] = {0};
  formation.readBytes(0, readBuffer, sizeof(data));

  Serial.print("Formation size: ");
  Serial.println(formation.getDeviceSize());
  Serial.print("Data: ");
  Serial.println((char*)readBuffer);
}

void loop() {}
```

### 5. Device Information

```cpp
#include <Wire.h>
#include <External24x256Eeprom/External24x256Eeprom.h>

External24x256Eeprom eeprom;

void setup() {
  Serial.begin(115200);
  Wire.begin();

  Serial.println("=== EEPROM Info ===");
  Serial.print("Device size: ");
  Serial.print(eeprom.getDeviceSize());
  Serial.println(" bytes");

  Serial.print("Page size: ");
  Serial.print(eeprom.getPageSize());
  Serial.println(" bytes");

  Serial.print("Address size: ");
  Serial.print(eeprom.getAddressSize());
  Serial.println(" bytes");

  Serial.print("Address bits: ");
  Serial.println(eeprom.getAddressBitsSize());

  Serial.print("I2C Address: 0x");
  Serial.println(eeprom.getAddress(), HEX);
}

void loop() {}
```

## Supported Devices

| Device   | Size    | Page Size | Address Bytes |
|----------|---------|-----------|---------------|
| 24x02    | 256 B   | 16 B      | 1             |
| 24x08    | 1 KB    | 16 B      | 1             |
| 24x16    | 2 KB    | 16 B      | 1             |
| 24x32    | 4 KB    | 32 B      | 2             |
| 24x64    | 8 KB    | 32 B      | 2             |
| 24x128   | 16 KB   | 64 B      | 2             |
| 24x256   | 32 KB   | 64 B      | 2             |
| 24x512   | 64 KB   | 128 B     | 2             |

## Important Notes

### Page Boundary Handling

Write operations respect page boundaries automatically. When you write data that crosses a page boundary, the library splits it into multiple write operations internally. This prevents data corruption from page rollover.

### Write Cycle Time

After each write operation, EEPROM devices require a write cycle time (typically 5ms). The library handles this automatically through the underlying `EepromBasedWiredDevice` class.

### Address Limits

Always ensure your addresses are within the device's capacity. The library provides bounds checking through `deviceRemainingRoom()`, but it's good practice to validate addresses in your application.

## License

See [LICENSE](LICENSE) file if available in this repository.

## Author

Dalmir da Silva <dalmirdasilva@gmail.com>

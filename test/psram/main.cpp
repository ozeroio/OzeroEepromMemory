#include <Arduino.h>
#include <Wire.h>
#include <vector>

template<class T>
struct PSallocator {
	typedef T value_type;
	PSallocator() = default;
	template<class U>
	constexpr PSallocator(const PSallocator<U> &) noexcept {}
	[[nodiscard]] T *allocate(std::size_t n) {
		if (n > std::size_t(-1) / sizeof(T)) throw std::bad_alloc();
		if (auto p = static_cast<T *>(ps_malloc(n * sizeof(T)))) return p;
		throw std::bad_alloc();
	}
	void deallocate(T *p, std::size_t) noexcept { std::free(p); }
};
template<class T, class U>
bool operator==(const PSallocator<T> &, const PSallocator<U> &) { return true; }
template<class T, class U>
bool operator!=(const PSallocator<T> &, const PSallocator<U> &) { return false; }

std::vector<int, PSallocator<int>> v;

void setup() {
	Serial.begin(460800);
	delay(1000);
	Serial.printf("Before allocating ~4M of data: %d free.", ESP.getFreePsram());
	v.reserve(900000);
	for (uint32_t x = 0; x < 900000; x++) {
		v.push_back(x);
	}
	Serial.printf("After allocating ~4M of data: %d free.", ESP.getFreePsram());
	v.clear();
	v.shrink_to_fit();
	Serial.printf("After freeing ~4M of data: %d free.", ESP.getFreePsram());
}

void loop() {
	delay(1000);
}
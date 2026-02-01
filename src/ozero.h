#ifndef OZERO_MEMORY_OZERO_H
#define OZERO_MEMORY_OZERO_H

template<typename T>
constexpr const T &ozero_max(const T &x, const T &y) {
	return (x > y) ? x : y;
}

template<typename T>
constexpr const T &ozero_min(const T &x, const T &y) {
	return (x < y) ? x : y;
}

#endif// OZERO_MEMORY_OZERO_H

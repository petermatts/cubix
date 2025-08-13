#include <cstdint>
#include <cassert>

#include "common.h"

uint32_t get(uint32_t num, int from) {
    return (num << (32-from-3)) >> CLEAR; 
}

void set(uint32_t &num, int to, uint32_t set_val) {
    assert(set_val < 8);
    num &= ~(7 << to);
    num |= (set_val << to);
}
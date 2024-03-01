#include "pico/time.h"

typedef uint64_t delayBase_t;

__STATIC_INLINE void Vdelay_us(uint16_t delay_us) {
    busy_wait_us_32(delay_us);
}

__STATIC_INLINE void Vdelay_ms(uint16_t delay_ms) {
    busy_wait_ms(delay_ms);
}

__STATIC_INLINE void Vdelay_s(uint16_t delay_s) {
    busy_wait_ms((uint32_t)1000 * delay_s);
}

__STATIC_INLINE void Vsleep_us(uint16_t delay_us) {
    sleep_us(delay_us);
}

__STATIC_INLINE void Vsleep_ms(uint16_t delay_ms) {
    sleep_ms(delay_ms);
}

__STATIC_INLINE void Vsleep_s(uint16_t delay_s) {
    sleep_ms((uint32_t)1000 * delay_s);
}

__STATIC_INLINE void Vdelay_getBase(delayBase_t *delayBase_p) {
    *delayBase_p = get_absolute_time();
}

__STATIC_INLINE void Vdelay_based_us(
    delayBase_t *delayBase_p, uint16_t delay_us) {
    busy_wait_until(delayed_by_us(*delayBase_p, delay_us));
}

__STATIC_INLINE void Vdelay_based_ms(
    delayBase_t *delayBase_p, uint16_t delay_ms) {
    busy_wait_until(delayed_by_ms(*delayBase_p, delay_ms));
}

__STATIC_INLINE void Vdelay_based_s(
    delayBase_t *delayBase_p, uint16_t delay_s) {
    busy_wait_until(delayed_by_ms(*delayBase_p, (uint32_t)1000 * delay_s));
}

__STATIC_INLINE void Vsleep_based_us(
    delayBase_t *delayBase_p, uint16_t delay_us) {
    sleep_until(delayed_by_us(*delayBase_p, delay_us));
}

__STATIC_INLINE void Vsleep_based_ms(
    delayBase_t *delayBase_p, uint16_t delay_ms) {
    sleep_until(delayed_by_ms(*delayBase_p, delay_ms));
}

__STATIC_INLINE void Vsleep_based_s(
    delayBase_t *delayBase_p, uint16_t delay_s) {
    sleep_until(delayed_by_ms(*delayBase_p, (uint32_t)1000 * delay_s));
}

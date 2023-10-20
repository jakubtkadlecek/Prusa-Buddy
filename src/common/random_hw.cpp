// HW RNG implementation of random.h

#include "random.h"

#include <device/hal.h>
#include <freertos_mutex.hpp>
#include <option/developer_mode.h>

static FreeRTOS_Mutex rand_strong_mutex;

RAND_DECL uint32_t rand_u() {
    uint32_t result = 0;
    HAL_StatusTypeDef retval;

    {
        const std::lock_guard _lg(rand_strong_mutex);
        retval = HAL_RNG_GenerateRandomNumber(&hrng, &result);
    }

    // RNG could theoretically fail, check for it
    // This should theoretically never happen. But if it does...
    if (retval != HAL_OK) {
#if DEVELOPER_MODE()
        // Dev build -> make the devs know RNG failed
        bsod("HAL RNG failed.");
#else
        // Production -> try to keep things working
        static volatile uint32_t rng_ctx = 0x2a57ead0; // Chosen by fair dice roll. Guaranteed to be random.
        rng_ctx = (rng_ctx * 1103515245 + 12345) & 0x7fffffff; // glibc LCG constants
        return rng_ctx;
#endif
    }

    return result;
}

/// Replacement of the original std::rand that was using a software RNG and dynamic allocation
RAND_DECL int __wrap_rand() {
    return int(rand_u() & INT_MAX);
}
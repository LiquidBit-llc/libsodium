
#ifndef randombytes_sysrandom_H
#define randombytes_sysrandom_H

#include "export.h"
#include "randombytes.h"

#ifdef NINTENDO_SWITCH

#ifdef __cplusplus
extern "C" {
#endif

SODIUM_EXPORT
extern struct randombytes_implementation randombytes_switch_implementation;

#ifdef __cplusplus
}
#endif

#endif

#endif

#include "core.h"
#include "private/common.h"
#include "randombytes.h"
#include "randombytes_switch.h"
#include "utils.h"

#ifdef NINTENDO_SWITCH

#include <nn/crypto.h>

static void
randombytes_switch_buf(void * const buf, const size_t size)
{
    nn::crypto::GenerateCryptographicallyRandomBytes(
            buf,
            size 
        );       
}

static uint32_t
randombytes_switch(void)
{
    uint32_t result;

    randombytes_switch_buf((void *)&result, sizeof(result));
    
    return result;
}

static void
randombytes_switch_stir(void)
{
}

static int
randombytes_switch_close(void)
{
    return 0;
}


static const char *
randombytes_switch_implementation_name(void)
{
    return "switchrandom";
}

struct randombytes_implementation randombytes_switch_implementation = {
    SODIUM_C99(.implementation_name =) randombytes_switch_implementation_name,
    SODIUM_C99(.random =) randombytes_switch,
    SODIUM_C99(.stir =) randombytes_switch_stir,
    SODIUM_C99(.uniform =) NULL,
    SODIUM_C99(.buf =) randombytes_switch_buf,
    SODIUM_C99(.close =) randombytes_switch_close
};

#endif
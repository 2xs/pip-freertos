
#ifndef __MBEDTLS_CONFIG_H__
#define __MBEDTLS_CONFIG_H__

/** Configuration file, mainly for AES bench */

/** Activate AES */
#define MBEDTLS_AES_C
/** Compiles the self test fonction */
#define MBEDTLS_SELF_TEST

/** Enable all cipher modes */
#define MBEDTLS_CIPHER_MODE_CFB
#define MBEDTLS_CIPHER_MODE_CBC
#define MBEDTLS_CIPHER_MODE_CTR

/** for memset and memcmp */
#include "stdlib.h"

#endif

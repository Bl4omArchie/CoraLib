#include <openssl/bn.h>
#include <stdio.h>
#include <stdlib.h>

const int M = 1e9+1;

int binary_exp(BIGNUM *sto, BIGNUM *a, BIGNUM *b) {
    if (BN_is_zero(b)) {
        BN_zero(sto);
        return 1;
    }
}
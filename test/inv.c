#include <openssl/bn.h>
#include <stdio.h>
#include <stdlib.h>


const int M = 1e9+1;

int inv_mod(BIGNUM *sto, BIGNUM *a) {
    BIGNUM *x;
    BN_one(x);

    BIGNUM *y;
    BN_zero(y);

    while (!BN_is_one(a)) {
        BN_sub(y, y, );

        BN_mod(b, b, a);
        BN_swap(a, b);
        BN_swap(x, y);
    }
    
}
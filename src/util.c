#include "rsa.h"


int bn_to_int(BIGNUM *a) {
    char sto = *BN_bn2dec(a);
    return (int)sto;
}

int gcd(BIGNUM *sto, BIGNUM *a, BIGNUM *b) {
    if (BN_is_zero(a)) {
        BN_copy(sto, a);
        return EXIT_SUCCESS;
    } 

    if (BN_is_zero(b)) {
        BN_copy(sto, b);
        return EXIT_SUCCESS;
    }

    BIGNUM *az = BN_new();
    BIGNUM *bz = BN_new();
    BIGNUM *diff = BN_new();
    BIGNUM *shift = BN_new();

    if (BN_cmp(az, bz) == -1)
        BN_copy(shift, a);
    
    else
        BN_copy(shift, b);
    BN_rshift(b, b, bn_to_int(bz));

    while (!BN_is_zero(a)) {
        BN_rshift(a, a, bn_to_int(az));
        BN_sub(diff, b, a);
        BN_copy(az, diff);
        
        if (BN_cmp(a, b) == -1)
            BN_copy(b, a);

        BN_copy(a, diff);
    }
    BN_lshift(b, b, bn_to_int(shift));
    BN_copy(sto, b);

    BN_free(az);
    BN_free(bz);
    BN_free(diff);
    BN_free(shift);

    return 1;
}
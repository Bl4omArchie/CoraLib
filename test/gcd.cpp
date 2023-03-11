#include <openssl/bn.h>
#include <stdio.h>
#include <stdlib.h>


int bn_to_int(BIGNUM *a) {
    char sto = *BN_bn2dec(a);
    return (int)sto;
}


int binary_gcd(BIGNUM *sto, BIGNUM *a, BIGNUM *b) {
    if (BN_is_zero(a) || BN_is_zero(b)) {
        BN_zero(sto);
        return EXIT_FAILURE;
    }

    BIGNUM *az = BN_new();
    BIGNUM *bz = BN_new();
    BIGNUM *diff = BN_new();
    BIGNUM *shift = BN_new();
    unsigned char *nb_ptr;

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


int main() {
    BIGNUM *sto;
    BIGNUM *a;
    BIGNUM *b;

    std::string *a_str = {"82019154470699086128524248488673846867876336512717"};
    std::string *b_str "12345678765343456545678877890987876542345665512717";


    BN_dec2bn(&a, a_str);
    BN_dec2bn(&b, b_str);
    binary_gcd(sto, a, b);

    FILE *fp = fopen("gcd_test", "w");
    BN_print_fp(fp, sto);
}
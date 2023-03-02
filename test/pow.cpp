#include <openssl/bn.h>


/* All airhtmetic operation

binary_gcd:                gcd(a, b)
binary_exponentiation:     a ** n
montgomery multiplication: (a*x) % n 
inverse:                   e**-1 % n

*/


int binary_pow(BIGNUM *sto, BIGNUM *a, BIGNUM *n, BIGNUM *M) {
    BIGNUM *r;
    bignum_ctx *ctx;
    BN_one(r);


    while (n) {
        if (BN_is_bit_set(n, 0x1)) 
            BN_mod_mul(r, r, a, M, ctx);
        
        BN_mod_mul(a, a, a, M, ctx);    //Montgomery incoming
        BN_rshift1(n, n);       
    }
    BN_copy(sto, r);

    BN_free(r);
    BN_CTX_free(ctx);
    return EXIT_SUCCESS;
}

int main() {
    BIGNUM *sto;
    BIGNUM *a;
    BIGNUM *b;
    BIGNUM *M;

    unsigned char *a_str [] = {"82019154470699086128524248488673846867876336512717"};
    unsigned char *b_str = "12345678765343456545678877890987876542345665512717";
    unsigned char *M_str = "123456787653434565456788778909878765423456655127189675864545223125467";

    BN_dec2bn(&a, a_str);
    BN_dec2bn(&b, b_str);
    BN_dec2bn(&M, M_str);
    binary_pow(sto, a, b, M);

    FILE *fp = fopen("pow_test", "w");
    BN_print_fp(fp, sto);
}
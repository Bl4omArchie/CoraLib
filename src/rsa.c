#include "rsa.h"


//This structure contain all the necessary information for computing an RSA keypair. 
//Yet the program return the public/private key and clear this structure
struct RSA_KEYPAIR {
    BIGNUM *public_modulus;         //public modulus: n
    BIGNUM *public_exponent;        //public exponent: e
    BIGNUM *p_factor;               //prime factor: p
    BIGNUM *q_factor;               //prime factor: q
    BIGNUM *p_factor_minus_one;     //p-1
    BIGNUM *q_factor_minus_one;     //q-1
    BIGNUM *phi_number;             //phi = (p-1) * (q-1)
    BIGNUM *private_exponent;       //private exponent: d
};



int generate_private_exponent(struct RSA_KEYPAIR *kp_struct) {
    BN_CTX *tmp_var = BN_CTX_new();
    BIGNUM *minus_one = BN_new();
    BN_one(minus_one);

    //Code
    //init p-1 and q-1 so we can compute phi
    BN_sub(kp_struct->p_factor_minus_one, kp_struct->p_factor, minus_one);
    BN_sub(kp_struct->q_factor_minus_one, kp_struct->q_factor, minus_one);
    

    //compute phi
    BN_mul(kp_struct->phi_number, kp_struct->p_factor_minus_one, kp_struct->q_factor_minus_one, tmp_var);
    BN_CTX_free(tmp_var);

    //compute private exponent d
    BN_mod_inverse(kp_struct->private_exponent, kp_struct->public_exponent, kp_struct->phi_number, tmp_var);
    BN_CTX_free(tmp_var);

    return 1;
}


int generate_primes_factors(struct RSA_KEYPAIR *kp_struct, int prime_Bits) {
    BIGNUM *p_candidate;
    BIGNUM *q_candidate;

    //Code

    //...
    kp_struct->p_factor = p_candidate;
    kp_struct->q_factor = q_candidate;
    BN_free(p_candidate);
    BN_free(q_candidate);

    return 1;
}


int rsa_generation(int nBits) {
    //check the validity of the keypair size
    if (nBits < 2048 || nBits > 8192) {
        printf("[!] Incorrect key size. Available key size are between 2048 and 8192 included");
        return EXIT_FAILURE;
    }

    //init the keypair structure
    struct RSA_KEYPAIR *kp_struct = &(struct RSA_KEYPAIR) {};
    BN_CTX *tmp_var = BN_CTX_new();

    //init public exponent
    BN_hex2bn(&kp_struct->public_exponent, "10001");   //x010001 = 65537
    
    //generate p, q, phi and d
    generate_primes_factors(kp_struct, nBits/2);
    generate_private_exponent(kp_struct);

    //init public modulus
    BN_mul(kp_struct->public_modulus, kp_struct->p_factor, kp_struct->q_factor, tmp_var);
    BN_CTX_free(tmp_var);

    return 0;
}
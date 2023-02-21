#ifndef RSA_H
#define RSA_H

#include <stdlib.h>
#include <stdio.h>
#include <openssl/bn.h>


struct RSA_KEYPAIR;

int generate_private_exponent(struct RSA_KEYPAIR *kp_struct);
int generate_primes_factors(struct RSA_KEYPAIR *kp_struct, int prime_Bits);
int rsa_generation(int nBits);
int bn_to_int(BIGNUM *a);
int gcd(BIGNUM *sto, BIGNUM *a, BIGNUM *b);

#endif
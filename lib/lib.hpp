#ifndef LIB_HPP
#define LIB_HPP

#include <openssl/bn.h>
#include <stdio.h>


struct Montgomery;

int reduce(BIGNUM *n);
int multiply(BIGNUM *x, BIGNUM *y);
int transform(BIGNUM *X);


#endif
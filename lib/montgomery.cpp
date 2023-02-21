#include "lib.hpp"

/*
Montgomerry C++ class
*/


struct Montgomery {
    int reduce(BIGNUM *n);
    int multiply(BIGNUM *x, BIGNUM *y);
    int transform(BIGNUM *x);

    BIGNUM *n;
    BIGNUM *nr;
};


int Montgomery::reduce(BIGNUM *n) {
    return 1;
}

int Montgomery::multiply(BIGNUM *x, BIGNUM *y) {
    return 1;
}

int Montgomery::transform(BIGNUM *x) {
    return 1;
}
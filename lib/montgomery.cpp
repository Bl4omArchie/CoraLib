#include "lib.hpp"

/*
Montgomerry C++ struct
*/


struct Montgomery {
    int reduce(BIGNUM *n);
    int multiply(BIGNUM *x, BIGNUM *y);
    int transform(BIGNUM *x);

    BIGNUM *n;
    const BIGNUM *nr;

    constexpr Montgomery(BIGNUM *n) : n(n) {
        
    }

    int reduce(BIGNUM *n) const {
        return 1;
    }

    int multiply(BIGNUM *x, BIGNUM *y) const {
        return 1;
    }

    int transform(BIGNUM *x) const {
        return 1;
    }

};
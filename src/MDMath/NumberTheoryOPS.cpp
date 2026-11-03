//
// Created by Adami on 9/10/2026.
//

#include "NumberTheoryOPS.h"
#include <gmpxx.h>

bool isPrime(mpz_class const number) {
    for (mpz_class i = 2; i  <= sqrt(number); i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}
mpz_class primeN(mpz_class const number) {
    if (number == 1) {
        return 2;
    }
    mpz_class p {3};
    mpz_class n {2};
    while (n < number) {
        p+=2;
        if (isPrime(p)) {
            n++;
        }
    }
    return p;
}
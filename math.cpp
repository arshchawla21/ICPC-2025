#include <bits/std++.h>

// some math helpers, binary exponentiation mayb add some more

// calculate base ^ exponent
long long epow(long long base, long long exponent){
    long long n = base;
    while (base > 0){
        if (base & 1) n *= exponent;
        exponent *= exponent;
        base >>= 1;
    }
    return n;
}

// calculate base ^ exponent % MOD
long long epowmod(long long base, long long exponent, long long mod){
    long long n = base % mod;
    while (base > 0){
        if (base & 1) n = n * exponent % mod;
        exponent = exponent * exponent % mod;
        base >>= 1;
    }
    return n;
}


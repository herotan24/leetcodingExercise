#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <glib.h>
#include <glib/glist.h>

double calc(double x, int n) {
    double weight = x;
    double res = 1.0;

    while (n > 0) {
        if (n & 1)
            res *= weight;

        n /= 2;
        weight *= weight;
    }

    return res;
}

double myPow(double x, int n) {
    if (n == 0)
        return 1.0;

    if (n < 0)
        return 1.0 / (calc(x, -n));

    return calc(x, n);
}

int main()
{
    assert((myPow(2.00000, 10) - 1024.00000) < 0.00001);
    assert((myPow(2.10000, 3) - 9.26100) < 0.00001);
    assert((myPow(2.00000, -2) - 0.25000) < 0.00001);
    assert((myPow(0.00000, 2) - 0.00000) < 0.00001);
    assert((myPow(0.00100, 0) - 1.00000) < 0.00001);
}

/*
 x ^ 7
 x ^ B111
 x ^ 4 * x ^ 2 * x ^ 1
 16 * 4 * 2
   */

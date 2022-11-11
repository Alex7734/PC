#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fraction_simplify.h>
#include <exception.h>
#include <memoryLeaks.h>

int gcd(int n, int m)
{
    int gcd, remainder;

    while (n != 0)
    {
        remainder = m % n;
        m = n;
        n = remainder;
    }

    gcd = m;

    return gcd;
}

void fraction_simplify(int *fraction) {

    // Exception case I
    if (fraction == NULL){
        setErrorInfo(NULL_POINTER);
        return;
    }

    // Exception case II
    if (fraction[1] == 0){
        setErrorInfo(INVALID_RANGE);
        return;
    }

    setErrorInfo(OK);

    // ??? Cipri de ce ???
    if (fraction[0] == 0){
        fraction[1] = 1;
        return;
    }

    // Simplify them
    int gcdu = gcd(fraction[0], fraction[1]);
    fraction[0] = fraction[0] / gcdu;
    fraction[1] = fraction[1] / gcdu;

    // Check for sgn(fraction)
    if (fraction[0]<0 && fraction[1]<0){
        fraction[0] = -fraction[0];
        fraction[1] = -fraction[1];
    }
    if (fraction[1]<0 && fraction[0]>0){
        fraction[1] = -fraction[1];
        fraction[0] = -fraction[0];
    }

}

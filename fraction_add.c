#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fraction_add.h>
#include <exception.h>
#include <memoryLeaks.h>

void fraction_add(const int *fraction1, const int *fraction2, int *result) {
    // Exception case I
    if (fraction1 == NULL || fraction2 == NULL || result == NULL){
        setErrorInfo(NULL_POINTER);
        return;
    }

    // Exception case II
    if (fraction1[1] == 0 || fraction2[1] == 0){
        setErrorInfo(INVALID_RANGE);
        return;
    }

    // Transform the fractions into changeable data types
    int frac1Numitor = fraction1[1];
    int frac1Numarator = fraction1[0];
    int frac2Numitor = fraction2[1];
    int frac2Numarator = fraction2[0];

    // Verify sgn(frac1)
    if (frac1Numitor < 0 && frac1Numarator <0){
        frac1Numitor = -frac1Numitor;
        frac1Numarator = -frac1Numarator;
    }

    // Verify sgn(frac2)
    if (frac2Numitor < 0 && frac2Numarator <0){
        frac2Numitor = -frac2Numitor;
        frac2Numarator = -frac2Numarator;
    }

    // Main CASE
    setErrorInfo(OK);
    // If the numitor is common in both fractions
    if (frac2Numitor==frac1Numitor){
        // calculate them
        result[1] = frac1Numitor;
        result[0] = frac1Numarator + frac2Numarator;

        // simplify them
        int gcdu = gcd(result[0], result[1]);
        result[0] = result[0] /gcdu;
        result[1] = result[1] /gcdu;

        // Check for sgn(result)
        if (result[0]<0 && result[1]<0){
            result[0] = -result[0];
            result[1] = -result[1];
        }
        if (result[1]<0 && result[0]>0){
            result[1] = -result[1];
            result[0] = -result[0];
        }

        // end of this case
        return;
    }
    // The other case ( numitor != common )
    result[1] = frac1Numitor*frac2Numitor;
    result[0] = frac1Numarator*frac2Numitor + frac2Numarator*frac1Numitor;

    // Simplify them
    int gcdu = gcd(result[0], result[1]);
    result[0] = result[0] /gcdu;
    result[1] = result[1] /gcdu;

    // Check for sgn(result)
    if (result[0]<0 && result[1]<0){
        result[0] = -result[0];
        result[1] = -result[1];
    }
    if (result[1]<0 && result[0]>0){
        result[1] = -result[1];
        result[0] = -result[0];
    }

    // check for further numarator simplification
    if (result[0]%result[1]==0){
        result[0] = result[0] / result[1];
    }

}

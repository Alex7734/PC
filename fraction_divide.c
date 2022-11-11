#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fraction_divide.h>
#include <exception.h>
#include <memoryLeaks.h>

void fraction_divide(const int *fraction1, const int *fraction2, int *result) {

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

    // actually multiply
    setErrorInfo(OK);
    result[0] = fraction1[0] * fraction2[1];
    result[1] = fraction1[1] * fraction2[0];

    // Simplify function
    fraction_simplify(result);

}

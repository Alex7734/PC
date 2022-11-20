#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arrayGeneration1.h>
#include <exception.h>
#include <memoryLeaks.h>

unsigned *arrayGeneration1(unsigned size) {
    if(size<1 || size>32){
        setErrorInfo(INVALID_RANGE);
        return NULL;
    }
    unsigned int *arr = malloc (sizeof (unsigned int) * size);

    unsigned int p = 1;
    for (int i=0; i<size; i++){
        arr[i] = p;
        p*=2;
    }

    setErrorInfo(OK);
    return arr;
}

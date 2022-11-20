#include <firstXPrimeNumbers.h>
#include <exception.h>
#include <memoryLeaks.h>
#include <math.h>

int isPrime(int a){
    int c;
    for (c=2;c<=a-1;c++){
        if (a%c == 0)
            return 0;
    }
    return 1;
}
unsigned *firstXPrimeNumbers(unsigned x) {
    if (x>1000 || x<1) {
        setErrorInfo(INVALID_RANGE);
        return NULL;
    }

    unsigned int *arr = malloc (sizeof (unsigned int) * x);

    int counter=1;
    arr[0] = 2;
    int k = 3;
    while (counter<x){
        if (isPrime(k)){
            arr[counter] = k;
            counter++;
        }
        k++;
    }
    setErrorInfo(OK);
    return arr;
}

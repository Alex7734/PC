#include <firstXPalindromeNumbers.h>
#include <exception.h>
#include <memoryLeaks.h>

int isPalindorme(int number){
    int result = 0;
    int aux = number;
    int lastDigit;

    while (aux>0)
    {
        lastDigit = aux % 10;
        result = result*10+lastDigit;
        aux = aux/10;
    }

    if (result==number)
        return 1;
    return 0;
}



unsigned *firstXPalindromeNumbers(unsigned x) {

    if (x>1000 || x<1) {
        setErrorInfo(INVALID_RANGE);
        return NULL;
    }

    unsigned int *arr = malloc (sizeof (unsigned int) * x);

    int k=0;
    int counter=0;
    while (counter<x){
        if (isPalindorme(k)){
            arr[counter] = k;
            counter++;
        }
        k++;
    }
    setErrorInfo(OK);
    return arr;
}

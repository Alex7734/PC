#include <countBits.h>
#include <exception.h>
#include <memoryLeaks.h>

int countSetBits(unsigned int n){
    if (n==0){
        return 0;
    } else {
        return (n & 1) + countSetBits(n >> 1);
    }
}

unsigned countBits(unsigned number, unsigned value) {
    setErrorInfo(OK);
    if (value == 1){
        return countSetBits(number);
    } else {
        return 32 - countSetBits(number);
    }
}
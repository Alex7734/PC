#include <setKthBit.h>
#include <exception.h>
#include <memoryLeaks.h>

unsigned int setBit(int n, int k, int value)
{
    unsigned int masca = 1 << k;
    if (value){
        return masca | n;
    } else {
        return n - masca;
    }
}


unsigned setKthBit(unsigned number, unsigned k, unsigned value) {
    if (k>31){
        setErrorInfo(INVALID_RANGE);
        return 0;
    }
    setErrorInfo(OK);
    int result = setBit(number, k, value);
    return result;
}
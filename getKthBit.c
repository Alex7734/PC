#include <getKthBit.h>
#include <exception.h>
#include <memoryLeaks.h>

unsigned getKthBit(unsigned number, unsigned k) {

    if (k<0 || k>31){
        setErrorInfo(INVALID_RANGE);
        return 0;
    };
    setErrorInfo(OK);
    int result = number & (1 << k);
    if (result == 0){
        return 0;
    } else return 1;
}
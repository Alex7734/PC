#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <areMemoryZonesEqual.h>
#include <exception.h>
#include <memoryLeaks.h>

int areMemoryZonesEqual(void *address1, void *address2, unsigned size) {

    if(address1 == NULL || address2 == NULL){
        setErrorInfo(NULL_POINTER);
        return 0;
    }

    if(size==0){
        setErrorInfo(INVALID_RANGE);
        return 0;
    }

    setErrorInfo(OK);
    if (!memcmp(address1, address2, size)){
        return 1;
    }
    return 0;
}

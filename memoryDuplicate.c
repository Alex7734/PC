#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memoryDuplicate.h>
#include <exception.h>
#include <memoryLeaks.h>

void *memoryDuplicate(void *source, unsigned size) {
    if (size == 0){
        setErrorInfo(INVALID_RANGE);
        return NULL;
    }
    if (source == NULL){
        setErrorInfo(NULL_POINTER);
        return NULL;
    }

    void *address = malloc(size*2);
    memcpy(address, source, size);

    setErrorInfo(OK);
    return address;
}

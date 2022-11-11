#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fraction_fromString.h>
#include <exception.h>
#include <memoryLeaks.h>
#include <fraction_simplify.h>
#include <ctype.h>

int allDigits(const char *str)
{
    size_t i;
    for(i=0;str[i];i++)
        if(!isdigit(str[i]) && str[i]!='/' && str[i]!='-')
            return 0;
    return 1;
}

int *fraction_fromString(const char *fractionAsString) {

    // Nici eu nu stiu ce face dar asa zicea StackOverflow
    int *result = calloc(2, sizeof(*result));


    if (fractionAsString == NULL){
        setErrorInfo(NULL_POINTER);
        return NULL;
    }

    if (!allDigits(fractionAsString)){
        setErrorInfo(INVALID_RANGE);
        return NULL;
    }

    char buffer[100];
    int scanner = sscanf(fractionAsString, "%d/%d%s", &result[0], &result[1], buffer);
    if (strlen(buffer)>0){
        setErrorInfo(INVALID_RANGE);
        return NULL;
    }

    if (scanner == 2){
        setErrorInfo(OK);
        fraction_simplify(result);
        if (result[1]){
            return result;
        }
    } else if (sscanf(fractionAsString, "%d%s", &result[0], buffer)){
        if (strlen(buffer)>0){
            setErrorInfo(INVALID_RANGE);
            return NULL;
        }
        result[1] = 1;
        setErrorInfo(OK);
        return result;
    }

    setErrorInfo(INVALID_RANGE);
    return NULL;
}

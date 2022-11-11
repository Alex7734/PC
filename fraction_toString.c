#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <fraction_toString.h>
#include <exception.h>
#include <memoryLeaks.h>
#include <fraction_simplify.h>

char *fraction_toString(const int *fraction) {

    if (fraction==NULL){
        setErrorInfo(NULL_POINTER);
        return NULL;
    }

    if (fraction[1] == 0){
        setErrorInfo(INVALID_RANGE);
        return NULL;
    }

    setErrorInfo(OK);

    // Incep sa stiu ce face dar tot nu stiu defapt ce face
    char *result = calloc(100, sizeof(*result));

    if (fraction[0] == 0){
        result[0] = '0';
        return result;
    }

    fraction_simplify(fraction);
    
    // Sper ca are sens ce am facut aici
    char buff[10];
    itoa(fraction[0], buff, 10);
    int k = 0;
    for (int i=0; i<strlen(buff); i++){
        result[k] = buff[i];
        k++;
    }
    if (fraction[1] == 1)
    {
        return result;
    }
    else {
        // Aparent asa concatenezi stringuri in C ???
        strncat(result, "/", 1);
        k++;
        result[k] = '/';
        
        // Puteam face o functie dar lenea e mare 
        char buff2[10];
        itoa(fraction[1], buff2, 10);
        for (int i = 0; i < strlen(buff2); i++) {
            result[k] = buff2[i];
            k++;
        }
    }

    return result;
}

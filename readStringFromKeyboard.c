#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readStringFromKeyboard.h>
#include <exception.h>
#include <memoryLeaks.h>

char *readStringFromKeyboard(void) {

    int size = 32;
    char *result = malloc(size);

    int i = 0;
    char c;
    while (scanf("%c", &c)) {
        if (c == '\n') {
            if (i < 2 && result[i]!=0) {
                setErrorInfo(INVALID_RANGE);
                return NULL;
            }
            break;
        }

        if (i >= size){
            size *= 2;
            result = realloc(result, size);
        }

        result[i++] = c;
    }
    char *translate = malloc(size);
    memcpy(translate, result, size);
    setErrorInfo(OK);
    return translate;
}

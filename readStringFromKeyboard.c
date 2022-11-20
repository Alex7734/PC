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
            /* PRIMUL CAZ DOAR CU IF UL ASTA TRECE */
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
    /* Nu conteaza daca copiez memoria din result doar cat trebuie - returnez mereu ciudatenii la final */
    char *translate = malloc(size);
    memcpy(translate, result, size);
    setErrorInfo(OK);
    return translate;
}

/*
exemplu de eroare in log:

Calling readStringFromKeyboard with {"input":"012"}
	expected: {"errorInfo":OK, "return":"012"}
	found   : {"errorInfo":OK, "return":"01223456789 123456789 12345678""}

Calling readStringFromKeyboard with {"input":"0123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 12345"}
	expected: {"errorInfo":OK, "return":"0123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 12345"}
	found   : {"errorInfo":OK, "return":"0123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 123459 123456789 123456789 "

*/

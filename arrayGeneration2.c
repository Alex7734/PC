#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arrayGeneration2.h>
#include <exception.h>
#include <memoryLeaks.h>

char* getElementName(int x){
    int rad;
    if (x<10){
        rad = 1;
    } else if (x<100) {
        rad = 2;
    } else
        rad = 3;

    char* stringNumber = malloc(sizeof (rad));
    itoa(x, stringNumber, 10);
    char* result  = malloc(sizeof(char) * 1000);
    strcpy(result, "elem_");
    strcat(result, stringNumber);
    return result;
}

char **arrayGeneration2(unsigned size) {
    if(size<1 || size>100){
        setErrorInfo(INVALID_RANGE);
        return NULL;
    }

    char* *arr = malloc (size*1000);
    for (int i = 0; i < size; i++) {
        arr[i] = malloc(sizeof(char) * 1000);
    }
    for(int i=0; i<size; i++){
        arr[i]= getElementName(i+1);
    }

    setErrorInfo(OK);
    return arr;
}

void arrayGeneration2_free(char **array, unsigned size) {
    if (array == NULL){
        setErrorInfo(NULL_POINTER);
    } else if (array){
        free(array);
        setErrorInfo(OK);
    } else
        setErrorInfo(NULL_POINTER);
    // Nu inteleg de ce aici merge DOAR asa dar DOAR asa mi a mers ( cazurile de la inceput )
}


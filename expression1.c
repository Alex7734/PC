#include <stdio.h>
#include <expression1.h>
#include <exception.h>
#include <memoryLeaks.h>

void expression1(int a, int b, int c, int x) {
    float result = 0;
    if (c == 0){
        setErrorInfo(DIVISION_BY_ZERO);
        printf("-");
        return;
    }
    result = ((float) a * x + b)/c;
    setErrorInfo(OK);
    printf("%.3f", result);
}
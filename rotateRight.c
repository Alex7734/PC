#include <rotateRight.h>
#include <exception.h>
#include <memoryLeaks.h>

const int SIZE_TWO = 32;

unsigned rotateRight(unsigned number, unsigned times) {
    setErrorInfo(OK);
    return (number >> times) | (number << (SIZE_TWO - times));
}

// Verifica rotateLeft pentru explicare
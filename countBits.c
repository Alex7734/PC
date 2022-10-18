#include <countBits.h>
#include <exception.h>
#include <memoryLeaks.h>

int countSetBits(unsigned int n){
    // cazul de baza recursiv
    // cand ajungem la n == 0 returnam 0
    if (n==0){
        return 0;
    } else {
        // Daca ultimul bit este 1 incrementam cu valoare 1 si apelam recursiv
        // Shiftand numarul la dreapta eliminam ultimul bit
        // n & 1 verifica returneaza 1 daca ultimul bit este 1 ( vezi cum arata o masca )
        return (n & 1) + countSetBits(n >> 1);
    }
}

unsigned countBits(unsigned number, unsigned value) {
    setErrorInfo(OK);
    if (value == 1){
        return countSetBits(number);
    } else {
        return 32 - countSetBits(number);
    }
}

/*
 *
 *
 *
 *
 */
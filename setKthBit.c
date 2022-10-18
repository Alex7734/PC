#include <setKthBit.h>
#include <exception.h>
#include <memoryLeaks.h>

unsigned int setBit(int n, int k, int value)
{
    unsigned int masca = 1 << k;
    if (value){
        return masca | n;
    } else {
        return n - masca;
    }
}


unsigned setKthBit(unsigned number, unsigned k, unsigned value) {
    if (k>31){
        setErrorInfo(INVALID_RANGE);
        return 0;
    }
    setErrorInfo(OK);
    int result = setBit(number, k, value);
    return result;
}

/*
 *  Cea mai urata problema probabil
 *  Pentru a schimba bitul k avem 2 cazuri:
 *
 *  A. Cazul fericit - schimbam din 0 in 1
 *
 *    Cu o simpla masca in linia 7-9 rezolvam asta
 *    shiftam un bit de 1 in dreptul bitului k si realizam o operatie OR
 *    De ce OR? deoarece orice alta valoare are numarul restul bitilor mastii sunt 0
 *    Cu or va rezulta numarul dat cu pozitia schimbata pe k in 1
 *
 * B. Cazul nefericit - schimbam din 1 in 0
 *
 *    Dupa cateva minute mi-am dat seama ca asta inseamna pur si simplu sa
 *    scazi numarul masca din numarul initial
 *    De ce?
 *    Pai sa zicem ca avem nr 17 in binar
 *      --> daca vreau sa schimb bitul 4 din 1 in 0 trebuie doar
 *          sa scad masca care ar fi 16 = 2^4
 *
 */
#include <rotateLeft.h>
#include <exception.h>
#include <memoryLeaks.h>

const int SIZE = 32;

unsigned rotateLeft(unsigned number, unsigned times) {
    setErrorInfo(OK);
    return (number << times) | (number >> (SIZE - times));
}

/*
 *          INITIAL | consider in exemplu times == 1
 *
 *      index   32       5 4 3 2 1 0
 *      bit     0 .......0 0 1 0 1 1
 *
 *          number << times
 *
 *      index   32         5 4 3 2 1 0
 *      bit     0 .........0 1 0 1 1 0
 *
 *          number >> (SIZE - times)
 *
 *      index   32         5 4 3 2 1 0
 *      bit     0 .........0 0 0 1 0 1
 *
 *      Dupa un or operation vom avea numarul ==> 111 adica 1011 rotit la stanga cu 1 mutare
 *
*/
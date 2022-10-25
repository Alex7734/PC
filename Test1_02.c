#include <stdio.h>
unsigned char hashMap[256];
/*
 *
 * It is a must to initalize the hashMap as a global variable
 * In case you initialize it in the main function the values that the hasmap will have will be random
 * By initializing it as a global variable we make sure all values start at 0
 * The purpose of the hashMap will be to hash to the coresponding ascii values 1 in case the specific char is read
 *
 */

// Function to calculate the value n
int calculateN(float x){
        int a = ((int) x) % 10;
        x *= 10;
        int b = ((int) x) % 10;
        int n = a + b;
        if (n<0)
            return -n;
    return n;
}


int main()
{
    float x;
    scanf("%f", &x);
    int n = calculateN(x); // Calling the function above for a clean code

    // this is the special case when the number is of form xx0.0xxx
    if (n==0){
        printf("Nu exista cuvant!");
        return 0;
    }

    // we read the chars and hash them in the hashMap variable
    for (int i=0; i<n ;i++){
        char litera;
        scanf(" %c", &litera);
        hashMap[litera] = 1;
    }

    printf("Numarul de caractere citite: %d\n",n);
    printf("Cuvantul introdus este: ");

    // In order to get the final string in alphabetical order just iterate the hash and display
    // only the values that map to 1 ( in this case 1 means we read the char from the keyboard )
    for (int i=0; i<256; i++){
        if (hashMap[i] == 1)
            printf("%c", i);
    }

    return 0;
}
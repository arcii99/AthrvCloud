//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: intelligent
#include <stdio.h>
#include <stdbool.h>

/*------------------------------*/
/*-------GLOBAL VARIABLES------*/
/*------------------------------*/

const int p = 17; // prime number
const int g = 3; // generator
int a; // random number chosen by Alice
int b; // random number chosen by Bob

/*------------------------------*/
/*--------FUNCTIONS------------*/
/*------------------------------*/

/* Function to calculate power recursively */
int pow(int base, int exponent) {
    if (exponent == 0) {
        return 1;
    } else if (exponent == 1) {
        return base;
    } else {
        return base * pow(base, exponent - 1);
    }
}

/* Function to calculate the value of a^b mod p */
int mod(int a, int b, int p) {
    int result = 1;

    for (int i = 0; i < b; i++) {
        result = (result * a) % p;
    }

    return result;
}

/* Function to encrypt message */
void encrypt(char message[], int key) {
    for (int i = 0; message[i] != '\0'; i++) {
        message[i] = (message[i] + key) % 128;
    }
}

/* Function to decrypt message */
void decrypt(char message[], int key) {
    for (int i = 0; message[i] != '\0'; i++) {
        message[i] = (message[i] - key + 128) % 128;
    }
}

/*------------------------------*/
/*-----------MAIN--------------*/
/*------------------------------*/

int main() {
    /*----STEP 1: ALICE CHOOSES A RANDOM NUMBER A----*/
    a = 5;

    /*----STEP 2: BOB CHOOSES A RANDOM NUMBER B----*/
    b = 7;

    /*----STEP 3: ALICE COMPUTES G^A MOD P----*/
    int A = mod(g, a, p);

    /*----STEP 4: BOB COMPUTES G^B MOD P----*/
    int B = mod(g, b, p);

    /*----STEP 5: ALICE SENDS A TO BOB AND BOB SENDS B TO ALICE----*/

    /*----STEP 6: ALICE COMPUTES B^A MOD P----*/
    int s1 = mod(B, a, p);

    /*----STEP 7: BOB COMPUTES A^B MOD P----*/
    int s2 = mod(A, b, p);

    /*----CHECK IF THE GENERATED KEYS ARE EQUAL----*/
    bool keysMatch = s1 == s2;

    /*----PRINT THE GENERATED KEYS AND MATCHING RESULT----*/
    printf("A: %d\nB: %d\nKey matching result: %s\n", s1, s2, keysMatch ? "true" : "false");

    return 0;
}
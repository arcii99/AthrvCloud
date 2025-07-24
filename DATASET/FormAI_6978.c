//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

//Returns the greatest common divisor of two integers
int gcd(int a, int b) {
    int temp;
    while (1) {
        temp = a % b;
        if (temp == 0)
            return b;
        a = b;
        b = temp;
    }
}

//Generates two random prime numbers
int generatePrime(int p) {
    int i;
    int j = rand() % 100 + 2;
    for (i = j; i < 100; i++) {
        if (gcd(i, p) == 1 && p % i != 0)
            return i;
    }
    return -1;
}

//Returns the modular inverse of a number
int inverse(int a, int b) {
    int x = 0, y = 1, lastx = 1, lasty = 0, temp;
    while (b != 0) {
        int quotient = a / b;
        int remainder = a % b;
        a = b;
        b = remainder;
        temp = x;
        x = lastx - quotient * x;
        lastx = temp;
        temp = y;
        y = lasty - quotient * y;
        lasty = temp;
    }

    if (lastx < 0) {
        lastx += b;
    }

    return lastx;
}

int main() {
    int prime1, prime2;
    srand(time(NULL));
    prime1 = rand() % 100 + 2;
    prime2 = rand() % 100 + 2;

    int n = prime1 * prime2; //Calculate the modulus
    int tot = (prime1 - 1) * (prime2 - 1); //Calculate the totient of the modulus
    int e = generatePrime(tot); //Calculate the first co-prime number
    int d = inverse(e, tot); //Calculate the modular inverse of e

    printf("Public key: %d, %d\n", e, n);
    printf("Private key: %d, %d\n", d, n);

    char message[100];
    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);

    int encrypted[100];
    int decrypted[100];
    int i;
    for (i = 0; i < strlen(message) - 1; i++) {
        encrypted[i] = fmod(pow(message[i], e), n);
        decrypted[i] = fmod(pow(encrypted[i], d), n);
    }

    printf("\nEncrypted message: ");
    for (i = 0; i < strlen(message) - 1; i++) {
        printf("%d ", encrypted[i]);
    }

    printf("\nDecrypted message: ");
    for (i = 0; i < strlen(message) - 1; i++) {
        printf("%c", decrypted[i]);
    }
    printf("\n");

    return 0; //End of the program
}
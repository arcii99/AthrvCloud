//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

//function to check if number is prime
int isPrime(int num) {
    if (num == 2 || num == 3) {
        return 1;
    }
    if (num < 2 || num % 2 == 0) {
        return 0;
    }
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

//function to generate prime number
int generatePrimeNum() {
    srand(time(NULL));
    int primeNum;
    do {
        primeNum = rand() % 256 + 2; //limiting to 256 for demonstration purposes
    } while (!isPrime(primeNum));
    return primeNum;
}

//function to calculate Greatest Common Divisor
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

//function to calculate mod inverse
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1;
}

int main() {
    //generate p and q prime numbers
    int p = generatePrimeNum();
    printf("p: %d\n", p);
    int q = generatePrimeNum();
    printf("q: %d\n", q);

    //calculate n = p*q
    int n = p*q;
    printf("n: %d\n", n);

    //calculate phi(n) = (p-1)*(q-1)
    int phi_n = (p-1)*(q-1);
    printf("phi(n): %d\n", phi_n);

    //choose public key e
    int e;
    do {
        e = rand() % phi_n;
    } while (gcd(e, phi_n) != 1);
    printf("public key (e): %d\n", e);

    //calculate private key d
    int d = modInverse(e, phi_n);
    printf("private key (d): %d\n", d);

    //encryption
    char message[100];
    int encryptedMessage[100];
    printf("Enter message to be encrypted: ");
    fgets(message, 100, stdin);
    int messageLen = strlen(message)-1; //excluding newline character
    for (int i = 0; i < messageLen; i++) {
        encryptedMessage[i] = fmod(pow(message[i], e), n);
    }
    printf("Encrypted Message: ");
    for (int i = 0; i < messageLen; i++) {
        printf("%d ", encryptedMessage[i]);
    }
    printf("\n");

    //decryption
    char decryptedMessage[100];
    printf("Decrypting Message...\n");
    for (int i = 0; i < messageLen; i++) {
        decryptedMessage[i] = fmod(pow(encryptedMessage[i], d), n);
    }
    printf("Decrypted Message: %s\n", decryptedMessage);

    return 0;
}
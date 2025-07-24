//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_PRIME_NUMBER 1500
#define MAX_CHARACTERS 1000

struct keyPair {
    int publicKey;
    int privateKey;
};

int isPrime(int num) {
    int i, flag = 1;
    for (i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) {
            flag = 0;
            break;
        }
    }
    return flag;
}

int generatePrimeNumbers(int *primeNumbers) {
    int count = 0, i;
    for (i = 2; i < MAX_PRIME_NUMBER; ++i) {
        if (isPrime(i)) primeNumbers[count++] = i;
    }
    return count;
}

int gcd(int a, int b) {
    int temp;
    while (b != 0) {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

struct keyPair generatePublicKeyPair(int *primeNumbers, int primeNumbersCount) {
    struct keyPair keyPair;

    int p, q, n, totient, e, d;
    p = primeNumbers[rand() % primeNumbersCount];
    q = primeNumbers[rand() % primeNumbersCount];
    n = p * q;
    totient = (p - 1) * (q - 1);
    e = 2;
    while (e < totient) {
        if (gcd(e, totient) == 1)
            break;
        else
            ++e;
    }
    d = 1;
    while (1) {
        if ((d * e) % totient == 1) break;
        ++d;
    }

    keyPair.publicKey = e;
    keyPair.privateKey = d;
    return keyPair;
}

int* encrypt(char *plainText, int publicKey, int n) {
    int len = strlen(plainText);
    int i, *encryptedData = (int*)malloc(len * sizeof(int));
    for (i = 0; i < len; ++i) {
        encryptedData[i] = pow(plainText[i] - 'a' + 1, publicKey);
        encryptedData[i] = encryptedData[i] % n;
    }
    return encryptedData;
}

char* decrypt(int *encryptedData, int len, int privateKey, int n) {
    int i;
    char *plainText = (char*)malloc(len * sizeof(char));
    for (i = 0; i < len; ++i) {
        plainText[i] = pow(encryptedData[i], privateKey);
        plainText[i] = plainText[i] % n + 'a' - 1;
    }
    plainText[len] = '\0';
    return plainText;
}

int main() {
    int primeNumbers[MAX_PRIME_NUMBER];
    int primeNumbersCount = generatePrimeNumbers(primeNumbers);
    struct keyPair keyPair = generatePublicKeyPair(primeNumbers, primeNumbersCount);
    printf("Public Key: %d\n", keyPair.publicKey);
    printf("Private Key: %d\n", keyPair.privateKey);
    char plainText[MAX_CHARACTERS], c;
    printf("Enter message to be encrypted: ");
    scanf("%[^\n]", plainText);
    int *encryptedData = encrypt(plainText, keyPair.publicKey, primeNumbers[rand() % primeNumbersCount]);
    int i, len = strlen(plainText);
    printf("Encrypted Data: ");
    for (i = 0; i < len; ++i) printf("%d ", encryptedData[i]);
    printf("\n");
    char *decryptedData = decrypt(encryptedData, len, keyPair.privateKey, primeNumbers[rand() % primeNumbersCount]);
    printf("Decrypted Data: %s\n", decryptedData);
    free(encryptedData);
    free(decryptedData);
    return 0;
}
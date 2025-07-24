//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRING_LENGTH 100
#define PRIME_NUMBERS_LENGTH 4 //length of prime numbers array
#define MILLER_RABIN_ROUNDS 10 //number of Miller Rabin rounds

char publicKey[MAX_STRING_LENGTH];
char privateKey[MAX_STRING_LENGTH];
char encryptedMessage[MAX_STRING_LENGTH];
char decryptedMessage[MAX_STRING_LENGTH];

int primeNumbers[PRIME_NUMBERS_LENGTH] = { 3, 5, 7, 11 };

int generateRandomNumberInRange(int lower, int upper) {
    return (rand() % (upper - lower + 1)) + lower;
}

int gcd(int number1, int number2) {
    if (number1 == 0) {
        return number2;
    }
    return gcd(number2 % number1, number1);
}

int modPower(int base, int exponent, int modulo) {
    int result = 1;
    base = base % modulo;
    while (exponent > 0) {
        if (exponent & 1) result = (result * base) % modulo;
        exponent = exponent >> 1;
        base = (base * base) % modulo;
    }
    return result;
}

int isPrime(int number) {
    if (number <= 1 || number == 4) {
        return 0;
    }
    if (number <= 3) {
        return 1;
    }
    int d = number - 1;
    while (d % 2 == 0) {
        d /= 2;
    }
    for (int i = 0; i < MILLER_RABIN_ROUNDS; i++) {
        int a = generateRandomNumberInRange(2, number - 2);
        int x = modPower(a, d, number);
        if (x == 1 || x == number - 1) {
            continue;
        }
        int j;
        for (j = 1; j <= d - 1; j *= 2) {
            x = modPower(x, 2, number);
            if (x == 1) {
                return 0;
            }
            if (x == number - 1) {
                break;
            }
        }
        if (j > d / 2) {
            return 0;
        }
    }
    return 1;
}

int generateRandomPrimeNumber() {
    int primeNumber;
    do {
        primeNumber = primeNumbers[generateRandomNumberInRange(0, PRIME_NUMBERS_LENGTH - 1)];
    } while (!isPrime(primeNumber));
    return primeNumber;
}

int generatePublicKey(int phi) {
    int publicKey;
    do {
        publicKey = generateRandomNumberInRange(2, phi - 1);
    } while (gcd(publicKey, phi) != 1);
    return publicKey;
}

int generatePrivateKey(int phi, int publicKey) {
    int k = 1;
    int privateKey;
    while (1) {
        privateKey = (k * phi + 1) / publicKey;
        if ((privateKey * publicKey) % phi == 1 && privateKey != publicKey) {
            break;
        }
        k++;
    }
    return privateKey;
}

void encryptMessage(char* message, int publicKey, int modulus) {
    while (*message) {
        int character = (int)*message;
        int encryptedCharacter = modPower(character, publicKey, modulus);
        sprintf(encryptedMessage + strlen(encryptedMessage), "%d ", encryptedCharacter);
        message++;
    }
}

void decryptMessage(char* message, int privateKey, int modulus) {
    char* token = strtok(message, " ");
    while (token != NULL) {
        int character = atoi(token);
        int decryptedCharacter = modPower(character, privateKey, modulus);
        sprintf(decryptedMessage + strlen(decryptedMessage), "%c", decryptedCharacter);
        token = strtok(NULL, " ");
    }
}

int main() {
    srand(time(NULL));
    int primeNumber1 = generateRandomPrimeNumber();
    int primeNumber2 = generateRandomPrimeNumber();
    int modulus = primeNumber1 * primeNumber2;
    int phi = (primeNumber1 - 1) * (primeNumber2 - 1);
    int publicKey = generatePublicKey(phi);
    int privateKey = generatePrivateKey(phi, publicKey);

    printf("Public Key: %d\n", publicKey);
    printf("Private Key: %d\n", privateKey);
    printf("Modulus: %d\n", modulus);

    char message[MAX_STRING_LENGTH];
    printf("Enter a message to encrypt: ");
    fgets(message, MAX_STRING_LENGTH, stdin);
    encryptMessage(message, publicKey, modulus);
    printf("Encrypted Message: %s\n", encryptedMessage);

    decryptMessage(encryptedMessage, privateKey, modulus);
    printf("Decrypted Message: %s\n", decryptedMessage);

    return 0;
}
//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000

// Function to calculate GCD
int gcd(int a, int b) 
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

// Function to generate random prime number
int randomPrime()
{
    int low = 100;
    int high = 500;
    int num, i, flag;

    srand(time(0));

    // Generate random prime number within range
    do {
        num = (rand() % (high - low + 1)) + low;
        flag = 0;
        for (i = 2; i <= num / 2; ++i) {
            if (num % i == 0) {
                flag = 1;
                break;
            }
        }
    } while (flag == 1);
    return num;
}

// Function to calculate the public key
int publicKey(int phi)
{
    int e, i;
    for (i = 2; i < phi; i++) {
        if (gcd(i, phi) == 1) {
            e = i;
            break;
        }
    }
    return e;
}

// Function to calculate modular exponentiation
int modExp(int a, int b, int n) 
{
    int result = 1;
    a = a % n;

    while (b > 0) {
        if (b & 1)
            result = (result * a) % n;
        b = b >> 1;
        a = (a * a) % n;
    }
    return result;
}

// Function to encrypt plaintext
void encrypt(int *plainText, int n, int e, int *cipherText)
{
    int i;
    for (i=0; plainText[i] != -1; i++) {
        cipherText[i] = modExp(plainText[i], e, n);
    }
    cipherText[i] = -1; // Mark the end of the message
}

int main() 
{
    int p = randomPrime(); // Generate first prime number 
    int q = randomPrime(); // Generate second prime number

    int n = p * q; // Calculate n
    int phi = (p - 1) * (q - 1); // Calculate phi

    int e = publicKey(phi); // Calculate public key

    int d = 1, k; // Calculate private key
    do {
        k = (phi * d + 1) % e;
        d++;
    } while (k != 0);
    d = (phi * d + 1) / e;

    int plainText[MAX], cipherText[MAX];
    int i = 0, ch;

    printf("Enter the plaintext: ");
    while ((ch = getchar()) != '\n') {
        plainText[i] = ch;
        i++;
    }
    plainText[i] = -1;

    encrypt(plainText, n, e, cipherText); // Encrypt plaintext

    printf("\nPublic Key: (%d, %d)", n, e);
    printf("\nPrivate Key: (%d, %d)", n, d);
    printf("\nCipher Text: ");
    for (i=0; cipherText[i] != -1; i++) {
        printf("%d ", cipherText[i]);
    }

    return 0;
}
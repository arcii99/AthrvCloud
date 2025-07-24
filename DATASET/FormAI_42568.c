//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* function to find greatest common divisor */
int gcd(int a, int b) {
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

/* generate a random prime number */
int generatePrimeNumber() {
    int num, i, flag;
    srand(time(NULL));   /* Initialization, should only be called once. */
    do {
        flag = 1;
        num = rand() % 10000 + 1;   /* generate a random number between 1 and 10000 */
        for(i = 2; i <= num / 2; ++i) {
            if(num % i == 0) {
                flag = 0;
                break;
            }
        }
    } while(flag == 0);
    return num;
}

int main() {
    int p, q, n, e, d, phi, message, encryptedMessage, decryptedMessage;
    p = generatePrimeNumber();  /* generate a random prime number */
    q = generatePrimeNumber();  /* generate another random prime number */
    n = p * q;  /* calculate n */
    phi = (p - 1) * (q - 1);  /* calculate phi(n) */
    e = 2;  /* choose an encryption key */
    while(gcd(e, phi) != 1) {
        e++;
    }
    d = 1;  /* choose a decryption key */
    while((d * e) % phi != 1) {
        d++;
    }
    printf("p = %d, q = %d, n = %d, phi(n) = %d, e = %d, d = %d\n", p, q, n, phi, e, d);
    printf("Enter the message to be encrypted: ");
    scanf("%d", &message);
    encryptedMessage = ((long)pow(message, e)) % n;  /* encrypt the message */
    printf("Encrypted message: %d\n", encryptedMessage);
    decryptedMessage = ((long)pow(encryptedMessage, d)) % n;  /* decrypt the message */
    printf("Decrypted message: %d\n", decryptedMessage);
    return 0;
}
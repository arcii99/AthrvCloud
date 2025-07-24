//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define TRUE 1
#define FALSE 0

int gcd(int a, int b) {
    // This function calculates GCD
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main() {
    int p, q, n, phi, e, d;
    char message[MAX] = "Hello World!";
    int encrypted[MAX], decrypted[MAX];

    /* Generate Random Primes */
    srand((unsigned int) time(NULL));
    p = rand() % MAX + 1;
    q = rand() % MAX + 1;
    while (p == q) q = rand() % MAX + 1;

    printf("p = %d\nq = %d\n", p, q);

    /* Calculate n */
    n = p * q;

    /* Calculate phi */
    phi = (p - 1) * (q - 1);

    /* Calculate e */
    int i;
    for (i = 2; i < phi; i++) {
        if (gcd(i, phi) == 1) {
            e = i;
            break;
        }
    }

    /* Calculate d */
    int k = 1;
    int stop = FALSE;
    while (!stop) {
        d = (k * phi + 1) / e;
        if (d * e == k * phi + 1) stop = TRUE;
        k++;
    }

    /* Encryption */
    int len = strlen(message);
    for (i = 0; i < len; i++) {
        encrypted[i] = (int) pow((double) message[i], (double) e) % n;
    }

    /* Decryption */
    for (i = 0; i < len; i++) {
        decrypted[i] = (int) pow((double) encrypted[i], (double) d) % n;
    }

    printf("Original Message: %s\n", message);
    printf("Encrypted Message: ");
    for (i = 0; i < len; i++) {
        printf("%d ", encrypted[i]);
    }
    printf("\n");

    printf("Decrypted Message: ");
    for (i = 0; i < len; i++) {
        printf("%c", decrypted[i]);
    }
    printf("\n");

    return 0;
}
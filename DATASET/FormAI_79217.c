//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 256

int gcd(int a, int b) {
    if(b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int find_e(int phi) {
    int e = 2;

    while(e < phi) {
        if(gcd(e, phi) == 1) {
            return e;
        }

        e++;
    }

    return -1;
}

int modular_inverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if(m == 1) {
        return 0;
    }

    while(a > 1) {
        q = a / m;
        t = m;

        m = a % m;
        a = t;

        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if(x1 < 0) {
        x1 += m0;
    }

    return x1;
}

int main() {
    char message[MAX_LEN];

    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = 0;

    // Generate random prime numbers
    int p = 17;
    int q = 19;

    // Calculate n and phi(n)
    int n = p * q;
    int phi = (p - 1) * (q - 1);

    // Find e (public key)
    int e = find_e(phi);

    // Calculate d (private key)
    int d = modular_inverse(e, phi);

    int len = strlen(message);
    int i, c, m;

    printf("Public key: {%d, %d}\n", n, e);
    printf("Private key: {%d, %d}\n", n, d);

    printf("Encrypted message: ");
    for(i = 0; i < len; i++) {
        m = message[i];

        c = (int) pow(m, e) % n;

        printf("%d ", c);
    }

    printf("\n");

    printf("Decrypted message: ");
    for(i = 0; i < len; i++) {
        c = message[i] - '0';

        m = (int) pow(c, d) % n;

        printf("%c", m);
    }

    printf("\n");

    return 0;
}
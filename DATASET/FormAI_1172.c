//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main() {
    int p = 3, q = 7, n = p * q, phi = (p - 1) * (q - 1), e = 2, d, m, c;
    while(e < phi) {
        if(gcd(e, phi) == 1)
            break;
        else
            e++;
    }
    for(d = 1; d < phi; d++) {
        if((e * d) % phi == 1)
            break;
    }
    printf("Public key (n, e): (%d, %d)\n", n, e);
    printf("Private key (n, d): (%d, %d)\n", n, d);
    printf("Enter message to be encrypted: ");
    scanf("%d", &m);
    c = (int)pow(m, e) % n;
    printf("Encrypted message: %d\n", c);
    m = (int)pow(c, d) % n;
    printf("Decrypted message: %d\n", m);
    return 0;
}
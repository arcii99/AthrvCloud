//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <math.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int p = 5, q = 7, n, e, d, phi, m, c, decrypted_m;
    n = p * q;
    phi = (p - 1) * (q - 1);
    e = 2;
    while (e < phi) {
        if (gcd(e, phi) == 1) {
            break;
        }
        e++;
    }
    for (int i = 1; i < phi; i++) {
        if ((i * e) % phi == 1) {
            d = i;
            break;
        }
    }
    printf("Public Key (n, e): (%d, %d)\n", n, e);
    printf("Private Key (n, d): (%d, %d)\n", n, d);
    printf("Enter the message m (integer): ");
    scanf("%d", &m);
    c = fmod(pow(m, e), n);
    printf("Encrypted message c: %d\n", c);
    decrypted_m = fmod(pow(c, d), n);
    printf("Decrypted message m: %d\n", decrypted_m);
    return 0;
}
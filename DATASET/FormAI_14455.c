//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: irregular
#include <stdio.h>

int main() {
    int m, n, e, encrypted, decrypted;
    
    printf("Enter two prime numbers: ");
    scanf("%d %d", &m, &n);
    
    printf("Enter encryption key (e): ");
    scanf("%d", &e);
    
    int phi = (m-1) * (n-1);
    
    int d, temp;
    for (d = 2; d < phi; d++) {
        if ((e * d) % phi == 1) {
            break;
        }
    }
    
    printf("Public key: (%d,%d)\n", n, e);
    printf("Private key: (%d,%d)\n", n, d);
    
    printf("Enter message to encrypt: ");
    scanf("%d", &m);
    
    encrypted = 1;
    for (int i = 0; i < e; i++) {
        encrypted *= m;
        encrypted %= n;
    }
    printf("Encrypted message: %d\n", encrypted);
    
    decrypted = 1;
    for (int i = 0; i < d; i++) {
        decrypted *= encrypted;
        decrypted %= n;
    }
    printf("Decrypted message: %d\n", decrypted);
    
    return 0;
}
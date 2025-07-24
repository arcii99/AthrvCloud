//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: brave
#include <stdio.h>
#include <stdlib.h>

/* Function to find Greatest Common Divisor of a and b using Euclidean Algorithm */
long long int gcd(long long int a, long long int b) {
    long long int temp;
    while(b!=0) {
        temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}

/* Function to find inverse of a mod m using Extended Euclidean Algorithm */
long long int inverseMod(long long int a, long long int m) {
    long long int b, q, t1 = 0, t2 = 1, r, tempM = m;
    if(m == 1)
        return 0;
    while(a>1) {
        q = a/m;
        r = a - q*m;
        t1 = t2 - q*t1;
        t2 = r;
        a = m;
        m = r;
    }
    if(t2<0)
        t2 += tempM;
    return t2;
}

/* Function to generate public and private keys */
void generateKeys(long long int p, long long int q, long long int *publicKey, long long int *privateKey) {
    long long int n, phi, i, e, d;
    n = p*q;
    phi = (p-1)*(q-1);
    /* Find the smallest integer e that is co-prime with phi */
    for(i=2; i<phi; i++) {
        if(gcd(i,phi)==1) {
            e = i;
            break;
        }
    }
    /* Find the modular multiplicative inverse of e */
    d = inverseMod(e,phi);
    *publicKey = n;
    *privateKey = d;
}

/* Function to encrypt message using public key */
long long int encrypt(long long int message, long long int publicKey) {
    long long int i, enc = 1;
    for(i=0; i<publicKey; i++)
        enc = (enc*message) % publicKey;
    return enc;
}

/* Function to decrypt message using private key */
long long int decrypt(long long int messageEncrypted, long long int privateKey, long long int p, long long int q) {
    long long int i, dec = 1, n = p*q;
    for(i=0; i<privateKey; i++)
        dec = (dec*messageEncrypted) % n;
    return dec;
}

int main() {
    long long int p, q, publicKey, privateKey;

    printf("Enter two prime numbers (p,q):\n");
    scanf("%lld%lld",&p,&q);

    if(p<2 || q<2) {
        printf("p and q should be prime numbers greater than 1.\n");
        exit(0);
    }

    generateKeys(p,q,&publicKey,&privateKey);

    printf("\nPublic Key (n): %lld", publicKey);
    printf("\nPrivate Key (d): %lld", privateKey);

    char message[100];
    printf("\nEnter the message to be encrypted: ");
    scanf("%s", message);

    long long int messageEncrypted[strlen(message)];
    for(int i=0; i<strlen(message); i++)
        messageEncrypted[i] = encrypt(message[i], publicKey);

    printf("\nEncrypted Message: ");
    for(int i=0; i<strlen(message); i++)
        printf("%lld ", messageEncrypted[i]);

    printf("\n\nDecrypted Message: ");
    for(int i=0; i<strlen(message); i++)
        printf("%c", decrypt(messageEncrypted[i], privateKey, p, q));
    printf("\n");

    return 0;
}
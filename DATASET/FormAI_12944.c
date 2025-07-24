//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 256
#define PRIME 65537

long int gcd(long int a, long int b){
    if(b == 0){
        return a;
    }
    return gcd(b, a%b);
}

void keyGen(long int *d, long int *e, long int *n){
    long int phi, p, q;
    srand(time(0));
    do{
        p = rand() % (SIZE - 1) + 1;
    }while(gcd(p, PRIME) != 1);
    do{
        q = rand() % (SIZE - 1) + 1;
    }while(gcd(q, PRIME) != 1 || q == p);
    *n = p * q;
    phi = (p - 1) * (q - 1);
    do{
        *e = rand() % (phi - 2) + 2;
    }while(gcd(phi, *e) != 1);
    long int k = 1;
    while(1){
        k += phi;
        if(k % *e == 0){
            *d = k / *e;
            return;
        }
    }
}

long int encrypt(long int m, long int e, long int n){
    long int r = m;
    for(int i=1; i<e; i++){
        r = (r * m) % n;
    }
    return r;
}

long int decrypt(long int c, long int d, long int n){
    long int r = c;
    for(int i=1; i<d; i++){
        r = (r * c) % n;
    }
    return r;
}

int main(){
    long int d, e, n;
    keyGen(&d, &e, &n);
    printf("Public Key: (%ld, %ld)\n", e, n);
    printf("Private Key: (%ld, %ld)\n", d, n);
    long int m, c;
    printf("Enter a message to encrypt: ");
    scanf("%ld", &m);
    c = encrypt(m, e, n);
    printf("Encrypted message: %ld\n", c);
    m = decrypt(c, d, n);
    printf("Decrypted message: %ld\n", m);
    return 0;
}
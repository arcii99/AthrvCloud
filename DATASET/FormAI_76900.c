//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX 1000
#define BLOCKSIZE 256
#define PRIME_START 10
#define PRIME_END 100

int gcd(int a, int b){
    if(b == 0){
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int is_prime(int num){
    if (num <= 1){
        return 0;
    }
    int i;
    for (i = PRIME_START; i < PRIME_END; i++){
        if (num % i == 0 && num != i){
            return 0;
        }
    }
    return 1;
}

int generate_prime(){
    int num;
    do {
        num = rand() % MAX;
    } while (!is_prime(num));
    return num;
}

int generate_key_pair(int p, int q, int *e, int *d, int *n){
    *n = p * q;
    int phi = (p - 1) * (q - 1);
    do {
        *e = rand() % phi;
    } while (gcd(*e, phi) != 1);
    int k = 1;
    while((k * phi + 1) % *e != 0){
        k++;
    }
    *d = (k * phi + 1) / *e;
    return 0;
}

void rsa_crypt(char *src, char *dst, int key, int n){
    int block[BLOCKSIZE];
    int i, x;
    for (i = 0; i < strlen(src); i += BLOCKSIZE){
        for (x = 0; x < BLOCKSIZE && (i + x) < strlen(src); x++){
            block[x] = src[i + x];
        }
        for (x = strlen(src) % BLOCKSIZE; x < BLOCKSIZE; x++){
            block[x] = 0;
        }
        int result = 1;
        for (x = 0; x < BLOCKSIZE; x++){
            result = (result * block[x]) % n;
        }
        result = pow(result, key);
        result %= n;
        sprintf(dst + i, "%d", result);
    }
}

void rsa_decrypt(char *src, char *dst, int key, int n){
    char block_str[MAX];
    int block[BLOCKSIZE];
    int i, x;
    for (i = 0; i < strlen(src); i += BLOCKSIZE){
        memcpy(block_str, src + i, BLOCKSIZE);
        block_str[BLOCKSIZE] = '\0';
        int block_val = atoi(block_str);
        int result = 1;
        for (x = 0; x < key; x++){
            result = (result * block_val) % n;
        }
        for (x = BLOCKSIZE - 1; x >= 0; x--){
            block[x] = result % 10;
            result /= 10;
        }
        memcpy(dst + i, block, BLOCKSIZE);
    }
}

int main(){
    srand(time(NULL));
    int p = generate_prime();
    int q = generate_prime();
    int e, d, n;
    generate_key_pair(p, q, &e, &d, &n);

    printf("Generated primes: %d %d\n", p, q);
    printf("Public key (e, n): (%d, %d)\n", e, n);
    printf("Private key (d, n): (%d, %d)\n", d, n);

    char message[MAX], encrypted[MAX], decrypted[MAX];
    printf("Enter message to encrypt: ");
    fgets(message, MAX, stdin);
    message[strcspn(message, "\n")] = '\0';

    rsa_crypt(message, encrypted, e, n);
    printf("Encrypted message: %s\n", encrypted);

    rsa_decrypt(encrypted, decrypted, d, n);
    printf("Decrypted message: %s\n", decrypted);

    return 0;
}
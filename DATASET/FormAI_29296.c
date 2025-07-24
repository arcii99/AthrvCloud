//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PRIME_LIMIT 10000 // maximum limit for prime number generator
#define MESSAGE_LIMIT 1000 // maximum limit for message length

// function to generate a random prime number within a given limit
int prime_generator(int limit) {
    int i, j, flag, num;
 
    // keep generating random numbers until a prime is found
    while(1) {
        num = rand() % limit + 2; // generate a random number between 2 and limit+1
        flag = 1; // assume number is prime
 
        for (j = 2; j <= sqrt(num); ++j) {
            if (num % j == 0) { // if number is divisible by any other number, it is not prime
                flag = 0;
                break;
            }
        }
 
        if (flag == 1) // if a prime number is found, return it
            return num;
    }
}

// function to calculate GCD of two numbers
int gcd(int a, int b) {
    int temp;
    
    while(b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    
    return a;
}

// function to calculate modular inverse of a number
int mod_inverse(int a, int b) {
    int q, r, x1 = 0, x2 = 1, y1 = 1, y2 = 0, temp, gcdval;
    
    while(b != 0) {
        q = a / b;
        r = a % b;
        a = b;
        b = r;
        temp = x2;
        x2 = x1 - q * x2;
        x1 = temp;
        temp = y2;
        y2 = y1 - q * y2;
        y1 = temp;
    }
    
    gcdval = a;
    
    return x1;
}

// function to encrypt a message using public key
void encrypt(char *message, int n, int e) {
    int i = 0, num;
    
    printf("Encrypted message: ");
    while(message[i]) {
        num = (int)message[i];
        num = fmod(pow(num, e), n);
        printf("%d ", num);
        i++;
    }
    printf("\n");
}

// function to decrypt a message using private key
void decrypt(int *cipher, int length, int n, int d) {
    int i = 0, num;
    
    printf("Decrypted message: ");
    while(i < length) {
        num = cipher[i];
        num = fmod(pow(num, d), n);
        printf("%c", num);
        i++;
    }
    printf("\n");
}

int main() {
    int p, q, n, z, e, d, i, cipher[MESSAGE_LIMIT];
    char message[MESSAGE_LIMIT];
    
    srand(time(0));
    
    // generate two random prime numbers
    p = prime_generator(PRIME_LIMIT);
    q = prime_generator(PRIME_LIMIT);
    
    // calculate values for public key
    n = p * q;
    z = (p - 1) * (q - 1);
    e = 2;
    while(e < z) {
        if(gcd(z, e) == 1)
            break;
        else
            e++;
    }
    
    // calculate values for private key
    d = mod_inverse(e, z);
    
    printf("Public Key: {%d, %d}\nPrivate Key: {%d, %d}\n", n, e, n, d);
    
    printf("Enter message to encrypt: ");
    fgets(message, MESSAGE_LIMIT, stdin);
    
    encrypt(message, n, e);
    
    printf("Enter cipher to decrypt (separate numbers by spaces): ");
    i = 0;
    while(scanf("%d", &cipher[i]) == 1)
        i++;
     
    decrypt(cipher, i, n, d);
    
    return 0;
}
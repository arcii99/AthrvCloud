//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// function to check if a number is prime
int is_prime(int num) {
    int i;
    if(num < 2) {
        return 0;
    }
    for(i = 2; i <= sqrt(num); i++) {
        if(num % i == 0) {
            return 0;
        }
    }
    return 1;
}

// function to generate a random prime number within a range
int generate_prime(int start, int end) {
    int num;
    do {
        num = rand() % (end - start + 1) + start;
    } while(!is_prime(num));
    return num;
}

// function to calculate gcd of two numbers
int gcd(int a, int b) {
    int temp;
    while(b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// function to calculate phi of a number
int phi(int num) {
    int i, result = 1;
    for(i = 2; i < num; i++) {
        if(gcd(num, i) == 1) {
            result++;
        }
    }
    return result;
}

// function to generate a random number coprime with n
int generate_coprime(int n) {
    int num;
    do {
        num = rand() % (n - 2) + 2;
    } while(gcd(num, n) != 1);
    return num;
}

// function to calculate modular exponentiation
int modular_exponentiation(int base, int exp, int mod) {
    int result = 1;
    while(exp > 0) {
        if(exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// function to generate public and private keys
void generate_keys(int *public_key, int *private_key) {
    // generate two random prime numbers p and q
    int p = generate_prime(100, 1000);
    int q = generate_prime(100, 1000);

    // calculate n and phi(n)
    int n = p * q;
    int phi_n = phi(n);

    // calculate e, which is a random number coprime with phi_n
    int e = generate_coprime(phi_n);

    // calculate d, which is the modular multiplicative inverse of e
    int d;
    int i = 1;
    while(1) {
        d  = ((phi_n * i) + 1) / e;
        if((d * e) % phi_n == 1) {
            break;
        }
        i++;
    }

    // set public and private keys
    public_key[0] = e;
    public_key[1] = n;
    private_key[0] = d;
    private_key[1] = n;
}

int main() {
    // seed random number generator
    srand(time(NULL));

    // generate public and private keys
    int public_key[2];
    int private_key[2];
    generate_keys(public_key, private_key);

    // print out keys
    printf("Public Key: (%d, %d)\n", public_key[0], public_key[1]);
    printf("Private Key: (%d, %d)\n", private_key[0], private_key[1]);

    // get message from user
    printf("Enter a message to encrypt: ");
    char message[100];
    fgets(message, 100, stdin);

    // encrypt message
    int len = strlen(message);
    int i;
    for(i = 0; i < len; i++) {
        int c = (int) message[i];
        int encrypted = modular_exponentiation(c, public_key[0], public_key[1]);
        printf("%d ", encrypted);
    }
    printf("\n");

    return 0;
}
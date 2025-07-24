//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>

/*
 *  Hello there! I am so excited to show you my cheerful implementation of a Public-Key Algorithm in C language!
 *  In this program, we will generate two very large prime numbers, p and q, and then compute their product, N.
 *  Then, we will select a number, e, which is relatively prime to (p-1)(q-1), and compute its inverse mod (p-1)(q-1), which will be our decryption key, d.
 *  Finally, we will encrypt and decrypt a message using these keys. Let's get started!
 */

// Function to check whether a number is prime or not
int is_prime(int num) {
    int i;
    for(i=2; i<num/2; i++) {
        if(num%i == 0)
            return 0;
    }
    return 1;
}

// Function to generate a random prime number
int generate_prime() {
    int num = rand()%1000 + 1000;   // Generating a random number between 1000 and 1999
    while(!is_prime(num)) {
        num++;
    }
    return num;
}

// Function to compute the greatest common divisor of two numbers using Euclid's algorithm
int gcd(int a, int b) {
    if(b == 0)
        return a;
    else
        return gcd(b, a%b);
}

// Function to compute the modular inverse of a number using Extended Euclid's algorithm
int mod_inverse(int a, int b) {
    int b0 = b, t, q;
    int x0 = 0, x1 = 1;
    if(b == 1)
        return 1;
    while(a > 1) {
        q = a/b;
        t = b, b = a%b, a = t;
        t = x0, x0 = x1 - q*x0, x1 = t;
    }
    if(x1 < 0)
        x1 += b0;
    return x1;
}

// Main function
int main() {
    int p = generate_prime();
    int q = generate_prime();
    int n = p*q;
    int phi_n = (p-1)*(q-1);
    int e;
    do {
        e = rand()%phi_n + 1;   // Generating a random number between 1 and phi_n
    } while(gcd(e, phi_n) != 1);   // Checking if e and phi_n are coprime
    int d = mod_inverse(e, phi_n);
    printf("p = %d\n", p);
    printf("q = %d\n", q);
    printf("n = %d\n", n);
    printf("phi(n) = %d\n", phi_n);
    printf("e = %d\n", e);
    printf("d = %d\n", d);
    printf("Enter a message (maximum 25 characters): ");
    char message[26];
    scanf("%s", message);
    int i, len = strlen(message);
    int encrypted[25], decrypted[25];
    for(i=0; i<len; i++) {
        encrypted[i] = (int)pow((message[i]-'a'+1), e)%n;   // encrypting the message
    }
    printf("Encrypted message: ");
    for(i=0; i<len; i++) {
        printf("%d ", encrypted[i]);
    }
    printf("\n");
    for(i=0; i<len; i++) {
        decrypted[i] = (int)pow(encrypted[i], d)%n;   // decrypting the message
    }
    printf("Decrypted message: ");
    for(i=0; i<len; i++) {
        printf("%c", decrypted[i]-1+'a');   // converting back to original message
    }
    printf("\n");
    return 0;
}
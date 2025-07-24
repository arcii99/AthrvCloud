//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// function to calculate greatest common divisor
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

// function to generate random prime number
int generate_prime() {
    int num, i, flag;
    srand(time(NULL));
    
    while(1) {
        num = (rand() % 100) + 2; // generate a random number between 2 and 101
        flag = 1;
        
        for (i = 2; i <= sqrt(num); i++) { // check if the number is prime
            if (num % i == 0) {
                flag = 0;
                break;
            }
        }
        
        if (flag == 1) {
            return num;
        }
    }
}

int main() {
    int p, q, n, totient, e, d, plaintext, ciphertext;
    char message;
    
    // generate two random prime numbers
    p = generate_prime();
    q = generate_prime();
    
    // calculate n
    n = p * q;
    
    // calculate the totient
    totient = (p - 1) * (q - 1);
    
    // choose e such that 1 < e < totient and gcd(e, totient) = 1
    do {
        e = (rand() % (totient - 2)) + 2; // generate a random number between 2 and totient-1
    } while (gcd(e, totient) != 1);
    
    // calculate d such that d*e = 1 (mod totient)
    int k = 1;
    while (1) {
        if ((k * totient + 1) % e == 0) {
            d = (k * totient + 1) / e;
            break;
        }
        k++;
    }
    
    printf("Public Key: {%d, %d}\n", n, e);
    printf("Private Key: {%d, %d}\n", n, d);
    
    // get the message from the user
    printf("Enter a message to encrypt: ");
    scanf("%c", &message);
    
    // encrypt the message
    plaintext = message;
    ciphertext = fmod(pow(plaintext, e), n);
    printf("Ciphertext: %d\n", ciphertext);
    
    // decrypt the message
    plaintext = fmod(pow(ciphertext, d), n);
    printf("Plaintext: %c\n", plaintext);
    
    return 0;
}
//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//function to check if a number is prime
int is_prime(long int num) {
    if(num == 2 || num == 3)
        return 1;

    if(num == 1 || num % 2 == 0)
        return 0;

    for(int i = 3; i <= sqrt(num); i += 2) {
        if(num % i == 0)
            return 0;
    }

    return 1;
}

//function to generate random prime number
long int generate_prime() {
    long int p = rand() % 1000 + 1;

    while(!is_prime(p)) {
        p = rand() % 1000 + 1;
    }

    return p;
}

int main() {
    srand(time(NULL));

    //generate two different prime numbers
    long int p = generate_prime();
    long int q = generate_prime();

    while(p == q) {
        q = generate_prime();
    }

    //calculate n
    long int n = p * q;

    //calculate totient
    long int totient = (p-1)*(q-1);

    //generate random number between 1 and totient
    long int e = rand() % (totient - 1) + 1;

    while(totient % e == 0) {
        e = rand() % (totient - 1) + 1;
    }

    //calculate d
    long int d = 1;

    while(((d*e) % totient) != 1 || d == e) {
        d++;
    }

    //print keys
    printf("Public key:\n");
    printf("e = %ld, n = %ld\n", e, n);

    printf("\nPrivate key:\n");
    printf("d = %ld, n = %ld\n", d, n);

    return 0;
}
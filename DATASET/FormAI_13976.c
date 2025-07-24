//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void prime_generator(int num){

    int primes[num + 1];

    for (int i = 0; i <= num; i++)
        primes[i] = 1;

    for (int i = 2; i <= sqrt(num); i++) {

        if (primes[i] == 1) {

            for (int j = 2; i * j <= num; j++)

                primes[i * j] = 0;
        }
    }

    printf("The prime numbers from 2 to %d are:\n", num);

    for (int i = 2; i <= num; i++) {

        if (primes[i] == 1) {

            printf("%d ", i);
        }
    }
}

int main(){

    int num;

    printf("Enter a number to find all prime numbers from 2 to n: ");
    scanf("%d", &num);

    prime_generator(num);

    getchar();
    return 0;
}
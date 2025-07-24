//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: shocked
#include <stdio.h>
#include <math.h>

int is_prime(int num) {
    int i;
    if (num <= 1) {
        return 0;
    }
    for (i = 2; i <= sqrt(num); i++) {
        if (num%i == 0) {
            return 0;
        }
    }
    return 1;
}

void print_primes(int count) {
    int i = 2;
    while (count > 0) {
        if (is_prime(i)) {
            printf("%d ", i);
            count--;
        }
        i++;
    }
    printf("\n");
}

int main() {
    int count;

    printf("How many prime numbers would you like to generate? ");
    scanf("%d", &count);

    printf("The first %d prime number(s) are: ", count);
    print_primes(count);

    return 0;
}
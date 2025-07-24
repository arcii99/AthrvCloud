//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Function to check if a number is prime */
bool check_prime(int num) {
    int i;
    bool is_prime = true;

    /* Check if num is divisible by any number less than num */
    for (i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            is_prime = false;
            break;
        }
    }

    return is_prime;
}

int main() {
    int num, i;
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    printf("Prime numbers between 1 and %d are: \n", num);

    /* Check and print prime numbers between 1 and num */
    for (i = 2; i <= num; i++) {
        if (check_prime(i)) {
            printf("%d\n", i);
        }
    }

    return 0;
}
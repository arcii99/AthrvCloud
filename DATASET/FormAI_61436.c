//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: enthusiastic
#include <stdio.h>
#include <stdbool.h>

/* Function to check if a number is prime */
bool is_prime(int num) {
    /* 1 and any number less than 1 are not considered prime */
    if (num <= 1) {
        return false;
    }

    /* Check if num is divisible by any number from 2 up to the square root of num */
    int i;
    for (i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    /* If the loop finishes, num is prime */
    return true;
}

/* Function to generate prime numbers up to a maximum */
void generate_prime_numbers(int max_num) {
    /* Check every number up to max_num */
    int i;
    for (i = 2; i <= max_num; i++) {
        /* If the number is prime, print it */
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int max_num;
    printf("Welcome to the Prime Number Generator!\n");
    printf("Please enter the maximum number you want to generate: ");
    scanf("%d", &max_num);
    printf("Generating all prime numbers up to %d...\n", max_num);
    generate_prime_numbers(max_num);
    printf("Done!\n");
    return 0;
}
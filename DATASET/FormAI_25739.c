//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: funny
#include <stdio.h>

int main() {
    printf("Hey there! I'm the Prime Number Generator!\n");
    printf("I can generate all the prime numbers between two given numbers!\n\n");

    int min, max, p;

    printf("Enter the minimum value: ");
    scanf("%d", &min);

    printf("Enter the maximum value: ");
    scanf("%d", &max);

    printf("Calculating all the prime numbers between %d and %d...\n\n", min, max);

    int is_prime;

    for(int i = min; i <= max; i++) {
        is_prime = 1;

        for(int j = 2; j <= i / 2; j++) {
            if(i % j == 0) {
                is_prime = 0;
                break;
            }
        }

        if(is_prime && i != 1 && i != 0) {
            printf("%d is a prime number!\n", i);
            p++;
        }
    }

    if(p == 0) {
        printf("Oh no! There are no prime numbers between %d and %d!\n", min, max);
    } else {
        printf("\nAll done! We found %d prime numbers between %d and %d! Happy counting!\n", p, min, max);
    }

    return 0;
}
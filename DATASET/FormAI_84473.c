//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: imaginative
#include <stdio.h>

int is_prime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

void prime_generator(int start, int end) {
    printf("Prime numbers between %d and %d are:\n", start, end);
    for (int num = start; num <= end; num++) {
        if (is_prime(num)) {
            printf("%d\n", num);
        }
    }
    printf("End of prime numbers.\n");
}

int main() {
    printf("Welcome to the Prime Number Generator 9000!\n");
    printf("Please enter the starting number: ");
    int start;
    scanf("%d", &start);
    printf("Please enter the ending number: ");
    int end;
    scanf("%d", &end);

    prime_generator(start, end);

    printf("Thank you for using the Prime Number Generator 9000!\n");
    return 0;
}
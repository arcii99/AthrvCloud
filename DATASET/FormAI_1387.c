//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: curious
#include <stdio.h>

int main() {
    int num, i, isPrime;
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    // Check if num is prime
    if (num < 2) {
        printf("Error: Number is less than 2. Please enter a positive integer greater than or equal to 2. \n");
        return 0;
    }
    printf("The prime numbers are:\n");
    for(i = 2; i <= num; i++) {
        isPrime = 1;
        for(int j = 2; j <= i/2; j++) {
            if (i % j == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime == 1) {
            printf("%d\n", i);
        }
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: automated
#include <stdio.h>
#include <stdlib.h>

int main() {
    int max_num, count = 0, prime;

    printf("Enter the maximum number to check for prime numbers: ");
    scanf("%d", &max_num);

    // Check all numbers between 2 and max_num
    for (int num = 2; num <= max_num; num++) {
        prime = 1;
        // Check if num is prime
        for (int i = 2; i <= num / 2; i++) {
            if (num % i == 0) {
                prime = 0;
                break;
            }
        }
        if (prime) {
            printf("%d ", num);
            count++;
            // Print 10 numbers per line
            if (count % 10 == 0) {
                printf("\n");
            }
        }
    }
    printf("\nTotal number of prime numbers between 2 and %d: %d", max_num, count);
    return 0;
}
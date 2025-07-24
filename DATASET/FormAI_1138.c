//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: careful
#include <stdio.h>

int main() {
    int num, prime, i, j;
    printf("Enter the upper limit to generate prime numbers: ");
    scanf("%d", &num);
    printf("Prime numbers from 1 to %d are:\n", num);
    for (i = 2; i <= num; i++) {
        prime = 1;
        for (j = 2; j < i; j++) {
            if (i % j == 0) {
                prime = 0;
                break;
            }
        }
        if (prime == 1) {
            printf("%d\n", i);
        }
    }
    return 0;
}
//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Ken Thompson
#include <stdio.h>

int main() {
    int num, i, j, isPrime;
    
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    printf("Prime numbers between 1 and %d are: \n", num);

    for (i = 2; i <= num; i++) {
        isPrime = 1;

        for (j = 2; j < i; j++) {
            if (i % j == 0) {
                isPrime = 0;
                break;
            }
        }

        if (isPrime) {
            printf("%d ", i);
        }
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: grateful
#include <stdio.h>
#include <stdbool.h>

int main() {
    int num;
    bool isPrime;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 2) {
        printf("%d is not a prime number.\n", num);
        return 0;
    }

    for (int i = 2; i <= num; i++) {
        isPrime = true;

        for (int j = 2; j <= i/2; j++) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        
        if (isPrime) {
            printf("%d ", i);
        }   
    }

    return 0;
}
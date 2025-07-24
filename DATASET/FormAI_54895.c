//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, j, num;
    int sum = 0;

    srand(time(NULL));

    printf("Welcome to Retro Style Performance-Critical Component Example Program\n");

    for (i = 0; i < 5; i++) {
        num = rand() % 100 + 1;
        printf("Randomly generated number %d: %d\n", i+1, num);

        for (j = 2; j <= num/2; j++) {
            if(num % j == 0) {
                sum += j;
            }
        }
        if(sum == 0) {
            printf("%d is a prime number.\n", num);
        } else {
            printf("Sum of factors of %d is %d.\n", num, sum+1);
            sum = 0;
        }
    }

    printf("Thank you for using Retro Style Performance-Critical Component Example Program!\n");

    return 0;
}
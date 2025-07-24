//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: excited
#include <stdio.h>
#include <stdbool.h>

int main() {
    printf("Are you ready to generate some prime numbers?\n");
    printf("Let's go!\n\n");

    int num, count = 0;
    bool isPrime;

    for(num = 2; count < 50; num++) {
        isPrime = true;

        for(int i = 2; i <= num/2; i++) {
            if(num % i == 0) {
                isPrime = false;
                break;
            }
        }

        if(isPrime) {
            printf("%d\n", num);
            count++;
        }
    }

    printf("\nThat's it! %d prime numbers have been generated.\n", count);

    return 0;
}
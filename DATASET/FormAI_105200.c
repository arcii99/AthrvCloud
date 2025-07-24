//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: imaginative
#include <stdio.h>

int main() {
    int count = 0;
    int num = 2;
    printf("The first 50 prime numbers are: \n");

    while (count < 50) {
        int isPrime = 1;
        for (int i = 2; i <= num / 2; i++) {
            if (num % i == 0) {
                isPrime = 0;
                break;
            }
        }

        if (isPrime == 1) {
            printf("%d ", num);
            count++;
        }

        num++;
    }

    return 0;
}
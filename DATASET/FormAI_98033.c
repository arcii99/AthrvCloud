//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: post-apocalyptic
#include <stdio.h>

int isPrime(int num) {
    if (num < 2) {
        return 0; // not a prime number
    }
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            return 0; // not a prime number
        }
    }
    return 1; // is a prime number
}

int main() {
    int count = 0;
    printf("Generating prime numbers...\n");
    for (int i = 2; count < 10; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
            count++;
            sleep(1); // simulate post-apocalyptic slow computing speed
        }
    }
    printf("\nDone!\n");
    return 0;
}
//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: curious
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void primeGen(int start) {
    int current = start;
    printf("The next prime number after %d is:\n", start);
    while (!isPrime(current)) {
        current++;
    }
    printf("%d\n", current);
}

int main() {
    int num;
    printf("Please enter a number to start generating prime numbers from:\n");
    scanf("%d", &num);
    while (true) {
        primeGen(num);
        printf("Would you like to generate the next prime number? (Y/N)\n");
        char response;
        scanf(" %c", &response);
        if (response == 'Y' || response == 'y') {
            num++;
        } else {
            printf("Goodbye!\n");
            return 0;
        }
    }
}
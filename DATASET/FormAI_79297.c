//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: calm
/*
Prime Number Generator
Author: Chatbot
Date: 10/12/2021
*/

#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n);

int main() {

    int n, i;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    printf("Prime numbers between 1 and %d are: ", n);

    for (i = 2; i <= n; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    return 0;
}

bool is_prime(int n) {

    int i;

    if (n <= 1) {
        return false;
    }

    for (i = 2; i <= n/2; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}
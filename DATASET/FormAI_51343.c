//FormAI DATASET v1.0 Category: Math exercise ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= n/2; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    srand(time(0));
    int num1 = generateRandomNumber(1, 100);
    int num2 = generateRandomNumber(1, 100);
    int gcd = 1;
    int lcm = (num1 * num2) / gcd;

    printf("Welcome to the Math Exercise Program!\n\n");

    printf("Find the greatest common divisor (GCD) and least common multiple (LCM) of the following numbers:\n");
    printf("%d and %d\n\n", num1, num2);

    // Find GCD
    for (int i = 1; i <= num1 && i <= num2; i++) {
        if (num1 % i == 0 && num2 % i == 0) {
            gcd = i;
        }
    }

    // Find LCM
    while (true) {
        if (lcm % num1 == 0 && lcm % num2 == 0) {
            break;
        }
        lcm++;
    }

    printf("GCD: %d\n", gcd);
    printf("LCM: %d\n\n", lcm);

    printf("Next question:\n");
    int num3 = generateRandomNumber(1, 100);
    int num4 = generateRandomNumber(1, 100);
    printf("Find the product of the following prime numbers:\n");
    while (!isPrime(num3)) {
        num3 = generateRandomNumber(1, 100);
    }
    while (!isPrime(num4)) {
        num4 = generateRandomNumber(1, 100);
    }
    printf("%d and %d\n\n", num3, num4);

    int product = num3 * num4;

    printf("Answer: %d\n", product);

    return 0;
}
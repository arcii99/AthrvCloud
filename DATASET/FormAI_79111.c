//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: detailed
#include <stdio.h>

int isPrime(int num);

int main() {
    int num, i, flag;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    printf("Prime numbers between 1 and %d are: ", num);

    // Loop through each number between 2 and num
    for (i = 2; i <= num; i++) {

        // Check if the current number is prime
        flag = isPrime(i);

        // If the number is prime, print it out
        if (flag == 1)
            printf("%d ", i);
    }

    return 0;
}

// Function to check if a number is prime or not
int isPrime(int num) {
    int i;

    // Check if num is divisible by any number between 2 and num/2
    for (i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return 0;
        }
    }

    return 1;
}
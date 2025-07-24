//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: peaceful
// C Prime Number Generator
// Written in a peaceful style by the chatbot

#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is prime or not
bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= num/2; i++) {
        if (num%i == 0) return false;
    }
    return true;
}

int main() {
    int num, cnt = 0;

    // Ask user for input
    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Generating prime numbers up to %d...\n", num);

    // Generate prime numbers up to user input
    for (int i = 2; i <= num; i++) {
        // Check if i is prime
        if (isPrime(i)) {
            printf("%d ", i);
            cnt++;
        }
    }

    printf("\n\nTotal prime numbers generated: %d\n", cnt);

    return 0;
}
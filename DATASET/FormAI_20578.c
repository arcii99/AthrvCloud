//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: unmistakable
#include <stdio.h>
#include <stdbool.h>

// function to check if a given number is prime or not
bool is_prime(int num) {
    if (num == 2 || num == 3) {
        return true;
    }
    if (num == 1 || num % 2 == 0) {
        return false;
    }
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// function to generate and print prime numbers within a range
void prime_gen(int start, int end) {
    printf("Prime numbers between %d and %d:\n", start, end);
    for (int i = start; i <= end; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// main function
int main() {
    int start, end;
    printf("Enter the starting number: ");
    scanf("%d", &start);
    printf("Enter the ending number: ");
    scanf("%d", &end);
    prime_gen(start, end);
    return 0;
}
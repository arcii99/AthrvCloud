//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: cheerful
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int number){
    for (int i = 2; i <= number / 2; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    printf("Welcome to the Prime Number Generator!\n");
    printf("This program will generate all prime numbers between 2 and the number you choose.\n");
    int limit;
    printf("Please enter a number: ");
    scanf("%d", &limit);
    printf("The prime numbers between 2 and %d are:\n", limit);
    for (int i = 2; i <= limit; i++) {
        if (isPrime(i)) {
            printf("%d\n", i);
        }
    }
    printf("Thank you for using the Prime Number Generator. Have a nice day!\n");
    return 0;
}
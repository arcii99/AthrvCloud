//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: curious
#include <stdio.h>

int main() {

    // Greetings to the user
    printf("Welcome to the Prime Number Generator!\n\n");
    printf("Please enter a positive integer greater than or equal to 2: ");

    // Reading input from the user
    int num;
    scanf("%d", &num);

    // Checking if the input is valid
    if (num < 2) {
        printf("\nInvalid input! The number must be greater than or equal to 2.\n");
        return 0;
    }

    // Printing the prime numbers
    printf("\nPrime numbers less than or equal to %d:\n", num);

    // Looping through all the numbers less than or equal to the input
    for (int i = 2; i <= num; i++) {
        // Initializing a flag variable to check if the number is prime or not
        int is_prime = 1;

        // Checking if the number is divisible by any number less than itself
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                is_prime = 0; // As the number is divisible, it is not prime
                break; // There is no need to continue the loop
            }
        }

        // Printing the number if it is prime
        if (is_prime) {
            printf("%d ", i);
        }
    }

    printf("\n\nThank you for using the Prime Number Generator!\n");
    
    return 0;
}
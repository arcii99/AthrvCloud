//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: genious
#include <stdio.h>

int main() {
    // Display a welcome message
    printf("Welcome to Prime Number Generator!\n");
    
    // Get user input for the range of numbers to check
    int start, end;
    printf("Enter the start and end values (separated by a space): ");
    scanf("%d %d", &start, &end);
    
    // Loop through numbers within the user-input range
    for (int i = start; i <= end; i++) {
        int isPrime = 1;
        
        // Check if the current number is prime
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                isPrime = 0;
                break;
            }
        }
        
        if (isPrime && i != 1) {
            printf("%d is a prime number.\n", i);
        }
    }
    
    // Display a goodbye message and return 0 to exit the program
    printf("Thank you for using Prime Number Generator!\n");
    return 0;
}
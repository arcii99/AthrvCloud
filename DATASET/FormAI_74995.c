//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Sherlock Holmes
#include <stdio.h>

// This is a C program to generate prime numbers
// In the style of Sherlock Holmes

// Begin the case
int main() {
    int suspect, is_prime; // Declare our suspects and their status
    
    printf("Sherlock's Prime Number Generator:\n");
    printf("The game is afoot!\n");
    
    // Start our investigation
    for (suspect = 2; suspect <= 100; suspect++) {
        is_prime = 1; // Assume innocence

        // Eliminate suspects with clear evidence
        for (int i = 2; i <= suspect / 2; i++) {
            if (suspect % i == 0) { // Found a divisor?
                is_prime = 0; // Guilty as charged
                break; // Move on to the next suspect
            }
        }

        // If the suspect is still a prime number
        // Then it must be so against all evidence
        if (is_prime == 1) {
            printf("%d is prime!\n", suspect); // Guilty as charged
            
            // But our investigation is far from over...
            printf("The question remains: what is the next prime number?\n");
            printf("There is only one way to find out!\n");  
        }
    }

    printf("The game is up!\n"); // Finally, we have our answer
    return 0;
}
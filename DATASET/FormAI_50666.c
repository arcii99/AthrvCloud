//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: medieval
// Thou art now entering the realm of prime numbers!
// Ye olde prime number generator program, by Sir Bot-A-Lot

#include <stdio.h>

// Function to generate prime numbers within a given range
void generate_primes(int start, int end) {
    int i, j, prime, count = 0;
    
    printf("The prime numbers within the range of %d and %d are:\n", start, end);
    
    // Check for prime numbers within the given range
    for (i = start; i <= end; i++) {
        prime = 1;  // Assume i is prime until proven otherwise
        
        for (j = 2; j <= i/2; j++) {
            if (i % j == 0) {
                prime = 0;  // i is not prime
                break;
            }
        }
        
        if (prime == 1) {
            count++;
            printf("%d, ", i);  // Display prime number if found
        }
    }
    
    // Check if no prime numbers were found within the given range
    if (count == 0) {
        printf("There are no prime numbers within the range of %d and %d\n", start, end);
    }
}

int main() {
    int start, end;
    
    printf("Greetings, milord! I am Sir Bot-A-Lot, your trusty prime number generator.\n");
    printf("Please enter the range of numbers you would like me to search for primes:\n");
    printf("From: ");
    scanf("%d", &start);
    printf("To: ");
    scanf("%d", &end);
    
    generate_primes(start, end);
    
    printf("\nFare thee well, milord! May your numbers be always prime.\n");
    return 0;
}
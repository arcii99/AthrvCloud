//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: energetic
#include <stdio.h>
#include <stdbool.h>

int main() {

    int n, i, j;
    bool isPrime;
 
    printf("Enter the number of prime numbers you want to generate: ");
    scanf("%d", &n);
 
    printf("The first %d prime numbers are: ", n);
 
    // 2 is the first prime number
    printf("2 ");
 
    for(i=3; i<=n; i++) {
		
        // Assume the number is prime
        isPrime = true;
		
		
        for(j=2; j<i; j++) {
            if(i%j == 0) {
                isPrime = false; // Not a prime number
                break; // Exit the inner for loop
            }
        }
 
        if(isPrime) {
            printf("%d ", i); // Print the prime number
        }
    }
 
    return 0;
}
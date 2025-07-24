//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: portable
#include <stdio.h>

int main() {
    int num, i, flag;
    
    printf("This program will generate prime numbers up to a given limit.\n");
    printf("Enter the limit: ");
    scanf("%d", &num);
    
    // Iterate from 2 to the given limit
    for (i=2; i<=num; i++) {
        flag = 1; // Assume i is prime
        
        // Check if i is divisible by any number from 2 to i/2
        for (int j=2; j<=i/2; j++) {
            if (i % j == 0) {
                flag = 0; // i is not prime
                break;
            } 
        }
        
        // Print i if it is prime
        if (flag == 1) {
            printf("%d ", i);
        }
    }
    
    return 0;
}
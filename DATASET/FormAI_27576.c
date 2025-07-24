//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: relaxed
#include <stdio.h>

// Function to check if a number is prime or not
int isPrime(int n) {
    // Corner cases
    if (n <= 1) {
        return 0;
    }
    
    if (n <= 3) {
        return 1;
    }
    
    // This is checked so that we can skip the middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0) {
        return 0;
    }
    
    for (int i = 5; i * i <= n; i = i + 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return 0;
        }
    }
    
    return 1;
}

// Main function to generate prime numbers between the given range
int main() {
    int start, end;
    
    printf("Enter the start of range: ");
    scanf("%d", &start);
    
    printf("Enter the end of range: ");
    scanf("%d", &end);
    
    printf("Prime numbers between %d and %d are: ", start, end);
    
    for (int i = start; i <= end; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    
    printf("\n");
    
    return 0;
}
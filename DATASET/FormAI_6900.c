//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: recursive
#include <stdio.h>

// Custom recursive function to generate prime numbers
void genPrime(int num, int divisor) {
    int flag = 1; // Flag to check for prime
    if(num == 1 || num == 2) { // Base cases
        printf("%d ", num);
        genPrime(num + 1, 2);
        return;
    }
    for(int i = 2; i <= num/2; i++) { // Check for prime
        if(num % i == 0) {
            flag = 0;
            break;
        }
    }
    if(flag) {
        printf("%d ", num);
    }
    if(num == 100) { // End condition
        return;
    }
    genPrime(num + 1, 2); // Recursive call
}

// Main function
int main() {
    genPrime(1, 2); // Call to generate prime numbers
    return 0;
}
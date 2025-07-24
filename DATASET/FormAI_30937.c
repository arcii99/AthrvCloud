//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: expert-level
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int num);

int main() {
    int num, count = 0;
    
    printf("Enter the number upto which you want to find prime numbers: ");
    scanf("%d", &num);
    
    printf("The prime numbers between 1 and %d are:\n", num);
    
    for(int i=2; i<=num; i++) {
        if(is_prime(i)) {
            count++;
            printf("%d ", i);
        }
    }
    
    printf("\nTotal prime numbers found: %d", count);
    return 0;
}

// Function to check if a number is prime
bool is_prime(int num) {
    if(num <= 1) {
        return false;
    }
    
    for(int i=2; i*i<=num; i++) {
        if(num%i == 0) {
            return false;
        }
    }
    
    return true;
}
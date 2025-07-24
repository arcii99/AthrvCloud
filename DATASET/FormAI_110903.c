//FormAI DATASET v1.0 Category: Educational ; Style: unmistakable
#include <stdio.h>

// function to check if a number is prime or not
int isPrime(int num) {
    int i;
    
    for (i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    
    return 1;
}

// function to display prime numbers in a given range 
void displayPrimes(int start, int end) {
    int i;
    
    printf("Prime numbers between %d and %d are: ", start, end);
    
    for (i = start; i <= end; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    
    printf("\n");
}

// main function
int main() {
    int start, end;
    
    printf("Enter the starting number: ");
    scanf("%d", &start);
    
    printf("Enter the ending number: ");
    scanf("%d", &end);
    
    displayPrimes(start, end);
    
    return 0;
}
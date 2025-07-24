//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: genious
#include <stdio.h>

// Function to check if a number is prime or not
int isPrime(int num) {
    int i;
    for(i = 2; i <= num / 2; i++) {
        if(num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int num, i, j;
    printf("Enter the limit: ");
    scanf("%d", &num);
    printf("The prime numbers between 2 and %d are:\n", num);
    for (i = 2; i <= num; i++) {
        if(isPrime(i)) {
            printf("%d ", i);
        }
    }
    return 0;
}
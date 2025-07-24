//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: rigorous
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int num) {
    if (num <= 1) return false; // 1 is not a prime number
    if (num == 2) return true; // 2 is a prime number
    if (num % 2 == 0) return false; // even numbers are not prime
    
    // checking for divisibility from 3 to sqrt(num)
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return false;
    }
    
    return true;
}

int main() {
    int num, count = 1; // we start at 2 as the first prime number
    
    printf("Enter the number of prime numbers you want to generate: ");
    scanf("%d", &num);
    
    printf("The first %d prime numbers are:\n", num);
    printf("2 "); // 2 is the first prime number
    
    for (int i = 3; count < num; i += 2) { // we skip even numbers
        if (is_prime(i)) {
            printf("%d ", i);
            count++;
        }
    }
    
    return 0;
}
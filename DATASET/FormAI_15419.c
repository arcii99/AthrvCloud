//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Alan Touring
#include <stdio.h>

// function to check if a number is prime
int isPrime(int n) {
    if (n <= 1) {
        return 0;
    } else if (n <= 3) {
        return 1;
    } else if (n % 2 == 0 || n % 3 == 0) {
        return 0;
    }
    int i = 5;
    while (i * i <= n) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return 0;
        }
        i += 6;
    }
    return 1;
}

// function to generate prime numbers
void generatePrimes(int num) {
    int i = 2;
    int count = 0;
    while (count < num) {
        if (isPrime(i)) { // check if i is prime
            printf("%d ", i); // print if i is prime
            count++; // increment count
        }
        i++; // increment i
    }
}

// main function
int main() {
    int num;
    printf("Enter the number of prime numbers you want to generate: ");
    scanf("%d", &num);
    printf("The first %d prime numbers are:\n", num);
    generatePrimes(num);
    return 0;
}
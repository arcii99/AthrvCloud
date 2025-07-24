//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: accurate
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    printf("Enter the number of primes you want to generate:");
    scanf("%d", &n);
    int primes[n]; //array to store prime numbers
    int count = 0; //count of number of primes generated so far
    int num = 2; //start with the first prime number

    while (count < n) {
        if (isPrime(num)) { //if the number is prime, store it in primes array and increase count
            primes[count] = num;
            count++;
        }
        num++; //check the next number
    }

    printf("The first %d prime numbers are: ", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", primes[i]);
    }
    return 0;
}
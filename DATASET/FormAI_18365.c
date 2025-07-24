//FormAI DATASET v1.0 Category: Educational ; Style: accurate
#include<stdio.h> 

// function to determine if a given number is prime
int isPrime(int n) {
    if(n == 1) {
        return 0;
    }
    for(int i = 2; i <= n/2; i++) {
        if(n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int num, sum = 0;
    printf("Enter any number: ");
    scanf("%d", &num);

    for(int i = 2; i <= num; i++) {
        if(isPrime(i)) {
            sum += i;
        }
    }

    printf("Sum of all prime numbers between 1 to %d is %d", num, sum);

    return 0;
}
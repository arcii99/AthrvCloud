//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: intelligent
#include <stdio.h>

int main() {
    int n, i, j, flag, count = 0, num = 2;
    printf("Enter the limit of prime numbers to be generated: ");
    scanf("%d", &n); // Taking the number of prime numbers to be generated from user

    while(count < n) {
        flag = 0;
        for(i = 2; i <= num/2; i++) { // To check whether number is prime or not
            if(num % i == 0) {
                flag = 1; // If flag is 1, number is not prime
                break;
            }
        }

        if(flag == 0) { // If flag is 0, number is prime
            printf("%d ", num); // Printing prime number
            count++; // Incrementing the count of prime numbers generated
        }

        num++; // Incrementing the number to be checked for prime
    }

    return 0;
}
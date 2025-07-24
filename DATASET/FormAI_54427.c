//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: immersive
#include <stdio.h>

/*
This is a Prime Number Generator program that generates prime numbers for the user. 
When the user enters a number, the program generates all prime numbers less than or equal to that number.
*/

//Function to check if a number is prime or not
int isPrime(int n) {
    if (n<=1)
        return 0;
    for (int i=2; i*i<=n; i++) {
        if (n%i == 0)
            return 0;
    }
    return 1;
}

int main() {
    int n;
    printf("Welcome to the Prime Number Generator program!\n");
    printf("Please enter a number: ");
    scanf("%d", &n);
    printf("Generating all prime numbers less than or equal to %d:\n", n);
    for (int i=2; i<=n; i++) {
        if (isPrime(i))
            printf("%d ", i);
    }
    printf("\n");
    printf("Thank you for using the Prime Number Generator! Have a nice day!");
    return 0;
}
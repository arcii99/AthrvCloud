//FormAI DATASET v1.0 Category: Arithmetic ; Style: rigorous
#include <stdio.h>

// Declare function to calculate factorial of given number
int calculateFactorial(int num) {
    int fact = 1;
    for(int i = 1; i <= num; i++) {
        fact *= i;
    }
    return fact;
}

// Define function to print nth prime number
void printNthPrime(int n) {
    int count = 0, num = 1;
    while(count < n) {
        int flag = 0;
        for(int i = 2; i <= num / 2; i++) {
            if(num % i == 0) {
                flag = 1;
                break;
            }
        }
        if(flag == 0) {
            count++;
        }
        num++;
    }
    printf("The %dth prime number is: %d\n", n, num-1);
}

int main() {
    int num;
    printf("Enter a number to calculate the factorial: ");
    scanf("%d", &num);
    int result = calculateFactorial(num);
    printf("The factorial of %d is: %d\n", num, result);
    
    printf("\nEnter a number to calculate the nth prime number: ");
    scanf("%d", &num);
    printNthPrime(num);
    return 0;
}
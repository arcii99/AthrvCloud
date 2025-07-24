//FormAI DATASET v1.0 Category: Recursive ; Style: lively
#include <stdio.h>

int calculateFactorial(int n) {
    if(n == 0) {
        return 1; //base case
    }
    else {
        return n * calculateFactorial(n-1); //recursive case
    }
}

int main() {
    int num, fact;
    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &num);

    if(num < 0) {
        printf("Invalid Input. Please enter a non-negative integer.\n");
    } 
    else {
        fact = calculateFactorial(num);
        printf("The factorial of %d is %d\n", num, fact);
    }

    return 0;
}
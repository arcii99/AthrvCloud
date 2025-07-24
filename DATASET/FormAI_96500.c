//FormAI DATASET v1.0 Category: Recursive ; Style: grateful
#include <stdio.h>

int factorial(int n) {
    if(n == 0) { // base case
        printf("I am so grateful for you, because your number is 0, which is quite a unique starting point!\n");
        return 1;
    }
    else {
        int result = n * factorial(n-1);
        printf("I am so grateful for you, because you just calculated factorial(%d), which equals %d!\n", n, result);
        return result;
    }
}

int main() {
    int number, fact;
    printf("I am so grateful to have the opportunity to calculate the factorial of a number for you!\n");
    printf("Please enter a number: ");
    scanf("%d", &number);
    fact = factorial(number);
    printf("\nI am so grateful to have been able to help you calculate the factorial of %d! The answer is %d.\n", number, fact);
    return 0;
}
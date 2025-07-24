//FormAI DATASET v1.0 Category: Recursive ; Style: medieval
#include <stdio.h>

int factorial(int);

int main() {
    int number, result;
    printf("Greetings thee! What number dost thou wish to find the factorial of? ");

    scanf("%d", &number);

    if(number < 0) {
        printf("Lead us not into temptation, only non-negative integers can be factorialized.");
    }
    else {
        result = factorial(number);
        printf("The factorial of %d is %d.\n", number, result);
        printf("Hark! Thy wish has been granted!\n");
    }
    return 0;
}

int factorial(int n) {
    if(n == 0 || n == 1) {
        return 1;
    }
    else {
        printf("Calculating the factorial of %d...\n", n);
        return n * factorial(n-1);
    }
}
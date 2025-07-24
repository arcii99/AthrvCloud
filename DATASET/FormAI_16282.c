//FormAI DATASET v1.0 Category: Computer Biology ; Style: recursive
#include <stdio.h>

int fibonacci(int num) {
    if(num == 0) {
        return 0;
    }
    else if(num == 1) {
        return 1;
    }
    else {
        return fibonacci(num - 1) + fibonacci(num - 2);
    }
}

int factorial(int num) {
    if(num == 0) {
        return 1;
    }
    else {
        return num * factorial(num - 1);
    }
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    printf("\nFibonacci of %d is: %d", num, fibonacci(num));
    
    printf("\nFactorial of %d is: %d", num, factorial(num));
    
    return 0;
}
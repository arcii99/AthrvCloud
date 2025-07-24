//FormAI DATASET v1.0 Category: Recursive ; Style: energetic
#include<stdio.h>

int fibonacci(int num) {
    if(num <= 1) {
        return num;
    } else {
        return (fibonacci(num-1) + fibonacci(num-2));
    }
}

int main() {
    int input, result;

    printf("Enter a positive integer: ");
    scanf("%d",&input);

    result=fibonacci(input);

    printf("Fibonacci series of %d is %d", input, result);

    return 0;
}
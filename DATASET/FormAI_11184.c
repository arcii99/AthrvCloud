//FormAI DATASET v1.0 Category: Recursive ; Style: scalable
#include <stdio.h>

int recursiveFactorial(int n) {
    if(n == 0) {
        return 1;
    }
    else {
        return n * recursiveFactorial(n-1);
    }
}

void recursiveFibonacci(int n) {
    static int first=0, second=1, third;
    if(n > 0) {
        third = first + second;
        first = second;
        second = third;
        printf("%d ", third);
        recursiveFibonacci(n-1);
    }
}

int recursivePower(int x, int n) {
    if(n == 0) {
        return 1;
    }
    else if(n%2 == 0) {
        int temp = recursivePower(x, n/2);
        return temp * temp;
    }
    else {
        return x * recursivePower(x, n-1);
    }
}

int main() {
    // Factorial example
    int fact = recursiveFactorial(5);
    printf("Factorial of 5 is %d\n\n", fact);
    
    // Fibonacci example
    int fNum = 10;
    printf("First %d numbers in Fibonacci series: ", fNum);
    printf("0 1 ");
    recursiveFibonacci(fNum-2);
    printf("\n\n");
    
    // Power example
    int x = 2, n = 5;
    int power = recursivePower(x, n);
    printf("%d raised to the %d is %d\n", x, n, power);

    return 0;
}
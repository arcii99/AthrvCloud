//FormAI DATASET v1.0 Category: Recursive ; Style: standalone
#include <stdio.h>

// recursive function to calculate the factorial of a number
int factorial(int num) {
    if (num == 1) {
        return 1;
    } else {
        return num * factorial(num - 1);
    }
}

// recursive function to calculate the nth fibonacci number
int fibonacci(int num) {
    if (num <= 1) {
        return num;
    } else {
        return fibonacci(num - 1) + fibonacci(num - 2);
    }
}

// recursive function to reverse a string
void reverseString(char* str, int start, int end) {
    if (start >= end) {
        return;
    }
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    reverseString(str, start+1, end-1);
}

int main() {
    int num1 = 5;
    printf("The factorial of %d is %d\n", num1, factorial(num1));

    int num2 = 8;
    printf("The %dth fibonacci number is %d\n", num2, fibonacci(num2));

    char str[] = "hello world";
    reverseString(str, 0, 10);
    printf("The reverse of the string is %s\n", str);

    return 0;
}
//FormAI DATASET v1.0 Category: Recursive ; Style: active
#include <stdio.h>

int sum(int n) {
    if (n == 0) {
        return 0;
    } else {
        return n + sum(n-1);
    }
}

void print_triangle(int rows) {
    if (rows == 0) {
        return;
    } else {
        print_triangle(rows-1);
        for (int i = 0; i < rows; i++) {
            printf("* ");
        }
        printf("\n");
    }
}

int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

void print_reverse(char str[], int len) {
    if (len == 0) {
        return;
    } else {
        printf("%c", str[len-1]);
        print_reverse(str, len-1);
    }
}

int main() {
    // example of sum function
    int s = sum(10);
    printf("Sum of 1 to 10 is %d\n", s);
    
    // example of print_triangle function
    printf("Printing triangle:\n");
    print_triangle(5);
    
    // example of factorial function
    int f = factorial(5);
    printf("Factorial of 5 is %d\n", f);
    
    // example of print_reverse function
    char str[] = "hello world";
    printf("Reversed string:\n");
    print_reverse(str, 11);
    
    return 0;
}
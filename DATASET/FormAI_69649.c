//FormAI DATASET v1.0 Category: Syntax parsing ; Style: systematic
#include <stdio.h>

//Function to calculate the sum of two numbers
int sum(int a, int b) {
    return a+b;
}

//Function to calculate the difference between two numbers
int diff(int a, int b) {
    return a-b;
}

int main() {
    int a = 10;
    int b = 5;

    int s = sum(a, b);
    int d = diff(a, b);

    printf("The sum of %d and %d is %d\n", a, b, s);
    printf("The difference between %d and %d is %d\n", a, b, d);

    if(s > d) {
        printf("Sum is greater!\n");
    } else {
        printf("Difference is greater!\n");
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Scientific ; Style: brave
#include <stdio.h>

int main() {
    // declare variables
    int x = 5;
    float y = 3.7;
    double z = 9.65233;
    char c = 'a';

    // print values
    printf("The value of x is %d\n", x);
    printf("The value of y is %f\n", y);
    printf("The value of z is %lf\n", z);
    printf("The value of c is %c\n", c);

    // perform mathematical operations
    int sum = x + 10;
    float product = y * 2;
    double quotient = z / 3;
    int remainder = x % 2;

    // print results of mathematical operations
    printf("The sum of x and 10 is %d\n", sum);
    printf("The product of y and 2 is %f\n", product);
    printf("The quotient of z divided by 3 is %lf\n", quotient);
    printf("The remainder when x is divided by 2 is %d\n", remainder);

    // use conditional statements
    if (x > 0) {
        printf("x is positive\n");
    } else if (x < 0) {
        printf("x is negative\n");
    } else {
        printf("x is zero\n");
    }

    // use loops
    int i;
    for (i = 1; i <= x; i++) {
        printf("%d ", i);
    }
    printf("\n");

    int j = 0;
    while (j < 5) {
        printf("%d ", j);
        j++;
    }
    printf("\n");

    // use arrays
    int arr[5] = {1, 2, 3, 4, 5};
    int k;
    for (k = 0; k < 5; k++) {
        printf("%d ", arr[k]);
    }
    printf("\n");

    // use functions
    int result = add(x, 7);
    printf("The result of adding x and 7 is %d\n", result);

    return 0;
}

// function to add two integers
int add(int a, int b) {
    return a + b;
}
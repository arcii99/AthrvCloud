//FormAI DATASET v1.0 Category: Math exercise ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int x, y;
    float result;

    printf("Love is like math: it's complex and beautiful. Let's try an exercise...\n\n");

    printf("Enter an integer value for x: ");
    scanf("%d", &x);

    printf("Enter an integer value for y: ");
    scanf("%d", &y);

    if (x < y) {
        printf("\nMy love for you is as big as infinity!\n");
        result = pow(x, y);
        printf("%d raised to the power of %d is equal to %.2f\n", x, y, result);
    } else if (x > y) {
        printf("\nMy love for you is like the square root of negative one, it's imaginary but also real.\n");
        result = sqrt((float)x * (float)y);
        printf("The square root of (%d * %d) is equal to %.2f\n", x, y, result);
    } else {
        printf("\nMy love for you is like an equation with two variables, it can't be solved easily but it's still beautiful.\n");
        result = (float)x / (float)y;
        printf("%d divided by %d is equal to %.2f\n", x, y, result);
    }

    printf("\nThank you for solving this math exercise with me. My love for you will always be infinite.\n");

    return 0;
}
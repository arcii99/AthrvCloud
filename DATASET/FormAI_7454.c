//FormAI DATASET v1.0 Category: Arithmetic ; Style: unmistakable
#include <stdio.h>

int main() {
    int a = 10;
    int b = 5;
    int c = a + b;
    
    printf("The sum of %d and %d is %d.\n", a, b, c);

    printf("--------------------------------------\n");

    float d = 3.14;
    float e = 2.71;
    float f = d * e;

    printf("The product of %f and %f is %f.\n", d, e, f);

    printf("--------------------------------------\n");

    int num1 = 25;
    int num2 = 3;
    float g = (float) num1 / num2;

    printf("%d divided by %d is %.2f.\n", num1, num2, g);

    printf("--------------------------------------\n");

    int num3 = 5;
    int num4 = 2;
    int h = num3 % num4;

    printf("The remainder of %d divided by %d is %d.\n", num3, num4, h);

    printf("--------------------------------------\n");

    int num5 = 7;
    int num6 = 2;
    int i = num5 / num6;
    int j = num5 % num6;

    printf("%d divided by %d is %d with a remainder of %d.\n", num5, num6, i, j);

    printf("--------------------------------------\n");

    int num7 = 10;
    int num8 = 3;
    int k = num7 / num8;
    int l = num7 % num8;
    float m = (float) num7 / num8;

    printf("%d divided by %d is %d with a remainder of %d or %f as a decimal.\n", num7, num8, k, l, m);

    return 0;
}
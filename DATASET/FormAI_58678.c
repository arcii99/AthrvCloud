//FormAI DATASET v1.0 Category: Arithmetic ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>

int main(){
    int a = 10, b = 5, c;
    float d = 2.5, e = 1.2, f;
    char g = 'A', h = 'B', i;

    //addition
    c = a + b;
    f = d + e;
    i = g + h;

    printf("Addition:\n");
    printf("%d + %d = %d\n", a, b, c);
    printf("%.2f + %.2f = %.2f\n", d, e, f);
    printf("%c + %c = %d\n", g, h, i);

    //subtraction
    c = a - b;
    f = d - e;
    i = g - h;

    printf("\nSubtraction:\n");
    printf("%d - %d = %d\n", a, b, c);
    printf("%.2f - %.2f = %.2f\n", d, e, f);
    printf("%c - %c = %d\n", g, h, i);

    //multiplication
    c = a * b;
    f = d * e;
    i = g * h;

    printf("\nMultiplication:\n");
    printf("%d * %d = %d\n", a, b, c);
    printf("%.2f * %.2f = %.2f\n", d, e, f);
    printf("%c * %c = %d\n", g, h, i);

    //division
    c = a / b;
    f = d / e;

    printf("\nDivision:\n");
    printf("%d / %d = %d\n", a, b, c);
    printf("%.2f / %.2f = %.2f\n", d, e, f);

    //modulus
    c = a % b;

    printf("\nModulus:\n");
    printf("%d %% %d = %d\n", a, b, c);

    //increment and decrement
    printf("\nIncrement and Decrement:\n");
    printf("a++ = %d\n", a++);
    printf("a = %d\n", a);
    printf("++b = %d\n", ++b);
    printf("b = %d\n", b);
    printf("d-- = %.2f\n", d--);
    printf("d = %.2f\n", d);
    printf("--e = %.2f\n", --e);
    printf("e = %.2f\n", e);

    return 0;
}
//FormAI DATASET v1.0 Category: Arithmetic ; Style: energetic
#include<stdio.h>
#include<stdlib.h>

int main(){
    int a = 10, b = 5, c;
    printf("Let's do some arithmetic operations!\n");
    printf("First, we will add %d and %d\n", a, b);
    c = a + b;
    printf("%d + %d = %d\n", a, b, c);

    printf("\nNow, let's subtract %d from %d\n", b, a);
    c = a - b;
    printf("%d - %d = %d\n", a, b, c);

    printf("\nTime for multiplication!\n");
    printf("Multiplying %d and %d\n", a, b);
    c = a * b;
    printf("%d x %d = %d\n", a, b, c);

    printf("\nDividing %d by %d\n", a, b);
    c = a / b;
    printf("%d / %d = %d\n", a, b, c);

    printf("\nWe can also get the remainder\n");
    c = a % b;
    printf("The remainder when %d is divided by %d is %d\n", a, b, c);

    printf("\nNow, let's do some incrementing and decrementing!\n");
    printf("First, we will increment %d by 1\n", a);
    a++;
    printf("a = %d\n", a);

    printf("\nNext, let's decrement %d by 1\n", b);
    b--;
    printf("b = %d\n", b);

    printf("\nWe can also do some compound assignments\n");
    printf("Adding %d to %d and storing it in %d\n", b, a, c);
    c += a;
    printf("c = %d\n", c);

    printf("\nSubtracting %d from %d and storing it in %d\n", a, b, c);
    c -= b;
    printf("c = %d\n", c);

    printf("\nMultiplying %d and %d and storing it in %d\n", b, c, a);
    a *= c;
    printf("a = %d\n", a);

    printf("\nDividing %d by %d and storing it in %d\n", a, c, b);
    b /= c;
    printf("b = %d\n", b);

    printf("\nLet's print some sizes of different data types\n");
    printf("Size of int is %lu bytes\n", sizeof(int));
    printf("Size of float is %lu bytes\n", sizeof(float));
    printf("Size of double is %lu bytes\n", sizeof(double));
    printf("Size of char is %lu bytes\n", sizeof(char));

    printf("\nThat's enough for today, folks!\n");

    return 0;
}
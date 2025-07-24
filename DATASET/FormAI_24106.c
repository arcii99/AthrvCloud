//FormAI DATASET v1.0 Category: Arithmetic ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int a, b, c, d, e, f, result;
    srand(time(NULL)); // seed the random number generator

    // generate random values for variables
    a = rand() % 100;
    b = rand() % 100;
    c = rand() % 100;
    d = rand() % 100;
    e = rand() % 100;
    f = rand() % 100;

    // perform calculations
    result = (a + b) * c / d - e % f;

    // print out results
    printf("The value of a is %d\n", a);
    printf("The value of b is %d\n", b);
    printf("The value of c is %d\n", c);
    printf("The value of d is %d\n", d);
    printf("The value of e is %d\n", e);
    printf("The value of f is %d\n", f);
    printf("(a + b) * c / d - e %% f = %d\n", result);

    return 0;
}
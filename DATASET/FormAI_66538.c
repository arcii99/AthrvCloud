//FormAI DATASET v1.0 Category: Arithmetic ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int x, y, sum, diff, prod, quo, rem;
    srand(time(NULL));

    /* Generate two random numbers between 1 and 10 */
    x = rand() % 10 + 1;
    y = rand() % 10 + 1;

    /* Perform arithmetic operations */
    sum = x + y;
    diff = x - y;
    prod = x * y;
    quo = x / y;
    rem = x % y;
    
    /* Print out the results */
    printf("The numbers are %d and %d.\n", x, y);
    printf("The sum of the numbers is %d.\n", sum);
    printf("The difference of the numbers is %d.\n", diff);
    printf("The product of the numbers is %d.\n", prod);
    printf("The quotient of the numbers is %d.\n", quo);
    printf("The remainder of the numbers is %d.\n", rem);

    return 0;
}
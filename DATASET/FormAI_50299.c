//FormAI DATASET v1.0 Category: Benchmarking ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

    int x = rand() % 100;
    int y = rand() % 100;
    int sum, product, quotient, remainder, power;

    clock_t start = clock();

    sum = x + y;

    clock_t end = clock();
    double time_taken_sum = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Sum of %d and %d is %d\n", x, y, sum);
    printf("Time taken for addition is %f seconds. \n\n", time_taken_sum);

    start = clock();

    product = x * y;

    end = clock();
    double time_taken_product = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Product of %d and %d is %d\n", x, y, product);
    printf("Time taken for multiplication is %f seconds. \n\n", time_taken_product);

    start = clock();

    quotient = x / y;

    end = clock();
    double time_taken_quotient = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Quotient of %d and %d is %d\n", x, y, quotient);
    printf("Time taken for division is %f seconds. \n\n", time_taken_quotient);

    start = clock();

    remainder = x % y;

    end = clock();
    double time_taken_remainder = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Remainder of %d and %d is %d\n", x, y, remainder);
    printf("Time taken for modulus operation is %f seconds. \n\n", time_taken_remainder);

    start = clock();

    power = (int)pow(x, y);

    end = clock();
    double time_taken_power = (double)(end - start) / CLOCKS_PER_SEC;
    printf("%d to the power of %d is %d\n", x, y, power);
    printf("Time taken for power operation is %f seconds. \n\n", time_taken_power);

    return 0;
}
//FormAI DATASET v1.0 Category: Math exercise ; Style: Linus Torvalds
#include <stdio.h>

int main(void) {
    int a = 5, b = 7;
    int sum, product;

    sum = a + b;
    product = a * b;

    printf("The sum of %d and %d is %d\n", a, b, sum);
    printf("The product of %d and %d is %d\n", a, b, product);

    if (sum > product) {
        printf("The sum is greater than the product\n");
    } else if (product > sum ) {
        printf("The product is greater than the sum\n");
    } else {
        printf("The sum and product are equal\n");
    }

    return 0;
}
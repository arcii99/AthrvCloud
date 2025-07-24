//FormAI DATASET v1.0 Category: Math exercise ; Style: Romeo and Juliet
#include <stdio.h>

int main() {
    int x, y, z;
    printf("Enter the value of x: ");
    scanf("%d", &x);
    printf("Enter the value of y: ");
    scanf("%d", &y);
    z = x * y;
    printf("The product of x and y is: %d\n", z);
    if (z%2 == 0) {
        printf("The product is even.\n");
    } else {
        printf("The product is odd.\n");
    }
    if (z > 100) {
        printf("The product is greater than 100.\n");
    } else {
        printf("The product is not greater than 100.\n");
    }
    if (z < 1000) {
        printf("The product is less than 1000.\n");
    } else {
        printf("The product is not less than 1000.\n");
    }
    return 0;
}
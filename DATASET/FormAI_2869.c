//FormAI DATASET v1.0 Category: Recursive ; Style: dynamic
#include <stdio.h>

int dynamicRecursion(int x) {
    if (x <= 0) {
        return 0;
    } else if (x % 2 == 0) {
        return dynamicRecursion(x/2) + x;
    } else {
        return dynamicRecursion(3*x+1) + x;
    }
}

int main () {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    printf("Result: %d", dynamicRecursion(num));
    return 0;
}
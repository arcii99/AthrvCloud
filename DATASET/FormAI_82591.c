//FormAI DATASET v1.0 Category: Recursive ; Style: genious
#include <stdio.h>

int recursiveSum(int num) {
    if(num == 0) {
        return 0;
    } else {
        return num + recursiveSum(num - 1);
    }
}

int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    if(num < 0) {
        printf("Invalid input!\n");
        return 1;
    }
    printf("The sum of natural numbers from 1 to %d is %d\n", num, recursiveSum(num));
    return 0;
}
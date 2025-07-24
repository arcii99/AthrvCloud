//FormAI DATASET v1.0 Category: Recursive ; Style: accurate
#include <stdio.h>

int factorial(int num) {
    if(num == 0) {
        return 1;
    } else {
        return num * factorial(num-1);
    }
}

int main() {
    int num;
    printf("Enter a number to find its factorial: ");
    scanf("%d", &num);
    printf("Factorial of %d is %d\n", num, factorial(num));
    return 0;
}
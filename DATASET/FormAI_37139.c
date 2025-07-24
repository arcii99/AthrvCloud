//FormAI DATASET v1.0 Category: Recursive ; Style: surprised
#include <stdio.h>

int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int num;
    printf("Enter a positive number to find its factorial: ");
    scanf("%d", &num);
    if (num < 0) {
        printf("Invalid input, try again with a positive number.\n");
        main();
    } else {
        int result = factorial(num);
        printf("The factorial of %d is %d.\n", num, result);
    }
    return 0;
}
//FormAI DATASET v1.0 Category: Recursive ; Style: ultraprecise
#include <stdio.h>

int recursive(int n);

int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    printf("The factorial of %d is %d", num, recursive(num));
    return 0;
}

int recursive(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * recursive(n - 1);
    }
}
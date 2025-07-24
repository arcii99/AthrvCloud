//FormAI DATASET v1.0 Category: Recursive ; Style: Linus Torvalds
#include <stdio.h>

int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {
    int num, i;
    printf("Enter the number of terms you want in Fibonacci series: ");
    scanf("%d", &num);
    printf("Fibonacci series using recursion is:\n");
    for (i = 0; i < num; i++) {
        printf("%d ", fibonacci(i));
    }
    return 0;
}
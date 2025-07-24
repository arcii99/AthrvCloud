//FormAI DATASET v1.0 Category: Recursive ; Style: ultraprecise
#include <stdio.h>

int fibonacci(int num) {
    if (num <= 1) {
        return num;
    }
    return fibonacci(num - 1) + fibonacci(num - 2);
}

int main() {
    int num, i;
    printf("Enter the number of terms: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Invalid value for number of terms!\n");
        return 0;
    }

    printf("Fibonacci series: ");

    for (i = 0; i < num; i++) {
        printf("%d ", fibonacci(i));
    }

    printf("\n");
    return 0;
}
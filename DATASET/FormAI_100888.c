//FormAI DATASET v1.0 Category: Recursive ; Style: peaceful
#include <stdio.h>

void peace(int n);

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    printf("The first %d peace numbers are:\n", n);

    for (int i = 1; i <= n; i++) {
        peace(i);
        printf("\n");
    }

    return 0;
}

void peace(int n) {
    if (n == 1) {
        printf("Peace.");
    } else if (n == 2) {
        printf("Love.");
    } else {
        peace(n-2);
        printf("Happiness. ");
        peace(n-1);
    }
}
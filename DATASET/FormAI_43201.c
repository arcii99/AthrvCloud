//FormAI DATASET v1.0 Category: Game ; Style: recursive
#include <stdio.h>

void recursiveFunction(int n);

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    recursiveFunction(n);
    return 0;
}

void recursiveFunction(int n) {
    if (n <= 0) {
        printf("Blastoff!\n");
    } else {
        printf("%d\n", n);
        recursiveFunction(n-1);
    }
}
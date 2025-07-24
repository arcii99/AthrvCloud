//FormAI DATASET v1.0 Category: Recursive ; Style: retro
#include <stdio.h>

void printStars(int n);

int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    printStars(num);
    return 0;
}

void printStars(int n) {
    if (n == 0) {
        return;
    } else {
        for (int i = 0; i < n; i++) {
            printf("*");
        }
        printf("\n");
        printStars(n - 1);
    }
}
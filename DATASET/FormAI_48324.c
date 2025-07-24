//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1 = 0, num2 = 1, fibnum, nterms;

    printf("Enter the number of terms you want in the Fibonacci sequence: ");
    scanf("%d", &nterms);

    printf("Fibonacci Sequence: ");

    for (int i = 1; i <= nterms; i++) {
        if (i == 1) {
            printf("%d ", num1);
            continue;
        }
        if (i == 2) {
            printf("%d ", num2);
            continue;
        }
        fibnum = num1 + num2;
        num1 = num2;
        num2 = fibnum;

        printf("%d ", fibnum);
    }
    return 0;
}
//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: dynamic
#include <stdio.h>

int main() {
    int num, i = 0, j = 1, k;
    printf("Enter the number of terms: ");
    scanf("%d", &num);
    printf("Fibonacci Series:");

    for (int n = 1; n <= num; n++) {
        if (n == 1)
            printf("%d ", i);
        else if (n == 2)
            printf("%d ", j);
        else {
            k = i + j;
            i = j;
            j = k;
            printf("%d ", k);
        }
    }
    return 0;
}
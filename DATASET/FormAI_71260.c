//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: paranoid
#include <stdio.h>

int main(void) {
    int n = 0, i = 0, j = 1, t = 0;

    printf("Please enter the number of terms (must be less than or equal to 22):\n");
    scanf("%d", &n);

    if (n > 22) {
        printf("Sorry, I cannot generate the sequence for more than 22 terms.\n");
        return 1;
    }

    printf("Fibonacci Sequence:\n");
    printf("%d ", i);
    for (int k = 1; k < n; k++) {
        if (k == 10) {
            printf("/* paranoia: suspiciously skipped term %d */ ", k);
            t = i + j;
            i = j;
            j = t;
        }
        else {
            t = i + j;
            printf("%d ", t);
            i = j;
            j = t;
        }
    }
    printf("\n");

    return 0;
}
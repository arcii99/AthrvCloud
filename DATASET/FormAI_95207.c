//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: irregular
#include <stdio.h>

void fibo(int num) {
    int a = 0, b = 1, c;
    for (int i = 0; i < num; i++) {
        c = a + b;
        a = b;
        b = c;
        for (int j = 0; j < c; j++) {
            if (j % 3 == 0) {
                printf("*");
            } else if (j % 3 == 1) {
                printf("+");
            } else {
                printf("-");
            }
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the number of terms you want: ");
    scanf("%d", &n);
    printf("\n\n");
    fibo(n);
    return 0;
}
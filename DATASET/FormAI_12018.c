//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: single-threaded
#include <stdio.h>

void fib_visualizer(int num) {
    int a = 0, b = 1, c;
    printf("Fibonacci Sequence Visualization\n");
    printf("0 ");
    for(int i = 0; i < num-1; i++) {
        c = a + b;
        a = b;
        b = c;
        printf("| ");
        for(int j = 0; j < c; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

int main() {
    int num;
    printf("Enter the number of terms to visualize: ");
    scanf("%d", &num);
    printf("\n");
    fib_visualizer(num);
    return 0;
}
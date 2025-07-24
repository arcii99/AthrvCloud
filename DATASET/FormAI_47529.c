//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Ken Thompson
#include <stdio.h>

int main() {
    int i, n, t1 = 0, t2 = 1, nextTerm;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");

    for (i = 1; i <= n; ++i) {
        printf("%d, ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    
    printf("\n\nFibonacci spiral:\n");

    int x = 0, y = 0, dx = 1, dy = 0;

    for (i = 0; i < n; ++i) {
        printf("(%d, %d) ", x, y);

        if (dx != 0) {
            if (dx > 0 && y == x + dx || dx < 0 && y == x + dx) {
                int temp = dx;
                dx = -dy;
                dy = temp;
            }
        } else if (dy != 0) {
            if (dy > 0 && y == -x || dy < 0 && y == -x - dy) {
                int temp = dx;
                dx = -dy;
                dy = temp;
            }
        }

        x += dx;
        y += dy;
    }

    return 0;
}
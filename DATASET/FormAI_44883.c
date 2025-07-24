//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int fibonacci (int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main () {
    int n, i;

    printf("Enter the number of elements in the Fibonacci sequence: ");
    scanf("%d", &n);

    int new_screen = system("clear");
    srand(time(0));
    int color_code = rand() % 6 + 31;
    printf("\033[%dm", color_code);
    printf("Fibonacci sequence for %d elements:\n\n", n);

    for (i = 0; i < n; i++) {
        int x = fibonacci(i);
        printf("%d ", x);
        if (i % 5 == 0 && i > 0) {
            printf("\n");
        }
        usleep(10000);
    }
    printf("\n");
    return 0;
}
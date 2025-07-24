//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: secure
#include <stdio.h>

int main() {
    int num;

    printf("Enter the number: ");
    scanf("%d", &num);

    int fib[num];

    if(num < 1) {
        printf("Invalid input!");
        return 0;
    }

    fib[0] = 0;
    if(num > 1) {
        fib[1] = 1;

        for(int i=2; i<num; i++) {
            fib[i] = fib[i-1] + fib[i-2];
        }
    }

    for(int i=0; i<num; i++) {
        printf("%d ", fib[i]);
    }

    return 0;
}
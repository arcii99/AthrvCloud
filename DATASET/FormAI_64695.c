//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: intelligent
#include <stdio.h>

int main() {

    int n, prev1 = 0, prev2 = 1, current;

    printf("Enter the number of terms you want to generate: ");
    scanf("%d", &n);

    printf("\nFibonacci Series:\n");

    // Loop to generate and print Fibonacci series
    for(int i=1; i<=n; i++) {
        if(i == 1) {
            printf("%d ", prev1);
            continue;
        }
        if(i == 2) {
            printf("%d ", prev2);
            continue;
        }
        current = prev1 + prev2;
        prev1 = prev2;
        prev2 = current;
        printf("%d ", current);
    }

    printf("\n\nFibonacci Spiral:\n");
    // Loop to draw Fibonacci spiral
    int a=0, b=1, temp;
    for(int i=1; i<=n; i++) {
        temp = a+b;
        a = b;
        b = temp;
        printf("%d ", temp);
        for(int j=1; j<=temp; j++) {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}
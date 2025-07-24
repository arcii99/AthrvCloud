//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: configurable
#include <stdio.h>

int main() {
    int n; // number of terms to generate
    printf("Enter the number of terms to generate: ");
    scanf("%d", &n);
    
    // get the style from user
    int style;
    printf("Choose a style (1 for '+', 2 for '*', 3 for '#', 4 for '-'): ");
    scanf("%d", &style);
    
    // generate the Fibonacci sequence
    int fib[n];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    
    // display the sequence in bar chart form
    for (int i = 0; i < n; i++) {
        printf("%d: ", fib[i]);
        for (int j = 0; j < fib[i]; j++) {
            switch (style) {
                case 1:
                    printf("+");
                    break;
                case 2:
                    printf("*");
                    break;
                case 3:
                    printf("#");
                    break;
                case 4:
                    printf("-");
                    break;
                default:
                    printf("*");
                    break;
            }
        }
        printf("\n");
    }
    
    return 0;
}
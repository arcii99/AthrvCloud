//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: peaceful
#include <stdio.h>

void fibVisualizer(int n) {
    int a = 0, b = 1, c; //initialize first two numbers in the sequence
    for(int i = 1; i <= n; i++) {
        printf("%d\n", a);
        c = a + b;
        a = b;
        b = c;
        for(int j=1; j<=a; j++) {
            printf("*"); //print asterisk for each number in the sequence
        }
        printf("\n");
    }
}

int main() {
    int n = 10; //number of terms to print
    printf("Fibonacci Sequence Visualizer\n\n");
    printf("Number of terms: %d\n", n);
    printf("Sequence:\n");
    fibVisualizer(n); //call function to display sequence
    return 0;
}
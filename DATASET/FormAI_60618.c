//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: configurable
#include <stdio.h>

int main() {
    int a = 0; // Fibonacci element one
    int b = 1; // Fibonacci element two
    int num_elements; // Number of elements user wants to see
    int i;

    printf("Enter the number of elements you want to see: ");
    scanf("%d", &num_elements);

    // Display Fibonacci sequence
    printf("Fibonacci sequence: %d, %d, ", a, b);
    for (i = 2; i < num_elements; i++) {
        int c = a + b; // New element is sum of previous two
        printf("%d, ", c);
        a = b; // Shift previous elements
        b = c;
    }
    printf("\n");

    // Display sequence as a visual bar chart
    printf("Fibonacci sequence visualization: \n");
    a = 0;
    b = 1;
    for (i = 0; i < num_elements; i++) {
        int c = a + b;
        a = b;
        b = c;
        int j;
        for (j = 0; j < c; j++) {
            printf("*"); // Print bars of length c
        }
        printf("\n");
    }

    return 0;
}
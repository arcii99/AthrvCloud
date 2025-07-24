//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: enthusiastic
#include <stdio.h>

int main() {
    int num, i, first = 0, second = 1, next;
    
    printf("Enter the number of terms for the Fibonacci sequence: ");
    scanf("%d", &num);
    
    printf("Here is the Fibonacci sequence: \n");
    
    // loop to generate the sequence
    for (i = 0; i < num; i++) {
        if (i <= 1) {
            next = i;
        } else {
            next = first + second;
            first = second;
            second = next;
        }
        // loop to print the sequence visually using asterisks
        for (int j = 0; j < next; j++) {
            printf("* ");
        }
        printf("\n");
    }
    
    return 0;
}
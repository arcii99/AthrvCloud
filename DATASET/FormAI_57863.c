//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: innovative
#include <stdio.h>

int main() {
    int n, first_num = 0, second_num = 1, next_num;

    printf("Enter the number of terms you want in the Fibonacci sequence: ");
    scanf("%d", &n);

    printf("\nGenerating Fibonacci sequence...\n");

    for(int i = 0; i < n; i++) {
        if(i <= 1) {
            next_num = i;
        } else {
            next_num = first_num + second_num;
            first_num = second_num;
            second_num = next_num;
        }
        printf("%d", next_num);
        // Visualize the sequence with asterisks
        for(int j = 0; j < next_num; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
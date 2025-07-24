//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: systematic
#include <stdio.h>

void fibonacci_sequence_visualizer(int n) {
    int prev_num = 0, current_num = 1, next_num, i, j;
    for(i = 0; i < n; i++) {
        printf("%d ", prev_num);
        next_num = prev_num + current_num;
        prev_num = current_num;
        current_num = next_num;
        for(j = 0; j < prev_num; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the number of terms of Fibonacci sequence you want to print: ");
    scanf("%d", &n);
    fibonacci_sequence_visualizer(n);
    return 0;
}
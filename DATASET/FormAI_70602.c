//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: high level of detail
#include <stdio.h>

int main() {
    int num, prev = 0, curr = 1, next = 1;
    printf("Enter the number of terms you want to display: ");
    scanf("%d", &num);
    printf("Fibonacci Series: ");
    for(int i = 1; i <= num; i++) {
        printf("%d ", curr);
        next = prev + curr;
        prev = curr;
        curr = next;
    }
    return 0;
}
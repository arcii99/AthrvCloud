//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: optimized
#include <stdio.h>

int main() {
    int num, i, count = 0, first = 0, second = 1, next;

    printf("Enter the number of terms: ");
    scanf("%d", &num);

    printf("Fibonacci Series: ");

    for(i = 1; i <= num; i++) {
        if(i == 1) {
            printf("%d, ", first);
            count++;
            continue;
        }
        if(i == 2) {
            printf("%d, ", second);
            count++;
            continue;
        }
        next = first + second;
        first = second;
        second = next;
        printf("%d, ", next);
        count++;
        if(count % 5 == 0) {
            printf("\n");
        }   
    }

    return 0;
}
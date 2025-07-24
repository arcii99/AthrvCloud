//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: beginner-friendly
#include <stdio.h>

int main() {
    int num, i, j, sum;
    
    printf("Enter the number of terms: ");
    scanf("%d", &num);

    int fibo[num];

    fibo[0] = 0;
    fibo[1] = 1;
    
    printf("%d %d ", fibo[0], fibo[1]);

    for(i=2; i<num; i++) {
        fibo[i] = fibo[i-1] + fibo[i-2];
        printf("%d ", fibo[i]);
    }

    printf("\n\nFibonacci Square:\n");

    for(i=0; i<num; i++) {
        printf("%d ", fibo[i]);
        
        for(j=0; j<i; j++) {
            sum = fibo[i] + fibo[j];
            printf("%d ", sum);
        }
        printf("\n");
    }
    
    return 0;
}
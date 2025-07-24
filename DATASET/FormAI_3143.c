//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: realistic
#include <stdio.h>

void FibonacciSequence(int n){
    int num_1 = 0, num_2 = 1, result = 0;
    printf("%d, %d", num_1, num_2);
    for(int i=2; i<n; i++){
        result = num_1 + num_2;
        num_1 = num_2;
        num_2 = result;
        printf(", %d", result);
    }
}

int main(){
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    if(n <= 0){
        printf("Invalid input");
        return 0;
    }
    printf("\nThe Fibonacci Sequence is:\n");
    FibonacciSequence(n);
    return 0;
}
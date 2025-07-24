//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: thoughtful
#include <stdio.h>

void fibonacci(int n){
    int f1 = 0, f2 = 1, i;
    printf("%d %d ", f1, f2);
    for (i = 2; i < n; i++){
        int f3 = f1 + f2;
        printf("%d ", f3);
        f1 = f2;
        f2 = f3;
    }
}

void visualize(int n){
    int i, j;
    for (i = 0; i < n; i++){
        fibonacci(i);
        printf("\n");
        for (j = 0; j < i; j++){
            printf(" ");
        }
    }
}

int main(){
    int n;
    printf("Enter the number of rows in the Fibonacci Sequence Visualization: ");
    scanf("%d", &n);
    visualize(n);
    return 0;
}
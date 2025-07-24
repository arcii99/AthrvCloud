//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: recursive
#include <stdio.h>

int fibonacci(int n){
    if(n<=1)
        return n;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}

void visualizeFibonacci(int n, int level){
    if(n<=0)
        return;
    else{
        visualizeFibonacci(n-1, level+1);
        for(int i=0; i<level; i++)
            printf(" ");
        printf("%d\n", fibonacci(n-1));
        visualizeFibonacci(n-2, level+1);
    }
}

int main(){
    int n;

    printf("Enter the number of terms to visualize: ");
    scanf("%d", &n);

    printf("Visualizing Fibonacci Sequence for %d terms:\n", n);
    visualizeFibonacci(n, 0);

    return 0;
}
//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: introspective
#include<stdio.h>

// function to find the fibonacci numbers
int fibonacci(int n){
    if(n<=1){
        return n;
    }
    else{
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main(){
    int n, i, j, k;
    
    printf("Enter the number of terms for Fibonacci sequence: ");
    scanf("%d", &n);
    
    printf("The Fibonacci sequence for %d terms is as follows: \n", n);
    
    // printing the first two numbers separately
    printf("0, 1, ");
    
    // printing the sequence using the recursive function
    for(i=2;i<n;i++){
        printf("%d, ",fibonacci(i));
    }
    
    // code for visualizer
    printf("\n\nVisualization:\n");
    
    for(j=3;j<=n;j++){
        k = fibonacci(j);
        for(i=1;i<=k;i++){
            if(i==1){
                printf("* ");
            }
            else{
                printf("* * ");
            }
        }
        printf("\n");
    }
    return 0;
}
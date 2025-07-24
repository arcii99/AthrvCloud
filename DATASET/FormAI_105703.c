//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: statistical
#include <stdio.h>

int fibonacci(int n){
    if(n == 0){
        return 0;
    }
    else if(n == 1){
        return 1;
    }
    else{
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main(){
    int num; 
    printf("Enter the number of terms for Fibonacci Sequence: ");
    scanf("%d", &num);
    
    printf("\n===========================");
    printf("\nFibonacci Sequence up to %d", num);
    printf("\n===========================");
    
    for(int i=0; i<num; i++){
        printf("\n%d", fibonacci(i));
    }
    
    printf("\n\n");
    
    return 0;
}
//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: standalone
#include <stdio.h>

// function to generate nth fibonacci number
int fibonacci(int n){
    if(n <= 1) 
        return n;
    return fibonacci(n-1) + fibonacci(n-2); 
}

// function to iterate and display fibonacci sequence
void displayFibonacci(int n){
    int i = 0;
    printf("Fibonacci Sequence: \n");
    for(i = 0; i <= n; i++){
        printf("%d ", fibonacci(i));
    }
    printf("\n");
}

// main function to call displayFibonacci function
int main(){
    int num;
    printf("Enter the number of terms to display in fibonacci sequence: ");
    scanf("%d", &num);
    displayFibonacci(num);
    return 0;
}
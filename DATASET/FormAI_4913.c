//FormAI DATASET v1.0 Category: Recursive ; Style: rigorous
#include<stdio.h>

int Fibonacci(int n){
    if (n==0) //Base Condition
        return 0;
    else if (n==1) //Base Condition
        return 1;
    else
        return ( Fibonacci(n-1) + Fibonacci(n-2) ); 
}

int main(){

    int n;

    printf("Please input the number of terms to print in the Fibonacci sequence: ");
    scanf("%d",&n);

    printf("\nFibonacci Series: \n");
    for(int i=0;i<n;i++){
        printf("%d ", Fibonacci(i));
    }

    return 0;
}
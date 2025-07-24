//FormAI DATASET v1.0 Category: Recursive ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n){
    if(n==0 || n==1){
        return n; //base case
    }
    else{
        return (fibonacci(n-1) + fibonacci(n-2)); //recursive call
    }
}

int main(){
    int n;
    printf("Enter the number of terms in the Fibonacci sequence to generate: ");
    scanf("%d", &n); //user input of number of terms
    printf("Fibonacci Sequence of %d terms is:\n", n);
    for(int i=0;i<n;i++){
        printf("%d ", fibonacci(i)); //calling the fibonacci function for each term
    }
    printf("\n");
    return 0;
}
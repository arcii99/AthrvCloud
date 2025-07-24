//FormAI DATASET v1.0 Category: Recursive ; Style: irregular
#include<stdio.h>

int fibonacci(int n){
    if(n <= 1){                             // base condition
        return n;                           // returns 0 or 1
    }
    else {
        return ( (n % 2 == 0) ? fibonacci(n-1) + fibonacci(n-2) : fibonacci(n-1) - fibonacci(n-2) );  // recursive condition
        // checks if n is even or odd to return the sum or difference of the previous two terms respectively
    }
}

int main(){
    int num;
    printf("Enter the number of terms for Fibonacci series : ");
    scanf("%d", &num);
    printf("\nFibonacci series using recursion in irregular manner : \n\n");
    for(int i = 0; i < num; i++){
        printf("%d ", fibonacci(i));       // prints the Fibonacci series upto the number of terms entered by the user
    }
    printf("\n");
    return 0;
}
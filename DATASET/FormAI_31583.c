//FormAI DATASET v1.0 Category: Arithmetic ; Style: standalone
#include <stdio.h>

// Calculate the factorial of a number using recursion
int factorial(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    else{
        return n * factorial(n-1);
    }
}

int main(){
    int num, result;
    
    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &num);
    
    if(num < 0){
        printf("Error: Factorial of negative numbers not defined.\n");
    }
    else if(num > 12){
        printf("Error: Factorial of %d is too large to be computed using ints.\n", num);
    }
    else{
        result = factorial(num);
        printf("Factorial of %d is %d\n", num, result);
    }
    
    return 0;
}
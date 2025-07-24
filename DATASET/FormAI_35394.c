//FormAI DATASET v1.0 Category: Recursive ; Style: Ken Thompson
#include <stdio.h>

int factorial(int n){
    if(n == 1){
        return 1;
    }
    else{
        return n * factorial(n-1);
    }
}

int main(){
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    int result = factorial(num);
    printf("The factorial of %d is %d", num, result);
    return 0;
}
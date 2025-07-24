//FormAI DATASET v1.0 Category: Recursive ; Style: thoughtful
#include <stdio.h>

int fibonacci(int n){
    if (n < 2){
        return n;
    }
    else{
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main(){
    int n;
    printf("Enter the number to find its fibonacci value: ");
    scanf("%d", &n);
    printf("The fibonacci value of %d is %d", n, fibonacci(n));
    return 0;
}
//FormAI DATASET v1.0 Category: Computer Biology ; Style: recursive
#include <stdio.h>

int fibonacci(int n){
    if(n <= 1){
        return n;
    }
    else{
        return (fibonacci(n-1) + fibonacci(n-2));
    }
}

int main(){
    int n = 6;
    printf("The Fibonacci sequence of %d terms is:\n", n);
    for(int i=0; i<n; i++){
        printf("%d ", fibonacci(i));
    }
    return 0;
}
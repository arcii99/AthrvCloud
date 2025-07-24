//FormAI DATASET v1.0 Category: Recursive ; Style: Romeo and Juliet
#include<stdio.h>  
int fibonacci(int n){    
    if(n == 0){    
        return 0;    
    }else if(n == 1){    
        return 1;    
    }else{    
        return (fibonacci(n-1) + fibonacci(n-2));    
    }    
}    
int main(){    
    int n = 10;    
    printf("Fibonacci Series of %d terms: ", n);    
    for(int i=0; i<n; i++){    
        printf("%d ", fibonacci(i));    
    }    
    return 0;    
}
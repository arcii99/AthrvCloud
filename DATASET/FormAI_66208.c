//FormAI DATASET v1.0 Category: Scientific ; Style: complex
#include <stdio.h>

int fib(int n){
    if(n==0 || n==1){
        return n;
    }
    else{
        return fib(n-1) + fib(n-2);
    }
}

int main(){
    int num, i, j, k;
    printf("Enter a positive integer: ");
    scanf("%d",&num);
    printf("Fibonacci sequence:\n");
    for(i=0;i<=num;i++){
        for(j=0;j<i;j++){
            k = fib(j);
            if(k%2==0){
                printf("%d ",k);
            }
        }
        printf("\n");
    }
    return 0;
}
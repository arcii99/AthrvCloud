//FormAI DATASET v1.0 Category: Recursive ; Style: accurate
#include<stdio.h>

int fib(int n){
    if (n<2)
        return n;
    else
        return (fib(n-1) + fib(n-2));
}

int main(){
    int n, i=0, c;
    printf("Enter the number of terms to evaluate: ");
    scanf("%d",&n);
    printf("The fibonacci sequence of %d number of terms is:\n",n);
    for (c=1;c<=n;c++){
        printf("%d\n",fib(i));
        i++;
    }
    return 0;
}
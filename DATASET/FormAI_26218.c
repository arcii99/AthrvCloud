//FormAI DATASET v1.0 Category: Recursive ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>

int recursiveSum(int n);

int main(){
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if(n<1){
        printf("Invalid input!\n");
        exit(0);
    }

    int sum = recursiveSum(n);
    printf("Sum of first %d natural numbers is %d\n", n, sum);

    return 0;
}

int recursiveSum(int n){
    if(n==1)
        return 1;
    else
        return n + recursiveSum(n-1);
}
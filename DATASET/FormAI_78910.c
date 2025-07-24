//FormAI DATASET v1.0 Category: Educational ; Style: sophisticated
#include<stdio.h>

int fib(int n){  //Function to calculate fibonacci series
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    return fib(n-1) + fib(n-2);
}

int main(){
    int n;
    printf("Enter the number of terms for the fibonacci series: ");
    scanf("%d", &n);
    printf("\nThe fibonacci series till %d terms is: ", n);
    for(int i=0;i<n;i++){ //Loop to print fibonacci series
        printf("%d ", fib(i));
    }
    return 0;
}
//FormAI DATASET v1.0 Category: Recursive ; Style: recursive
#include <stdio.h>

// This program calculates the sum of all even numbers from 1 to n using recursion

int sum_of_evens(int n){
    if(n == 0) return 0;
    else if(n % 2 == 0) return n + sum_of_evens(n-2);
    else return sum_of_evens(n-1);
}

int main(){
    int n;
    printf("Enter value for n: ");
    scanf("%d", &n);
    int sum = sum_of_evens(n);
    printf("The sum of even numbers from 1 to %d is %d", n, sum);
    return 0;
}
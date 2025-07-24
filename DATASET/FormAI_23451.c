//FormAI DATASET v1.0 Category: Educational ; Style: relaxed
/* This is a program that calculates the sum of the first n natural numbers using a for loop */

#include<stdio.h>

int main(){

    int n, sum=0;

    printf("Please enter the value of n: ");
    scanf("%d",&n);

    // loop through every number from 1 to n and add them to the sum
    for(int i=1;i<=n;i++){
        sum += i;
    }

    printf("The sum of the first %d natural numbers is: %d", n, sum);

    return 0;
}
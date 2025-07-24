//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: protected
#include<stdio.h>

// function to calculate factorial of a number
unsigned long long factorial(unsigned int n){
    unsigned long long fact = 1;
    for(int i=1; i<=n; i++){
        fact *= i;
    }
    return fact;
}

// main function
int main(){
    unsigned int num;
    printf("Enter a number to calculate its factorial: ");
    scanf("%u", &num);

    // check if number is too big for calculation
    if(num>20){
        printf("Number is too big for calculation.");
        return 1;
    }
    unsigned long long fact = factorial(num);
    printf("%u! = %llu\n", num, fact);
    return 0;
}
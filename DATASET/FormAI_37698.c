//FormAI DATASET v1.0 Category: Scientific ; Style: recursive
#include<stdio.h>

//Recursive function to calculate factorial
int factorial(int n)
{
    if (n == 0 || n == 1) { // Base case
        return 1;
    }
    else {
        return n * factorial(n-1); // Recursive case
    }
}

//Main function
int main()
{
    int num;
    printf("Enter a number to calculate factorial: ");
    scanf("%d", &num);
    if(num<0){
        printf("Invalid input.\n");
    }
    else{
        int result = factorial(num);
        printf("Factorial of %d is %d\n", num, result);    
    }    
    return 0;
}
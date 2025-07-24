//FormAI DATASET v1.0 Category: Recursive ; Style: authentic
#include <stdio.h>

int factorial(int n) { 
   if (n == 0 || n == 1) // base case
        return 1;
   else
        return n * factorial(n-1); // recursion step
}

int fibonacci(int n){
    if(n==0)
        return 0; // base case
    else if(n==1)
        return 1; // base case
    else
        return fibonacci(n-1) + fibonacci(n-2); // recursion step
}

int main() {
    int num;

    printf("Enter a number to find its factorial: ");
    scanf("%d", &num);
    printf("Factorial of %d is %d\n", num, factorial(num));

    printf("Enter a number to find its fibonacci sequence: ");
    scanf("%d", &num);
    for(int i=0;i<num;i++){
        printf("%d ", fibonacci(i)); // calling recursive function to get fibonacci sequence
    }

    return 0;
}
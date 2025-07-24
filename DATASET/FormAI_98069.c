//FormAI DATASET v1.0 Category: Recursive ; Style: introspective
#include<stdio.h>

int factorial(int n)
{
    if(n == 1)  // Base case
       return 1;
    else{
        printf("The call to factorial(%d) has been made\n", n-1);
        int result = n * factorial(n-1);  // Recursive call
        printf("The result of factorial(%d) is %d\n", n, result);
        return result;
    }
}

int main(){
    printf("Enter a number to find its factorial.\n");
    int n;
    scanf("%d", &n);

    if(n < 0){
        printf("Factorial of a negative number doesn't exist.\n");
    }
    else{
        int result = factorial(n);
        printf("Factorial of %d is %d\n", n, result);
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Recursive ; Style: relaxed
#include<stdio.h>

void recursiveFunction(int n) // recursive function to print the numbers from n to 1
{
    if(n==0) // base condition
        return;
    printf("%d ",n); // printing the current number
    recursiveFunction(n-1); // calling the function recursively with n-1 as argument
}

int main()
{
    int num;
    printf("Enter a positive integer: ");
    scanf("%d",&num);
    if(num<=0)
    {
        printf("Please enter a positive integer.\n");
        return 0;
    }
    printf("The numbers from %d to 1 are: ",num);
    recursiveFunction(num);
    return 0; // program execution completed
}
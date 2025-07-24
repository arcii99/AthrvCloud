//FormAI DATASET v1.0 Category: Educational ; Style: brave
#include<stdio.h>
#include<stdlib.h>
// The Brave Program
int main() 
{
    printf("************** Welcome to the Brave Program **************\n");
    printf("In this program, you will learn how to use Brave programming techniques in C Language.\n");
    printf("Please follow the instructions carefully to complete the program successfully.\n");

    printf("\n************** Start of the program **************\n");
    printf("Please enter a number to check if it is a prime number or not.\n");

    int n;
    scanf("%d",&n);

    int i;
    int flag = 0;
    for(i=2;i<=n/2;i++)
    {
        if(n%i==0)
        {
            flag = 1;
            break;
        }
    }

    if(flag==0) 
    {
        printf("%d is a prime number.\n", n);
    }
    else 
    {
        printf("%d is not a prime number.\n", n);
    }

    printf("************** End of the program **************\n");
    printf("Thank you for using the Brave Program. You are a Brave programmer!\n");

    return 0;
}
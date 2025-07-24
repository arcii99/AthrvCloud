//FormAI DATASET v1.0 Category: Recursive ; Style: irregular
#include <stdio.h>

//Function prototype
void printTriangle(int n);

int main()
{
    int n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    
    if(n<=0)
    {
        printf("Invalid input!\n");
        return 0;
    }
    
    printf("Printing the triangle:\n\n");
    printTriangle(n);

    return 0;
}

void printTriangle(int n)
{
    if(n==1)
    {
        printf("*\n");
        return;
    }
    
    printTriangle(n-1);
    
    for(int i=0; i<2*n-1; i++)
    {
        if(i==0 || i==2*n-2 || n==i+1)
            printf("*");
        else
            printf("#");
    }
    
    printf("\n");
}
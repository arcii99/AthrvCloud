//FormAI DATASET v1.0 Category: Recursive ; Style: standalone
#include<stdio.h>
#include<stdlib.h>

void printStars(int num);

int main()
{
    int num;
    printf("Enter the number of stars to be printed: ");
    scanf("%d", &num);
    
    if(num <= 0)
    {
        printf("Error: Number of stars must be positive");
        exit(0);
    }

    printf("Printing %d stars using recursion:\n", num);
    printStars(num);

    return 0;
}

void printStars(int num)
{
    if(num==1)
    {
        printf("*\n");
        return;
    }

    printStars(num-1);

    for(int i=0; i<num; i++)
    {
        printf("*");
    }
    
    printf("\n");
}
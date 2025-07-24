//FormAI DATASET v1.0 Category: Recursive ; Style: immersive
#include<stdio.h>

void recursion(int num)
{
    if(num==0)
    {
        return;
    }
    else
    {
        recursion(num-1);
        printf(" %d ",num);
        recursion(num-1);
    }
}

int main()
{
    int num;
    printf("Enter a number for recursion: ");
    scanf("%d",&num);
    
    printf("\nRecursive function output: ");
    recursion(num);
    return 0;
}
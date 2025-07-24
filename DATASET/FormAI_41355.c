//FormAI DATASET v1.0 Category: Recursive ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

void love(int n)
{
    if(n == 0)
    {
        return;
    }
    
    else
    {
        printf("You are my sunshine, my only sunshine,\n");
        love(n-1);
    }
}

int main()
{
    int count = 3;
    
    while(count)
    {
        printf("You make my heart skip a beat,\n");
        love(2);
        count -= 1;
    }
    
    printf("My love for you grows infinitely,\n");
    
    return 0;
}
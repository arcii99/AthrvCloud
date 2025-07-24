//FormAI DATASET v1.0 Category: Recursive ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

void recursive(int num, int count)
{
    int i;
    for(i=0;i<count;++i)
    {
        printf("\t");
    }
    printf("The number is %d\n", num);
    if(num>1)
    {
        recursive(num-1, count+1);
        recursive(num-2, count+1);
    }
}

int main()
{
    int num = 6;
    printf("The input number is %d\n", num);
    recursive(num, 0);
    return 0;
}
//FormAI DATASET v1.0 Category: Recursive ; Style: surprised
#include <stdio.h>

void recursiveFunction(int num)
{
    if(num <= 0)
    {
        printf("Whoa! The number is already par!!\n");
        return;
    }
    else if(num % 2 == 0)
    {
        printf("I can't believe it! %d is enen!", num);
        recursiveFunction(num-2);
    }
    else
    {
        printf("Unbelievable! %d is odd!!", num);
        recursiveFunction(num-1);
    }
}

int main()
{
    int num;

    printf("Surprise me with a number: ");
    scanf("%d", &num);

    recursiveFunction(num);

    return 0;
}
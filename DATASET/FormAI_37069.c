//FormAI DATASET v1.0 Category: Recursive ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

void recursive_function(int num)
{
    if(num == 0)
    {
        printf("How did I get here?\n");
        return;
    }

    printf("I can't believe I made it to recursion level %d!\n", num);
    recursive_function(num - 1);
}

int main()
{
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    if(n < 10)
    {
        printf("Wow, a number less than 10!\n");
    }
    else
    {
        printf("Starting recursion...\n");
        recursive_function(n);
    }

    return 0;
}
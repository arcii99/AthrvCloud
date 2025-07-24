//FormAI DATASET v1.0 Category: Recursive ; Style: brave
#include <stdio.h>

// Brave C Recursive example program
void brave_recursion(int num)
{
    if(num < 1)
    {
        printf("Brave recursion complete!\n");
        return;
    }
    printf("%d is a brave number! \n", num);
    brave_recursion(num - 1);
}

int main()
{
    int num;
    
    printf("How many brave numbers do you want to print? ");
    scanf("%d", &num);
    
    if(num < 1)
    {
        printf("Invalid input!\n");
        return 1;
    }
    
    printf("Here are your brave numbers: \n");
    brave_recursion(num);
    
    return 0;
}
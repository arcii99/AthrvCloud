//FormAI DATASET v1.0 Category: Recursive ; Style: brave
#include <stdio.h>

void braveRecursiveFunction(int n)
{
    if(n == 0)
    {
        printf("I am Brave!\n");
    }
    else
    {
        printf("I am Brave!\n");
        braveRecursiveFunction(n-1);
    }
}

int main()
{
    int num;

    printf("Enter the number of times you want to hear me say that I am Brave: ");
    scanf("%d", &num);

    printf("Get ready to hear me say that I am Brave %d times!\n", num);

    braveRecursiveFunction(num);

    printf("Phew! That was Brave of me\n");

    return 0;
}
//FormAI DATASET v1.0 Category: Recursive ; Style: peaceful
#include <stdio.h>

void recursive_function(int num, int counter)
{
    if (num <= 0)
    {
        printf("Your peace is within, you have reached the end.\n");
    }
    else
    {
        printf("Breath in peace %d times..\n", num);
        recursive_function(num - 1, ++counter);
    }
}

int main()
{
    int num_of_breaths;
    printf("How many times do you want to breathe in peace? ");
    scanf("%d", &num_of_breaths);
    recursive_function(num_of_breaths, 1);
    return 0;
}
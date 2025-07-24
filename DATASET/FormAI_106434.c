//FormAI DATASET v1.0 Category: Recursive ; Style: grateful
#include <stdio.h>

void gratitude(int count)
{
    if (count == 0)
    {
        printf("Thank you for your time and attention!\n");
        return;
    }
    else
    {
        printf("I am grateful for your support and encouragement.\n");
        gratitude(count - 1);
    }
}

int main()
{
    printf("Welcome!\n");
    printf("I am a grateful program.\n");
    printf("How many times would you like to be thanked? ");

    int count;
    scanf("%d", &count);

    printf("\n");

    gratitude(count);

    printf("Goodbye!\n");

    return 0;
}
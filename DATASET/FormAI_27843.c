//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: enthusiastic
#include <stdio.h>

int main()
{
    printf("Welcome to the most exciting traffic light controller simulation!\n\n");

    int greenTime = 10;
    int yellowTime = 2;
    int redTime = 5;

    while (1)
    {

        printf("Green light is on!\n");
        for (int i = greenTime; i > 0; i--)
        {
            printf("%d seconds left before yellow light.\n", i);
        }

        printf("Yellow light is on!\n");
        for (int i = yellowTime; i > 0; i--)
        {
            printf("%d seconds left before red light.\n", i);
        }

        printf("Red light is on!\n");
        for (int i = redTime; i > 0; i--)
        {
            printf("%d seconds left before green light.\n", i);
        }

        printf("\n\n\n");

    }

    return 0;
}
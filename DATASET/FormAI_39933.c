//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

void red();
void green();
void yellow();

int main()
{
    int i, j;

    //initializing the default state of traffic signal
    int state = 0;

    //loop to mimic the running traffic signal
    for(i = 0; i < 8; i++)
    {
        //loop to mimic the blinking of yellow light
        for(j = 0; j < 4; j++)
        {
            switch(state)
            {
                case 0:
                    red();
                    state++;
                    break;

                case 1:
                    green();
                    state++;
                    break;

                case 2:
                    yellow();
                    state = 0;
                    break;

                default:
                    printf("Error! Invalid state.");
                    exit(0);
            }
        }

        printf("\n");
    }

    return 0;
}

void red()
{
    printf("  _______     \n");
    printf(" /       \\    \n");
    printf("/         \\   \n");
    printf("|   RED   |   \n");
    printf("\\         /   \n");
    printf(" \\_______/    \n");
}

void green()
{
    printf("  _______     \n");
    printf(" /       \\    \n");
    printf("/         \\   \n");
    printf("|  GREEN  |   \n");
    printf("\\         /   \n");
    printf(" \\_______/    \n");
}

void yellow()
{
    printf("  _______     \n");
    printf(" /       \\    \n");
    printf("/         \\   \n");
    printf("|  YELLOW |   \n");
    printf("\\         /   \n");
    printf(" \\_______/    \n");
}
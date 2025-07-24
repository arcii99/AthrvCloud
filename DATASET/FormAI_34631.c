//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void red_light();
void green_light();
void yellow_light();

int main()
{
    printf("Press any key to start the traffic light!\n");
    getchar();
    red_light();
    return 0;
}

void red_light()
{
    printf("\nRed light is on.\n");
    sleep(5);
    yellow_light();
}

void yellow_light()
{
    printf("\nYellow light is on.\n");
    sleep(2);
    green_light();
}

void green_light()
{
    printf("\nGreen light is on.\n");
    sleep(4);
    printf("\nPress 1 to repeat the process, press 0 to exit: ");
    int choice;
    scanf("%d", &choice);
    if(choice == 1)
    {
        red_light();
    }
    else
    {
        exit(0);
    }
}
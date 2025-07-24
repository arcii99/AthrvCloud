//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

enum light { GREEN, YELLOW, RED } current_light = RED;

void print_light()
{
    switch(current_light)
    {
        case GREEN:
            printf("Green light is on.\n");
            break;
        case YELLOW:
            printf("Yellow light is on.\n");
            break;
        case RED:
            printf("Red light is on.\n");
            break;
        default:
            break;
    }
}

void change_light()
{
    switch(current_light)
    {
        case GREEN:
            current_light = YELLOW;
            break;
        case YELLOW:
            if(rand() % 2 == 0)
            {
                current_light = GREEN;
            }
            else
            {
                current_light = RED;
            }
            break;
        case RED:
            current_light = GREEN;
            break;
        default:
            break;
    }
    print_light();
}

int main()
{
    srand(time(NULL)); // Seed the random number generator with the current time
    
    while(1)
    {
        change_light();
        sleep((rand() % 3) + 1); // Wait a random number of seconds between 1 and 3
    }
    
    return 0;
}
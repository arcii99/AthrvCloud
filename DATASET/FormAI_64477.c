//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define GREEN 1
#define YELLOW 2
#define RED 3

int main()
{
    int current_state = GREEN;
    bool is_running = true;

    while (is_running)
    {
        switch (current_state)
        {
            case GREEN:
                printf("Green Light\n");
                sleep(5);
                current_state = YELLOW;
                break;
            case YELLOW:
                printf("Yellow Light\n");
                sleep(2);
                current_state = RED;
                break;
            case RED:
                printf("Red Light\n");
                sleep(5);
                current_state = GREEN;
                break;
            default:
                printf("Error: Invalid state\n");
                is_running = false;
                break;
        }
    }

    return 0;
}
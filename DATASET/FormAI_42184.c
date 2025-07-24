//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int t = rand() % 3;
    char state[3][10] = {"GREEN", "YELLOW", "RED"};
    printf("The current traffic light is %s.\n", state[t]);
    switch(t)
    {
        case 0:
            printf("Great! You can go ahead.\n");
            printf("But remember, don't text and drive!\n");
            break;
        case 1:
            printf("Uh oh, the light is yellow.\n");
            printf("Better slow down and prepare to stop.\n");
            break;
        case 2:
            printf("Red light! Stop now!\n");
            printf("But don't worry, just sit back and enjoy your favorite podcast.\n");
            break;
        default:
            printf("Invalid state! Please call the technician.\n");
            break;
    }
    return 0;
}
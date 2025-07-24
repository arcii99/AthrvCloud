//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

typedef enum { RED, YELLOW, GREEN } State;

int main(int argc, char *argv[])
{
    int i = 0;
    State current_state = RED;
    srand(time(NULL));

    while (i < 10) // loop for 10 iterations
    {
        printf("State: ");
        switch (current_state) // print current state
        {
            case RED:
                printf("RED\n");
                sleep(2); // pause for 2 seconds
                current_state = GREEN;
                break;
            case YELLOW:
                printf("YELLOW\n");
                sleep(1); // pause for 1 second
                current_state = RED;
                break;
            case GREEN:
                printf("GREEN\n");
                sleep(3); // pause for 3 seconds
                if (rand() % 2 == 0) // randomly shift to yellow or stay green
                {
                    current_state = YELLOW;
                }
                break;
        }
        i++;
    }

    return 0;
}
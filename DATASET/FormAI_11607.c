//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: real-life
#include<stdio.h>
#include<unistd.h>
#include<signal.h>

#define GREEN 0
#define YELLOW 1
#define RED 2

int current_light = GREEN; // starting point

void handle_signal(int);

int main()
{
    signal(SIGALRM, handle_signal); // setting the SIGALRM signal handler
    while(1)
    {
        switch(current_light)
        {
            case GREEN:
                printf("Green Light is ON\n");
                sleep(10); // Green light ON for 10 seconds
                current_light = YELLOW; // Switching to YELLOW
                break;
            case YELLOW:
                printf("Yellow Light is ON\n");
                sleep(5); // Yellow Light ON for 5 seconds
                current_light = RED; // Switching to RED
                break;
            case RED:
                printf("Red Light is ON\n");
                sleep(15); // Red Light ON for 15 seconds
                current_light = GREEN; // Switching to GREEN
                break;
        }
        raise(SIGALRM); // Timer Interrupt - After Delay
    }
    return 0;
}

void handle_signal(int signum)
{
    // Do Nothing - Timer Interrupt Signal Handler
}
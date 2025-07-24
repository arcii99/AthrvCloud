//FormAI DATASET v1.0 Category: Smart home light control ; Style: asynchronous
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

volatile int led_state = 0;

void interrupt_handler(int sig)
{
    if (sig == SIGINT)
        led_state = !led_state;
}

int main()
{
    printf("Smart Home Light Control Program\n");
    printf("--------------------------------\n");

    // register signal handler
    signal(SIGINT, interrupt_handler);

    // main loop to listen for interrupts
    while (1)
    {
        if (led_state)
        {
            // turn on smart light
            printf("Smart light is on.\n");
            // simulate a delay of 1 second
            sleep(1);
        }
        else
        {
            // turn off smart light
            printf("Smart light is off.\n");
            // simulate a delay of 1 second
            sleep(1);
        }
    }

    return 0;
}
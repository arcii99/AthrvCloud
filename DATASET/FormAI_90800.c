//FormAI DATASET v1.0 Category: Smart home automation ; Style: Ken Thompson
#include<stdio.h>
#include<time.h>

/* Smart home automation example program */
int main(void)
{
    int temp_sensor; // Temperature sensor reading
    int light_sensor; // Light sensor reading
    int window_status = 0; // 0 means closed, 1 means open
    int door_status = 0; // 0 means closed, 1 means open
    time_t t;
    srand((unsigned) time(&t)); // Seed the random number generator

    printf("Smart Home Automation System\n");
    printf("-----------------------------\n");

    while(1) // Infinite loop
    {
        // Read sensor values
        temp_sensor = rand() % 100; // Random temperature between 0 and 99
        light_sensor = rand() % 1024; // Random light level between 0 and 1023

        // Check if it's too hot
        if(temp_sensor > 80)
        {
            printf("Temperature is too high! Turning on the air conditioner.\n");
        }

        // Check if it's too dark
        if(light_sensor < 100)
        {
            printf("It's too dark! Turning on the lights.\n");
        }

        // Check if someone broke in
        if(door_status == 0 && (rand() % 2) == 1)
        {
            door_status = 1; // Door is now open
            printf("ALERT: Someone has opened the front door!\n");
        }

        // Check if a window is open
        if(window_status == 0 && (rand() % 10) == 1)
        {
            window_status = 1; // Window is now open
            printf("ALERT: A window has been opened!\n");
        }

        // Check if someone closed the door
        if(door_status == 1 && (rand() % 2) == 1)
        {
            door_status = 0; // Door is now closed
            printf("The front door has been closed.\n");
        }

        // Check if a window has been closed
        if(window_status == 1 && (rand() % 10) == 1)
        {
            window_status = 0; // Window is now closed
            printf("A window has been closed.\n");
        }

        // Wait for 5 seconds
        sleep(5);
    }

    return 0;
}
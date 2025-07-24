//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: medieval
// Medieval Intrusion Detection System

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    // Initializing variables
    int intruder_detected = 0;
    int room_number = 0;
    int alarm_on = 0;

    // Setting up random seed
    srand(time(NULL));

    // Looping through all rooms in the castle
    for (int i = 1; i <= 50; i++)
    {
        // Generating a random number to determine if the room has an intruder
        int random_number = rand() % 10 + 1;

        // If a 1 is generated, there is an intruder
        if (random_number == 1)
        {
            intruder_detected = 1;
            room_number = i;
            break; // No need to keep checking rooms after an intruder is found
        }
    }

    // If an intruder is detected, sound the alarm
    if (intruder_detected)
    {
        printf("\nIntruder detected in room %d!\n", room_number);
        alarm_on = 1;
    }
    
    // If the alarm is on, notify the guards
    if (alarm_on)
    {
        printf("Guards, to arms! The castle is under attack!\n");
    }
    else
    {
        printf("The castle is safe... for now.\n");
    }

    return 0;
}
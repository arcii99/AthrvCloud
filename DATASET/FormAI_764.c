//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the Intruder Detection System\n");

    //Declare variables
    int motion_detected = 0;
    int user_input = 0;
    int intruder_detected = 0;

    srand(time(0)); //Seed the random number generator

    //Run the system
    while(1)
    {
        //Check for motion
        motion_detected = rand() % 2; // Generate a random number (0 or 1)

        if(motion_detected == 1)
        {
            printf("Motion detected!!!\n");

            //Check if the user wants to disable the system
            printf("Enter 1 to disable the system. Enter any other number to continue: ");
            scanf("%d", &user_input);

            if(user_input == 1)
            {
                printf("System disabled.\n");
                break;
            }
            else
            {
                printf("System still active.\n");
                //Check for motion again after 10 seconds
                sleep(10); // Wait for 10 seconds
                motion_detected = rand() % 2;

                if(motion_detected == 1)
                {
                    printf("Intruder detected!!!\n");
                    intruder_detected = 1;
                }
                else
                {
                    printf("No motion detected.\n");
                }
            }
        }

        if(intruder_detected == 1)
        {
            printf("ALERT!!! Intruder detected. Calling authorities...\n");
            break;
        }
    }

    return 0;
}
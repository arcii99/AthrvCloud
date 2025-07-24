//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: artistic
// C Traffic Light Controller
// Created by an artistic brain!
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function Prototypes
void RedLight(int* seconds);
void YellowLight(int* seconds);
void GreenLight(int* seconds);

int main()
{
    // Declarations
    int redLightTime = 10;
    int yellowLightTime = 3;
    int greenLightTime = 15;
    int totalSeconds = redLightTime + yellowLightTime + greenLightTime;

    printf("==============================\n");
    printf("|Traffic Light Controller App|\n");
    printf("==============================\n");

    // Run until user quits
    while (1)
    {
        // Declaration
        int timeElapsed = 0;

        // Loop through all the lights
        while (timeElapsed < totalSeconds)
        {
            if (timeElapsed < redLightTime)
            {
                RedLight(&redLightTime);
            }
            else if (timeElapsed < (redLightTime + yellowLightTime))
            {
                YellowLight(&yellowLightTime);
            }
            else
            {
                GreenLight(&greenLightTime);
            }

            // Add a random delay of 1-2 seconds
            int delay = (rand() % 2) + 1;
            timeElapsed += (delay + 1);
            printf("\n");

        } // end while
        
        // Confirm if user wants to repeat the cycle
        printf("Do you want to repeat the cycle (Y/N)? ");
        char choice = getchar();
        
        if (choice == 'n' || choice == 'N')
        {
            break; // Exit the loop
        }
        
    } // end while

    return 0;
} // end main

// Function Definitions
void RedLight(int* seconds)
{
    *seconds -= 1;
    printf("       _____\n");
    printf("    __|__   |\n");
    printf("   |     |__|\n");
    printf("   |\n");
    printf("   |\n");
    printf("   |\n");
    printf("===\n");
    printf("RED: %d seconds remaining\n", *seconds);    
} // end RedLight

void YellowLight(int* seconds)
{
    *seconds -= 1;
    printf("       _____\n");
    printf("    __|__   |\n");
    printf("   |     |__|\n");
    printf("   |       o\n");
    printf("   |\n");
    printf("   |\n");
    printf("===\n");
    printf("YELLOW: %d seconds remaining\n", *seconds);    
} // end YellowLight

void GreenLight(int* seconds)
{
    *seconds -= 1;
    printf("       _____\n");
    printf("    __|__   |\n");
    printf("   |     |__|\n");
    printf("   |         \n");
    printf("   |     o  \n");
    printf("   |         \n");
    printf("===\n");
    printf("GREEN: %d seconds remaining\n", *seconds);    
} // end GreenLight
//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to simulate time travel
void timeTravelSimulator()
{
    // Initializing random number generator
    srand(time(0));
    
    // Creating variables to store current year and time of day
    int currentYear = 1445;
    int timeOfDay = 0;
    
    // Setting up loop to simulate time travel
    while(1)
    {
        // Generating random number to simulate time travel
        int randomNum = rand() % 101;
        
        // Checking if time travel is possible
        if(randomNum >= 25)
        {
            // Generating random number to determine amount of time travel
            int yearsTraveled = rand() % 51;
            
            // Checking if time travel is into the future or past
            int direction = rand() % 2;
            
            // Updating current year based on direction of time travel
            if(direction == 0)
            {
                currentYear -= yearsTraveled;
                printf("You have traveled %d years into the past.\n", yearsTraveled);
            }
            else
            {
                currentYear += yearsTraveled;
                printf("You have traveled %d years into the future.\n", yearsTraveled);
            }
            
            // Updating time of day
            if(timeOfDay == 0)
            {
                timeOfDay = 1;
                printf("It is now dawn.\n\n");
            }
            else if(timeOfDay == 1)
            {
                timeOfDay = 2;
                printf("It is now midday.\n\n");
            }
            else if(timeOfDay == 2)
            {
                timeOfDay = 3;
                printf("It is now dusk.\n\n");
            }
            else if(timeOfDay == 3)
            {
                timeOfDay = 0;
                printf("It is now midnight.\n\n");
            }
        }
        else
        {
            printf("Time travel failed.\n\n");
        }
        
        // Checking if time travel takes place in current year, if so program exits
        if(currentYear == 1445)
        {
            printf("You have returned to the present day.\n");
            break;
        }
    }
}

// Main function
int main()
{
    // Running time travel simulator function
    timeTravelSimulator();
    
    // EXIT_SUCCESS indicates normal termination
    return EXIT_SUCCESS;
}
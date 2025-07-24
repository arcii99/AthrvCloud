//FormAI DATASET v1.0 Category: Robot movement control ; Style: safe
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define MOVEMENT_TIME_LIMIT 10   // limit for robot movement time duration
#define SENSOR_THRESHOLD 500     // threshold value for obstacle detection by sensor
#define FORWARD 'F'              // character code for moving forward
#define RIGHT 'R'                // character code for turning right
#define LEFT 'L'                 // character code for turning left

// function to generate random movement duration
int generateMovementDuration()
{
    srand(time(NULL));          // seed the random number generator
    
    int duration = rand() % MOVEMENT_TIME_LIMIT + 1;   // generate a random number between 1 to MOVEMENT_TIME_LIMIT
    
    return duration;
}

// function to check for obstacle using sensor
bool checkForObstacle()
{
    srand(time(NULL));          // seed the random number generator
    
    int sensorReading = rand() % 1000;    // generate a random sensor reading between 0 to 999
    
    if(sensorReading > SENSOR_THRESHOLD)
    {
        return true;    // obstacle detected
    }
    else
    {
        return false;   // no obstacle detected
    }
}

// main function to control robot movement
int main()
{
    int movementDuration;   // variable to store movement duration
    char direction;         // variable to store current movement direction
    
    while(true)
    {
        // generate random duration for next movement
        movementDuration = generateMovementDuration();
        
        // check if obstacle present in front
        if(checkForObstacle())
        {
            // turn right 90 degrees if obstacle detected and move in new direction
            printf("Obstacle detected! Turning right and moving forward for %d seconds.\n", movementDuration);
            direction = RIGHT;
        }
        else
        {
            // move forward for generated duration
            printf("Moving forward for %d seconds.\n", movementDuration);
            direction = FORWARD;
        }
        
        // sleep for movement duration
        sleep(movementDuration);
        
        // generate random duration for next rotation
        movementDuration = generateMovementDuration();
        
        // rotate left or right randomly
        srand(time(NULL));
        int rotate = rand() % 2;    // generate 0 or 1 randomly
        
        if(rotate == 0)
        {
            printf("Rotating left for %d seconds.\n", movementDuration);
            direction = LEFT;
        }
        else
        {
            printf("Rotating right for %d seconds.\n", movementDuration);
            direction = RIGHT;
        }
        
        // sleep for rotation duration
        sleep(movementDuration);
    }
    
    return 0;
}
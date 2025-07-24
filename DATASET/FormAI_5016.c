//FormAI DATASET v1.0 Category: Robot movement control ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

// define variables
int robot_position_x = 0;
int robot_position_y = 0;
int robot_direction = 0;
int obstacle_detected = 0;

int main()
{
    // set up sensors
    int front_sensor = 1;
    int back_sensor = 0;
    int left_sensor = 0;
    int right_sensor = 0;

    // set up motors
    int left_motor = 1;
    int right_motor = 1;
    
    // move robot forward until obstacle detected
    while(!obstacle_detected)
    {
        // read sensor values
        front_sensor = 1;
        back_sensor = 0;
        left_sensor = 0;
        right_sensor = 0;
        
        // check for obstacles
        if(front_sensor == 1)
        {
            // move forward
            robot_position_y++;
        }
        else
        {
            // change direction randomly
            robot_direction = rand() % 4;
        }
        
        // check for exit
        if(robot_position_x == 10 && robot_position_y == 10)
        {
            // exit found
            printf("Exit found!");
            break;
        }
        
        // update robot position based on direction
        if(robot_direction == 0)
        {
            // move up
            robot_position_y++;
        }
        else if(robot_direction == 1)
        {
            // move right
            robot_position_x++;
        }
        else if(robot_direction == 2)
        {
            // move down
            robot_position_y--;
        }
        else if(robot_direction == 3)
        {
            // move left
            robot_position_x--;
        }
    }
    
    // stop robot motors
    left_motor = 0;
    right_motor = 0;

    return 0;
}
//FormAI DATASET v1.0 Category: Robot movement control ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number
int random_generator(int min_num, int max_num) 
{
    int result = 0, low_num = 0, hi_num = 0;
 
    if (min_num < max_num) 
    {
        low_num = min_num;
        hi_num = max_num + 1; // include max_num in output
    } 
    else 
    {
        low_num = max_num + 1; // include max_num in output
        hi_num = min_num;
    }
 
    result = (rand() % (hi_num - low_num)) + low_num;
    return result;
}

// Robot Control Function
void robot_movement_control(int robot_x, int robot_y, int target_x, int target_y)
{
    // Determine the direction to move
    int dir_x = 0, dir_y = 0;
    if (robot_x < target_x)
        dir_x = 1;
    else if (robot_x > target_x)
        dir_x = -1;
    if (robot_y < target_y)
        dir_y = 1;
    else if (robot_y > target_y)
        dir_y = -1;
    
    // Move the robot in the determined direction
    if (dir_x == 0 && dir_y == 0)
        printf("Robot is already at the target.\n");
    else if (dir_x == 0)
    {
        while(robot_y != target_y)
        {
            printf("Moving robot from (%d, %d) to (%d, %d)\n", robot_x, robot_y, robot_x, robot_y+dir_y);
            robot_y += dir_y;
        }
    }
    else if (dir_y == 0)
    {
        while(robot_x != target_x)
        {
            printf("Moving robot from (%d, %d) to (%d, %d)\n", robot_x, robot_y, robot_x+dir_x, robot_y);
            robot_x += dir_x;
        }
    }
    else
    {
        while(robot_x != target_x && robot_y != target_y)
        {
            int choice = random_generator(0, 1);
            if (choice == 0)
            {
                printf("Moving robot from (%d, %d) to (%d, %d)\n", robot_x, robot_y, robot_x+dir_x, robot_y);
                robot_x += dir_x;
            }
            else
            {
                printf("Moving robot from (%d, %d) to (%d, %d)\n", robot_x, robot_y, robot_x, robot_y+dir_y);
                robot_y += dir_y;
            }
        }
        while(robot_x != target_x)
        {
            printf("Moving robot from (%d, %d) to (%d, %d)\n", robot_x, robot_y, robot_x+dir_x, robot_y);
            robot_x += dir_x;
        }
        while(robot_y != target_y)
        {
            printf("Moving robot from (%d, %d) to (%d, %d)\n", robot_x, robot_y, robot_x, robot_y+dir_y);
            robot_y += dir_y;
        }
    }
    printf("Robot reached the target at (%d, %d).\n", target_x, target_y);
}

// Main function
int main()
{
    // Initializing random number generator
    srand(time(NULL));
    
    // Setting up the robot and target positions
    int robot_x = 1, robot_y = 1;
    int target_x = 5, target_y = 5;
    
    // Controlling the robot movement
    robot_movement_control(robot_x, robot_y, target_x, target_y);
    
    return 0;
}
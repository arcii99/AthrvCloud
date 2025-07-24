//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int max_speed = 50;
    int min_speed = 10;
    int max_steering_angle = 45;
    int min_steering_angle = -45;
    int current_speed = 20;
    int current_steering_angle = 0;
    int up_key = 0;
    int down_key = 0;
    int left_key = 0;
    int right_key = 0;
    
    srand(time(NULL));  //initialize random seed
    
    printf("Welcome to the Remote Control Vehicle Simulation!\n");
    printf("The vehicle can move at speeds between %d and %d mph.\n", min_speed, max_speed);
    printf("The steering angle can be between %d and %d degrees.\n", min_steering_angle, max_steering_angle);
    
    while(1)
    {
        //check for user input and update vehicle state
        if(up_key)
        {
            if(current_speed < max_speed)
            {
                current_speed += 5;
            }
            up_key = 0;  //clear the flag
        }
        if(down_key)
        {
            if(current_speed > min_speed)
            {
                current_speed -= 5;
            }
            down_key = 0;  //clear the flag
        }
        if(left_key)
        {
            if(current_steering_angle > min_steering_angle)
            {
                current_steering_angle -= 5;
            }
            left_key = 0;  //clear the flag
        }
        if(right_key)
        {
            if(current_steering_angle < max_steering_angle)
            {
                current_steering_angle += 5;
            }
            right_key = 0;  //clear the flag
        }
        
        //simulate vehicle movement
        printf("Speed: %d mph\n", current_speed);
        printf("Steering angle: %d degrees\n", current_steering_angle);
        //simulate random changes in speed and steering angle
        if(rand() % 10 == 0)
        {
            int speed_variation = rand() % 11 - 5;  //generate a random value between -5 and 5
            current_speed += speed_variation;
            if(current_speed < min_speed)
            {
                current_speed = min_speed;
            }
            else if(current_speed > max_speed)
            {
                current_speed = max_speed;
            }
        }
        if(rand() % 8 == 0)
        {
            int steering_variation = rand() % 11 - 5;  //generate a random value between -5 and 5
            current_steering_angle += steering_variation;
            if(current_steering_angle < min_steering_angle)
            {
                current_steering_angle = min_steering_angle;
            }
            else if(current_steering_angle > max_steering_angle)
            {
                current_steering_angle = max_steering_angle;
            }
        }
        
        printf("\n");  //add some space between printouts
        usleep(500000);  //wait for half a second
    }
    
    return 0;
}
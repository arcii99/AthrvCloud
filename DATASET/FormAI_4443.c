//FormAI DATASET v1.0 Category: Smart home light control ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int light_state = 0;  // Initial state of light (off)
    int motion_state = 0;  // Initial state of motion sensor (no motion detected)
    int brightness = 0;  // Initial brightness level (0 - 100)
    
    // Loop to simulate continuous monitoring of the sensors
    while (1) 
    {
        // Check if motion is detected
        if (motion_sensor_detected())
        {
            motion_state = 1;
        }
        else
        {
            motion_state = 0;
        }
        
        if (motion_state == 1 && light_state == 0)  // Turn on the light if there is motion and light is off
        {
            turn_on_light();
            light_state = 1;
        }
        else if (motion_state == 0 && light_state == 1)  // Turn off the light if there is no motion and light is on
        {
            turn_off_light();
            light_state = 0;
        }

        // If light is on, adjust brightness level
        if (light_state == 1)
        {
            brightness = get_brightness_level();
            if (brightness < 50)
            {
                decrease_brightness();
            }
            else if (brightness > 70)
            {
                increase_brightness();
            }
        }
    }

    return 0;
}

// Function to simulate motion sensor detection (50% chance of detecting motion)
int motion_sensor_detected() 
{
    return (rand() % 2); 
}

// Function to turn on the light
void turn_on_light()
{
    printf("Turning on light...\n");
}

// Function to turn off the light
void turn_off_light()
{
    printf("Turning off light...\n");
}

// Function to get current brightness level
int get_brightness_level()
{
    return 60;   // return some random value between 0 and 100
}

// Function to increase brightness level
void increase_brightness()
{
    printf("Increasing brightness...\n");
}

// Function to decrease brightness level
void decrease_brightness()
{
    printf("Decreasing brightness...\n");
}
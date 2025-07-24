//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h> // for sleep function
 
#define GREEN 0
#define YELLOW 1
#define RED 2
 
int main()
{
    int current_light = GREEN; // start with green light
    bool is_button_pressed = false;
 
    while (true) // loop forever
    {
        if(current_light == GREEN)
        {
            printf("Green light on\n");
            sleep(5); // stay green for 5 seconds
            current_light = YELLOW; // turn on yellow light
        }
        else if(current_light == YELLOW)
        {
            printf("Yellow light on\n");
            sleep(3); // stay yellow for 3 seconds
 
            // check if button is pressed
            if(is_button_pressed)
            {
                current_light = GREEN; // turn on green light
                is_button_pressed = false; // reset button flag
            }
            else
            {
                current_light = RED; // turn on red light
            }
        }
        else // current light is RED
        {
            printf("Red light on\n");
            sleep(5); // stay red for 5 seconds
            current_light = GREEN; // turn on green light
        }
 
        // simulate button press (50% chance of press)
        if(rand() % 2 == 0)
        {
            is_button_pressed = true;
            printf("Button pressed\n");
        }
    }
 
    return 0;
}
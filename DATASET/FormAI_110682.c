//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int distance = 0;
    int speed = 0;
    int battery = 100;
    int direction = 0;

    printf("Welcome to the Remote Control Vehicle simulation program.\n");
    printf("Use the arrow keys to control the vehicle.\n");
    printf("Press 'q' to quit.\n\n");

    while(1) {
        // Clear the screen
        system("clear");

        // Print the status of the vehicle
        printf("Distance traveled: %d meters\n", distance);
        printf("Current speed: %d km/h\n", speed);
        printf("Battery remaining: %d%%\n", battery);
        printf("Direction: %s\n", (direction == 0 ? "north" : 
                                        (direction == 90 ? "east" : 
                                            (direction == 180 ? "south" : 
                                                (direction == 270 ? "west" : "unknown")))));

        // Get user input
        char key = getchar();

        // Quit if user presses 'q'
        if(key == 'q') {
            printf("\nThank you for using the Remote Control Vehicle simulation program.\n");
            break;
        }

        // Change direction if user presses arrow keys
        if(key == '\033') {
            getchar(); // Skip '['

            switch(getchar()) {
                case 'A': // Up arrow key
                    direction = 0;
                    break;
                case 'B': // Down arrow key
                    direction = 180;
                    break;
                case 'C': // Right arrow key
                    direction = 90;
                    break;
                case 'D': // Left arrow key
                    direction = 270;
                    break;
            }
        }

        // Increase or decrease speed if user presses '+' or '-'
        if(key == '+')
            speed++;
        else if(key == '-')
            speed--;

        // Limit speed to 0 km/h to 200 km/h
        if(speed < 0)
            speed = 0;
        else if(speed > 200)
            speed = 200;

        // Update the distance traveled based on the current speed
        distance += (speed * 1000) / 3600;

        // Decrease battery life
        battery -= (speed * 10) / 3600;

        // Limit battery life to 0% to 100%
        if(battery < 0)
            battery = 0;
        else if(battery > 100)
            battery = 100;
    }

    return 0;
}
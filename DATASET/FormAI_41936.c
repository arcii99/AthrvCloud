//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: cheerful
// This cheerful program allows a user to control their drone using a remote control
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int drone_x_pos = 0;  //initialize drone position variables
    int drone_y_pos = 0;
    int drone_z_pos = 0;
    printf("Welcome to the Drone Control Program!\n");
    printf("Press the arrow keys on your remote control device to move the drone\n");
    printf("Up arrow: Move the drone up\n");
    printf("Down arrow: Move the drone down\n");
    printf("Left arrow: Move the drone left\n");
    printf("Right arrow: Move the drone right\n");
    printf("Let's get ready to fly!!\n");

    while (1) // loop to keep checking for user input
    {

        char user_input = getchar(); // read in user's input
        if (user_input == '\n')
        {
            // ignore newline characters
            continue;
        }

        // move the drone based on user input
        switch (user_input)
        {
            case 'A': // up arrow key
                drone_z_pos++;
                printf("Drone moved up. Current height: %d meters\n", drone_z_pos);
                break;
            case 'B': // down arrow key
                drone_z_pos--;
                printf("Drone moved down. Current height: %d meters\n", drone_z_pos);
                break;
            case 'C': // right arrow key
                drone_y_pos++;
                printf("Drone moved right. Current position: (%d,%d,%d)\n", drone_x_pos, drone_y_pos, drone_z_pos);
                break;
            case 'D': // left arrow key
                drone_y_pos--;
                printf("Drone moved left. Current position: (%d,%d,%d)\n", drone_x_pos, drone_y_pos, drone_z_pos);
                break;
            default:
                printf("Invalid input. Please use the arrow keys on your remote control device to move the drone.\n");
                break;
        }

        // generate cheerful messages every few moves
        if (rand() % 3 == 0) // 1/3 chance of generating a message
        {
            switch (rand() % 3)
            {
                case 0:
                    printf("Woohoo! We're flying high!\n");
                    break;
                case 1:
                    printf("Nice work! Keep it up!\n");
                    break;
                case 2:
                    printf("This is so much fun!!\n");
                    break;
            }
        }

        // check if drone crashes
        if (drone_z_pos < 0) // drone crashed
        {
            printf("Oh no! The drone crashed! Please start over.\n");
            break; // exit loop
        }
    }

    printf("Thanks for using the Drone Control Program.\n"); 

    return 0;
}
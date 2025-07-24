//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(){
    // initialize variables
    int altitude = 0;
    int heading = 0;
    int speed = 0;
    char choice;

    // welcome message
    printf("Welcome to C Drone Remote Control!\n");

    // main loop
    while(1){
        // display menu
        printf("\nChoose an option:\n");
        printf("A. Increase altitude\n");
        printf("B. Decrease altitude\n");
        printf("C. Rotate left\n");
        printf("D. Rotate right\n");
        printf("E. Increase speed\n");
        printf("F. Decrease speed\n");
        printf("Q. Quit program\n");

        // get user choice
        choice = getchar();

        // clear input buffer
        fflush(stdin);

        // process user choice
        switch(choice){
            case 'A':
            case 'a':
                altitude += 10;
                printf("Increased altitude to %d meters.\n", altitude);
                break;

            case 'B':
            case 'b':
                altitude -= 10;
                if(altitude < 0){
                    altitude = 0;
                }
                printf("Decreased altitude to %d meters.\n", altitude);
                break;

            case 'C':
            case 'c':
                heading -= 10;
                if(heading < 0){
                    heading = 360;
                }
                printf("Rotated left to heading %d degrees.\n", heading);
                break;

            case 'D':
            case 'd':
                heading += 10;
                if(heading > 360){
                    heading = 0;
                }
                printf("Rotated right to heading %d degrees.\n", heading);
                break;

            case 'E':
            case 'e':
                speed += 10;
                printf("Increased speed to %d km/h.\n", speed);
                break;

            case 'F':
            case 'f':
                speed -= 10;
                if(speed < 0){
                    speed = 0;
                }
                printf("Decreased speed to %d km/h.\n", speed);
                break;

            case 'Q':
            case 'q':
                // end program
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Choose a valid option.\n");
                break;
        }

    }

    return 0;
}
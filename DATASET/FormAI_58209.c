//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

int main()
{
    char command;
    bool isConnected = false;
    int altitude = 0;

    printf("Welcome to C Drone Remote Control System! Press 1 to connect, or 2 to exit.\n");

    do
    {
        command = getchar();

        switch (toupper(command))
        {
            case '1':
                printf("Connection successful!\n");
                isConnected = true;
                break;

            case '2':
                printf("Exiting...\n");
                exit(0);
                break;

            default:
                break;
        }

    } while (!isConnected);

    printf("Connected! Drone is currently at an altitude of %d meters.\n", altitude);

    do
    {
        printf("Enter a command (U for up, D for down, F for forward, B for backward, L for left, R for right, Q to quit): ");

        command = getchar();

        switch (toupper(command))
        {
            case 'U':
                altitude += 10;
                printf("Drone ascended 10 meters. Current altitude: %d meters.\n", altitude);
                break;

            case 'D':
                altitude -= 10;
                printf("Drone descended 10 meters. Current altitude: %d meters.\n", altitude);
                break;

            case 'F':
                printf("Drone moved forward.\n");
                break;

            case 'B':
                printf("Drone moved backward.\n");
                break;

            case 'L':
                printf("Drone moved left.\n");
                break;

            case 'R':
                printf("Drone moved right.\n");
                break;

            case 'Q':
                printf("Disconnecting...\n");
                isConnected = false;
                break;

            default:
                printf("Invalid command. Please enter a valid command!\n");
                break;
        }

        // Consume any leftover characters in the input buffer
        while(getchar() != '\n');

    } while (isConnected);
    
    printf("Disconnected! Drone's final altitude: %d meters.\n", altitude);

    return 0;
}
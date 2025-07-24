//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    printf("Welcome to the Remote Control Vehicle Simulation Program\n");

    int speed = 0;
    int x = 0;
    int y = 0;
    int facing = 0; // 0 = North, 1 = East, 2 = South, 3 = West

    while (1)
    {
        // Display current position and speed
        printf("Position: (%d, %d), Facing: ", x, y);
        switch (facing)
        {
            case 0: printf("North"); break;
            case 1: printf("East"); break;
            case 2: printf("South"); break;
            case 3: printf("West"); break;
        }
        printf(", Speed: %d\n", speed);

        // Read user input
        char c = getchar();
        if (c == '\n') continue;

        // Handle user input
        switch (c)
        {
            case 'w': y += speed; break; // Move forward
            case 's': y -= speed; break; // Move backward
            case 'a': x -= speed; break; // Move left
            case 'd': x += speed; break; // Move right
            case 'q': facing--; if (facing < 0) facing = 3; break; // Turn left
            case 'e': facing++; if (facing > 3) facing = 0; break; // Turn right
            case ' ': speed = (speed + 1) % 6; break; // Increase speed
            case 'x': speed = (speed + 5) % 6; break; // Decrease speed
            case 'c': speed = 0; break; // Stop moving
            case 'p': printf("Program ending...\n"); exit(0); // End program
        }

        // Clear input buffer
        while (getchar() != '\n');
        
        // Slow down simulation
        usleep(100000);
    }

    return 0;
}
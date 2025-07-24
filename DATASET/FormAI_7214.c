//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void warpDrive(int x_coord, int y_coord); // Function declaration

int main()
{
    int x_coord = 0;
    int y_coord = 0;
    int fuel = 10000;
    srand(time(0)); // Seed the random number generator
    
    printf("Welcome to Procedural Space Adventure!\n");
    printf("Your starting coordinates are x=%d, y=%d\n", x_coord, y_coord);
    
    while(fuel > 0)
    {
        int rand_num = rand() % 4; // Generate a random number from 0-3
        switch(rand_num)
        {
            case 0:
                x_coord += 50;
                printf("Warping to x=%d, y=%d...\n", x_coord, y_coord);
                warpDrive(x_coord, y_coord);
                break;
            case 1:
                x_coord -= 50;
                printf("Warping to x=%d, y=%d...\n", x_coord, y_coord);
                warpDrive(x_coord, y_coord);
                break;
            case 2:
                y_coord += 50;
                printf("Warping to x=%d, y=%d...\n", x_coord, y_coord);
                warpDrive(x_coord, y_coord);
                break;
            case 3:
                y_coord -= 50;
                printf("Warping to x=%d, y=%d...\n", x_coord, y_coord);
                warpDrive(x_coord, y_coord);
                break;
        }
        fuel -= 100;
        printf("Fuel remaining: %d\n", fuel);
    }
    
    printf("Your ship is out of fuel. Game over.\n");
    return 0;
}

void warpDrive(int x_coord, int y_coord)
{
    printf("You have successfully warped to x=%d, y=%d\n", x_coord, y_coord);
}
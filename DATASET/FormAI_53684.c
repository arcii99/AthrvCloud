//FormAI DATASET v1.0 Category: Fractal Generation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int x = 0, y = 0;
    srand(time(NULL)); // Seed the random number generator
   
    for(int i = 0; i < 100000; i++) // Number of points to generate
    {
        int r = rand() % 100; // Generate a random number between 0 and 99
        
        // Four transformation rules for the Barnsley fern algorithm
        if(r < 1)
        {
            int new_x = 0;
            int new_y = 0.16 * y;
            x = new_x;
            y = new_y;
        }
        else if(r < 86)
        {
            int new_x = 0.85 * x + 0.04 * y;
            int new_y = -0.04 * x + 0.85 * y + 1.6;
            x = new_x;
            y = new_y;
        }
        else if(r < 93)
        {
            int new_x = 0.20 * x - 0.26 * y;
            int new_y = 0.23 * x + 0.22 * y + 1.6;
            x = new_x;
            y = new_y;
        }
        else
        {
            int new_x = -0.15 * x + 0.28 * y;
            int new_y = 0.26 * x + 0.24 * y + 0.44;
            x = new_x;
            y = new_y;
        }
        
        // Print the point to the console
        printf("%d %d\n", x + 50, y + 50); // Offset by 50 to center the fern
    }
    
    return 0;
}
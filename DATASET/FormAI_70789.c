//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main()
{
    printf("Welcome to the C RAM usage monitor program in post-apocalyptic style!\n");

    // Seed the random number generator
    srand(time(NULL));

    while(1)
    {
        // Simulate RAM usage by generating a random amount of memory usage
        int ram_used = rand() % 100 + 1;
        printf("RAM usage: %d%%\n", ram_used);

        if(ram_used >= 90)
        {
            printf("WARNING: RAM usage is critical!\n");
            // Play a siren sound to alert the user
            system("afplay siren.mp3 &");
        }

        // Wait for 3 seconds before generating the next RAM usage value
        sleep(3);
    }

    return 0;
}
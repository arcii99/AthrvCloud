//FormAI DATASET v1.0 Category: System boot optimizer ; Style: beginner-friendly
#include <stdio.h>
#include <stdbool.h>

int main()
{
    printf("Welcome to C System Boot Optimizer!\n");

    bool optimizeBoot = true;
    int bootTime = 120; // in seconds

    printf("Initializing boot sequence...\n\n");

    while(optimizeBoot)
    {
        printf("Reducing boot time...\n");
        bootTime -= 5;

        if(bootTime <= 0)
        {
            printf("\nBoot sequence optimized!\n");
            optimizeBoot = false;
        }
        else
        {
            printf("Boot time remaining: %d seconds\n\n", bootTime);
        }
    }

    printf("Press any key to exit...");
    getchar();

    return 0;
}
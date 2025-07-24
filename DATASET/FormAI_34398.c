//FormAI DATASET v1.0 Category: System boot optimizer ; Style: portable
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int bootTime = 0;
    int totalPrograms = 0;
    int optimizedCount = 0;

    printf("Welcome to the C System Boot Optimizer!\n\n");

    // Get user input for boot time
    printf("How long does your system take to boot (in seconds)? ");
    scanf("%d", &bootTime);

    // Get user input for number of programs installed
    printf("\nHow many programs do you have installed? ");
    scanf("%d", &totalPrograms);

    printf("\nAnalyzing boot performance...\n\n");

    // Simulate boot process with random program load times
    srand(time(NULL));
    int i;
    for (i = 0; i < totalPrograms; i++) {
        int programLoadTime = rand() % (bootTime + 1);
        printf("Loading program %d... (%d seconds)\n", i+1, programLoadTime);
        if (programLoadTime < bootTime) {
            optimizedCount++;
        }
    }

    printf("\nBoot optimized %d out of %d programs!\n", optimizedCount, totalPrograms);

    return 0;
}
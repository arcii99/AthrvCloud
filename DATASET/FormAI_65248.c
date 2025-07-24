//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    int pushups = rand() % 100;
    int squats = rand() % 100;
    int situps = rand() % 100;
    
    printf("Welcome to the Fitness Tracker Program!\n\n");
    printf("Today's workout consists of:\n");
    printf("%d pushups\n", pushups);
    printf("%d squats\n", squats);
    printf("%d situps\n\n", situps);
    
    printf("Let's start with the pushups...\n");
    for (int i = 1; i <= pushups; i++)
    {
        printf("Pushup %d\n", i);
        // Your code for tracking pushups goes here
    }
    
    printf("\nGreat job on the pushups! Let's move on to squats...\n");
    for (int i = 1; i <= squats; i++)
    {
        printf("Squat %d\n", i);
        // Your code for tracking squats goes here
    }
    
    printf("\nAmazing work on the squats! Finally, let's do some situps...\n");
    for (int i = 1; i <= situps; i++)
    {
        printf("Situp %d\n", i);
        // Your code for tracking situps goes here
    }
    
    printf("\nCongratulations on completing today's workout!");
    return 0;
}
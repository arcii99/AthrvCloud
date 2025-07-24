//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // seed the random number generator
    
    int red_time = rand() % 10; // generate random time for red light
    int green_time = rand() % 10; // generate random time for green light
    int yellow_time = rand() % 5; // generate random time for yellow light
    
    printf("Welcome to the Happy Traffic Light Controller!\n\n");
    printf("Red light will be on for %d seconds...\n", red_time);
    sleep(red_time); // wait for red light time
    
    printf("\nGreen light is on! You can go now!\n\n");
    printf("Green light will be on for %d seconds...\n", green_time);
    sleep(green_time); // wait for green light time
    
    printf("\nYellow light is on. Get ready to stop!\n\n");
    printf("Yellow light will be on for %d seconds...\n", yellow_time);
    sleep(yellow_time); // wait for yellow light time
    
    printf("\nRed light is on. Stop now!\n");
    
    return 0;
}